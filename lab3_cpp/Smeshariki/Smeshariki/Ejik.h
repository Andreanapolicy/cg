#pragma once
#include "Smesharik.h"

class Ejik : public Smesharik
{
public:
	Ejik();
	void Draw(float x, float y) override;
	~Ejik() = default;
};
