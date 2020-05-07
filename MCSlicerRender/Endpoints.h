#pragma once
#include <iostream>
#include <cmath>
#include "vertex.h"
#include "Vector3d.h"
#include "triangle.h"

class Endpoints
{
public:
	tri triangle;
	double slizeZ;
	vertex p1, p2;
	bool p1used;
	Vec3d pnormal;
	vertex Q;
	Endpoints(tri triangle, double z);

	void dotnorm();
	void algorithm(vertex &a, vertex &b);
	
	
};

