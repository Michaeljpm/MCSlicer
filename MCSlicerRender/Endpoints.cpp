#include "Endpoints.h"

Endpoints::Endpoints(tri triangle, double z)
{
	this->triangle = triangle;
	slizeZ = z;
	pnormal.setVec(0, 0, 1);
	Q.set(0, 0, z);
	p1used = false;
}

void Endpoints::dotnorm()
{
	Vec3d u(triangle.y - triangle.x);
	Vec3d v(triangle.z - triangle.y);
	Vec3d w(triangle.x - triangle.z);
	if (u.dot(pnormal) != 0)
	{
		algorithm(triangle.x, triangle.y);
	}
	if (v.dot(pnormal) != 0)
	{
		algorithm(triangle.y, triangle.z);
	}
	if (w.dot(pnormal) != 0)
	{
		algorithm(triangle.z, triangle.x);
	}
}

void Endpoints::algorithm(vertex& a, vertex& b)
{
	vertex upper = Q - a;
	vertex lower = b - a;
	double s = pnormal.dot(Vec3d(upper)) / pnormal.dot(Vec3d(lower));
	if (s < 0 || s > 1)
	{
		return;
	}
	vertex r = (b - a) * s;
	vertex point = r + a;
	if (p1used == false)
	{
		p1 = point;
		p1used = true;
	}
	else
	{
		p2 = point;
	}

}