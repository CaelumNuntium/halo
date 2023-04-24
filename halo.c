#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "refraction.h"

const double PI = 3.141592653589793;

int main()
{
	vector s1, s2, s3, n1, n2;
	double theta, psi, h, a, h0;
	int i, j;
	FILE* fp;
	const double n = 1.31;
	double h0_deg = 50;
	h0 = h0_deg / 180.0 * PI;
	if((fp = fopen("result.dat", "w")) == NULL)
	{
		return 1;
	}
	s1 = new_vector(-cos(h0), 0.0, -sin(h0));
	for(i = 0; i <= 3600; i += 2)
	{
		theta = i * PI / 1800.0;
		for(j = 0; j <= 3600; j += 2)
		{
			psi = j * PI / 1800.0;
			n1 = new_vector(cos(theta) * cos(psi), cos(theta) * sin(psi), sin(theta));
			n2 = new_vector(-cos(2 * PI / 3 - theta) * cos(psi), -cos(2 * PI / 3 - theta) * sin(psi), sin(2 * PI / 3 - theta));
			s2 = refraction(s1, n1, n);
			s3 = refraction(s2, negative(n2), 1.0 / n);
			h = atan(-s3.z / sqrt(s3.x * s3.x + s3.y * s3.y));
			a = atan2(s3.y, -s3.x);
			if(!isnan(h))
			{
				fprintf(fp, "%lf %lf\n", a / PI * 180, h / PI * 180);
			}
		}
	}
	fclose(fp);
	if((fp = fopen("sun.dat", "w")) == NULL)
	{
		return 1;
	}
	fprintf(fp, "0 %lf\n", h0_deg);
	fclose(fp);
	return 0;
}
