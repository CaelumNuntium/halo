typedef struct
{
	double x;
	double y;
	double z;
} vector;

double norm(vector);
double dot(vector, vector);
vector refraction(vector, vector, double);
vector cdot(double, vector);
vector sum(vector, vector);
vector negative(vector);
vector new_vector(double, double, double);
