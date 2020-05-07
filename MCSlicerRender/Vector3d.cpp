#include "Vector3d.h"

Vec3d::Vec3d(vertex v)
{
	this->i = v.x;
	this->j = v.y;
	this->k = v.z;
}

Vec3d::Vec3d()
{
	this->i = 0;
	this->j = 0;
	this->k = 0;

}
Vec3d::Vec3d(double i, double j, double k)
{
	this->i = i;
	this->j = j;
	this->k = k;
}

void Vec3d::setVec(double i, double j, double k)
{
	this->i = i;
	this->j = j;
	this->k = k;
}
double Vec3d::magnitude()
{
	double under = (i * i) + (j * j) + (k * k);
	return sqrt(under);
}

Vec3d Vec3d::normalize()
{
	double mag = magnitude();
	return Vec3d((i / mag), (j / mag), (k / mag));
}
double Vec3d::dot(const Vec3d& v)
{
	return (i * v.i) + (j * v.j) + (k * v.k);
}
Vec3d Vec3d::cross(const Vec3d& v)
{
	double cx = (j * v.k) - (k * v.j);
	double cy = (k * v.i) - (i * v.k);
	double cz = (i * v.j) - (j * v.i);
	return Vec3d(cx, cy, cz);
}