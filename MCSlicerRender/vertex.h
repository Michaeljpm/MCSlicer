#pragma once
#include <iostream>
#include <string>

class vertex
{
public:
	double x, y, z;
	vertex();
	vertex(char* in);
	vertex(double x, double y, double z);
	void set(double x, double y, double z);
	std::string printVertex();
	vertex operator+(const vertex& v)
	{
		return vertex(x + v.x, y + v.y, z + v.z);
	}
	vertex operator-(const vertex& v)
	{
		//double x1 = x - v.x;
		return vertex(x - v.x, y - v.y, z - v.z);
	}
	vertex operator*(const double& n)
	{
		return vertex(x * n, y * n, z * n);
	}
};

