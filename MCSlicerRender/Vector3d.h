#pragma once
#include <iostream>
#include <cmath>
#include "vertex.h"


class Vec3d
{
public:
	double i, j, k;
	Vec3d();
	Vec3d(double i, double j, double k);
	Vec3d(vertex v);

	void setVec(double i, double j, double k);
	double magnitude();
	Vec3d normalize();
	double dot(const Vec3d &v);
	Vec3d cross(const Vec3d& v);


};

