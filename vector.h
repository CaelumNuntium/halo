typedef struct
{
	double x;
	double y;
	double z;
} vector;

double norm(vector);
double dot(vector, vector);
vector cdot(double, vector);
vector sum(vector, vector);
vector negative(vector);
vector new_vector(double, double, double);
