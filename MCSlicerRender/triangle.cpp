#include "triangle.h"

tri::tri()
{
	normal.set(0, 0, 0);
	x.set(0, 0, 0);
	y.set(0, 0, 0);
	z.set(0, 0, 0);
	zMin = 0;
	zMax = 0;

}
tri::tri(vertex normal, vertex x, vertex y, vertex z)
{
	this->normal = normal;
	this->x = x;
	this->y = y;
	this->z = z;
	findzMax();
	findzMin();

}

void tri::findzMax()
{
	double max = 0;
	if (x.z > max)
	{
		max = x.z;
	}
	if (y.z > max)
	{
		max = y.z;
	}
	if (z.z > max)
	{
		max = z.z;
	}
	zMax = max;
}

void tri::findzMin()
{
	double min = x.z;

	if (y.z < min)
	{
		min = y.z;
	}
	if (z.z < min)
	{
		min = z.z;
	}
	zMin = min;
}

tri::~tri()
{

}