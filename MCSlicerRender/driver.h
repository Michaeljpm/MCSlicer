#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Vector3d.h"
#include "vertex.h"
#include "triangle.h"
#include "Endpoints.h"
#include "coords.h"
using namespace std;

class driver
{
	vector<tri> t;
	double z;

public:
	void readstl();
	void setZ(double z);
	double getZ();
	int getSize();
	void findendpoints(vector<coords> &v);

};