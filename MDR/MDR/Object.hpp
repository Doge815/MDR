#pragma once

#include "Common.hpp"
#include <math.h>

class Object
{
public:
	virtual bool Intersect(const Vec3d& position, const Vec3d& direction, float& distance) = 0;
};

class Sphere : public Object
{
private:
	Vec3d center;
	float radius;
public:
	bool Intersect(const Vec3d& position, const Vec3d& direction, float& distance) override;
};

bool Sphere::Intersect(const Vec3d& position, const Vec3d& direction, float& distance)
{
    Vec3d L = center - position;
    double tca = L * direction;
    double d2 = L * L - tca * tca;
    if (d2 > radius * radius) return false;
    double thc = sqrtf(radius * radius - d2);
    distance = tca - thc;
    double t1 = tca + thc;
    if (distance < 0) distance = t1;
    if (distance < 0) return false;
    return true;
}