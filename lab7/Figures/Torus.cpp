#include "stdafx.h"
#include "Torus.h"
#include "Ray.h"
#include "Intersection.h"
#include "Solver.h"
#include <numbers>

namespace
{
constexpr float EPSILON = 0.0001f;
}

Torus::Torus(float smallRadius, float bigRadius, CVector3d const& center, CMatrix4d const& transform)
	: CGeometryObjectWithInitialTransformImpl(transform)
	, m_smallRadius(smallRadius)
	, m_bigRadius(bigRadius)
{
	CMatrix4d initialTransform;
	initialTransform.Translate(center.x, center.y, center.z);

	SetInitialTransform(initialTransform);
}

bool Torus::Hit(CRay const& ray, CIntersection& intersection) const
{
	CRay invRay = Transform(ray, GetInverseTransform());
	const auto rayOrigin = invRay.GetStart();
	const auto rayDirection = invRay.GetDirection();

	// Torus formul: (x^2 + y^2 + z^2 + R^2 - r^2)^2 - 4R^2(x^2 + y^2) = 0
	// A*t^4 + B*t^3 + C*t^2 + D*t + E = 0
	const float firstCoef = std::powf(rayDirection.x, 2) + std::powf(rayDirection.y, 2) + std::powf(rayDirection.z, 2);
	const float secondCoef = std::powf(rayOrigin.x, 2) + std::powf(rayOrigin.y, 2) + std::powf(rayOrigin.z, 2) - std::powf(m_bigRadius, 2) - std::powf(m_smallRadius, 2);
	const float thirdCoef = rayOrigin.x * rayDirection.x + rayOrigin.y * rayDirection.y + rayOrigin.z * rayDirection.z;
	const float fourthCoef = 4.0 * std::powf(m_bigRadius, 2);

	const std::vector<float> coeffs = {
		secondCoef * secondCoef - fourthCoef * (std::powf(m_smallRadius, 2) - std::powf(rayOrigin.y, 2)),
		4.0f * thirdCoef * secondCoef + 2.0f * fourthCoef * static_cast<float>(rayOrigin.y) * static_cast<float>(rayDirection.y),
		2.0f * firstCoef * secondCoef + 4.0f * std::powf(thirdCoef, 2) + fourthCoef * std::powf(rayDirection.y, 2),
		4.0f * firstCoef * thirdCoef,
		std::powf(firstCoef, 2)
	};

	const auto solution = Solver::Solve4(coeffs);

	if (solution.empty())
	{
		return false;
	}

	auto min = FLT_MAX;
	for (auto number : solution)
	{
		if (number > EPSILON && number < min)
		{
			min = number;
		}
	}

	if (min == FLT_MAX)
	{
		return false;
	}

	auto hitPoint0 = ray.GetPointAtTime(min);
	auto hitPoint0InObjectSpace = invRay.GetPointAtTime(min);
	auto hitNormal0InObjectSpace = hitPoint0InObjectSpace;
	auto hitNormal0 = GetNormalMatrix() * hitNormal0InObjectSpace;

	CHitInfo hit0(
		min, *this,
		hitPoint0, hitPoint0InObjectSpace,
		hitNormal0, hitNormal0InObjectSpace);

	intersection.AddHit(hit0);
	return true;
}
