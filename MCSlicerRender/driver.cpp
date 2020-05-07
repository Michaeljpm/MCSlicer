#include "driver.h"

void driver::readstl()
{
	ifstream infile;
	infile.open("helix1.stl.stl", ios::in | ios::binary);

	char header[80];
	infile.read(header, 80);
	string str(header);
	char stuff[4];

	unsigned long numOfTriangles;
	

	if (str.substr(0, str.find(" ")) == "Solid")
	{
		cout << "Unable to process. Binary Stl Required!" << endl;
	}
	else
	{

		infile.read(stuff, 4);
		numOfTriangles = *((unsigned long*)stuff);
		cout << str << " " << numOfTriangles << endl;

		for (int x = 0; x < numOfTriangles; x++)
		{
			char input[50];

			if (infile)
			{
				infile.read(input, 50);
				vertex n(input);
				vertex p1(input + 12);
				vertex p2(input + 24);
				vertex p3(input + 36);

				t.push_back(tri(n, p1, p2, p3));
			}
		}



	}
}
void driver::setZ(double z)
{
	this->z = z;
}
void driver::findendpoints(vector<coords> &v)
{
	coords temp;
	for (int x = 0; x < t.size(); x++)
	{
		if (t.at(x).zMin < z && t.at(x).zMax > z)
		{
			Endpoints p(t.at(x), z);
			p.dotnorm();
			temp.x = p.p1.x;
			temp.y = p.p1.y;
			temp.x1 = p.p2.x;
			temp.y1 = p.p2.y;
			v.push_back(temp);
				//p.p1.printVertex() << " " << p.p2.printVertex() << endl;
		}
	}
}

int driver::getSize()
{
	return t.size();
}

double driver::getZ()
{
	return z;
}