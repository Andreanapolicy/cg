#include "stdafx.h"
#include "Torus.h"
#include "Ray.h"
#include "Intersection.h"

Torus::Torus(float smallRadius, float bigRadius, CVector3d const& center, CMatrix4d const& transform)
	: m_smallRadius(smallRadius)
	, m_bigRadius(bigRadius)
{
	assert(smallRadius < bigRadius);

	CMatrix4d initialTransform;
	initialTransform.Translate(center.x, center.y, center.z);
	//initialTransform.Scale(radius, radius, radius);

	SetInitialTransform(initialTransform);
}

bool Torus::Hit(CRay const& ray, CIntersection& intersection) const
{
	const auto rayOrigin = ray.GetStart();
	const auto rayDirection = ray.GetDirection();

	// Torus formul: (x^2 + y^2 + z^2 + R^2 - r^2)^2 - 4R^2(x^2 + y^2) = 0
	// A*t^4 + B*t^3 + C*t^2 + D*t + E = 0
	const float firstCoef = std::powf(rayDirection.x, 2) + std::powf(rayDirection.y, 2) + std::powf(rayDirection.z, 2);
	const float secondCoef = std::powf(rayOrigin.x, 2) + std::powf(rayOrigin.y, 2) + std::powf(rayOrigin.z, 2) - std::powf(m_bigRadius, 2) - std::powf(m_smallRadius, 2);
	const float thirdCoef = rayOrigin.x * rayDirection.x + rayOrigin.y * rayDirection.y + rayOrigin.x * rayDirection.z;
	const float fourthCoef = 4.0 * std::powf(m_bigRadius, 2);

	const std::vector<float> coeffs = {
		secondCoef * secondCoef - fourthCoef * (std::powf(m_smallRadius, 2) - std::powf(rayOrigin.y, 2)),
		4.0f * thirdCoef * secondCoef + 2.0f * fourthCoef + static_cast<float>(rayOrigin.y) * static_cast<float>(rayDirection.y),
		2.0f * firstCoef * secondCoef + 4.0f * std::powf(thirdCoef, 2) + fourthCoef * std::powf(rayDirection.y, 2),
		4.0f * firstCoef * thirdCoef,
		std::powf(firstCoef, 2)
	};

	const auto solution = Solver::solve4(coefs);

	CRay invRay = Transform(ray, GetInverseTransform());

	return false;
}
