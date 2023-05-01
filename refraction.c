#include <math.h>
#include "vector.h"
#include "refraction.h"

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
