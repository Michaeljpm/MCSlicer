#include "vertex.h"
vertex::vertex()
{
	x = 0;
	y = 0;
	z = 0;

}

vertex::vertex(char* in)
{
	char p1[4] = { in[0],in[1],in[2],in[3] };
	char p2[4] = { in[4],in[5],in[6],in[7] };
	char p3[4] = { in[8],in[9],in[10],in[11] };

	float xf = *((float*)p1);
	float yf = *((float*)p2);
	float zf = *((float*)p3);

	x = double(xf);
	y = double(yf);
	z = double(zf);
}

vertex::vertex(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void vertex::set(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

std::string vertex::printVertex()
{
	std::string v = " " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z);
	return v;
}