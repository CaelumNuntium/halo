#include <math.h>
#include "vector.h"

vector new_vector(double x, double y, double z)
{
	vector res;
	res.x = x;
	res.y = y;
	res.z = z;
	return res;
}

double norm(vector v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double dot(vector a, vector b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

vector cdot(double a, vector v)
{
	vector res;
	res.x = v.x * a;
	res.y = v.y * a;
	res.z = v.z * a;
	return res;
}

vector sum(vector a, vector b)
{
	vector res;
	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return res;
}

vector negative(vector v)
{
	vector res;
	res.x = -v.x;
	res.y = -v.y;
	res.z = -v.z;
	return res;
}

vector cross(vector a, vector b)
{
    vector res;
    res.x = a.y * b.z - a.z * b.y;
    res.y = a.z * b.x - a.x * b.z;
    res.z = a.x * b.y - a.y * b.x;
    return res;
}
