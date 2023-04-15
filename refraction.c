#include <math.h>
#include "refraction.h"
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

vector refraction(vector ray, vector plane, double n)
{
	vector res_parallel;
	vector res_perp;
	vector res;
	if(n < 1)
	{
		if(1.0 - dot(ray, plane) * dot(ray, plane) > n * n || (ray.x == 0 && ray.y == 0 && ray.z == 0))
		{
			res.x = 0;
			res.y = 0;
			res.z = 0;
			return res;
		}
		plane = negative(plane);
	}
	res_parallel = cdot(1.0 / n, sum(cdot(fabs(dot(ray, plane)), plane), ray));
	res_perp = negative(cdot(sqrt(1.0 - 1.0 / n / n * (1.0 - dot(ray, plane) * dot(ray, plane))), plane));
	res = sum(res_parallel, res_perp);
	return res;
}

vector new_vector(double x, double y, double z)
{
	vector res;
	res.x = x;
	res.y = y;
	res.z = z;
	return res;
}
