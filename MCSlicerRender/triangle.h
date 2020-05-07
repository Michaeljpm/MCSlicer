#pragma once
#include "vertex.h"
class tri
{
public:
	vertex normal, x, y, z;
	double zMax, zMin;
	tri();
	tri(vertex normal, vertex x, vertex y, vertex z);
	void findzMax();
	void findzMin();
	~tri();



};

