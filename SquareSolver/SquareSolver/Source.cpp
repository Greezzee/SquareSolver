#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <assert.h>
const int SS_INF_ROOTS = -1;

/*!****************************************************
 * Solve linear equation of type ax + b = 0
 *
 * @param [in] a,b coefficients of equation
 *
 * @param [out] x root of equation (don't change if number of roots not 1)
 *
 * @return number of roots (SS_INF_ROOTS if infinity)
 ******************************************************/
int SolveLinear(double a, double b, double* x);


/*!****************************************************
 * Solve square equation of type ax^2 + bx + c = 0
 *
 * @param [in] a,b,c coefficients of equation
 *
 * @param [out] x1 first root of equation (don't change if number of roots not 1 or 2)
 * @param [out] x2 second root of equation (don't change if number of roots not 2)
 *
 * @return number of roots (SS_INF_ROOTS if infinity)
 ******************************************************/
int SolveSquare(double a, double b, double c, double* x1, double* x2);


/*!****************************************************
 * Print information about equation solution to console
 *
 * @param [in] numberOfRoots roots count (SS_INF_ROOTS if infinity)
 * @param [in] x1,x2 roots of equation
 *
 * @return number, sign of which show, whitch string is "bigger"
 ******************************************************/
void PrintRoots(int numberOfRoots, double x1, double x2);

int main()
{
	double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

	printf("Welcome to Square Solver\nTo solve your square equation, enter a, b, c: ");

	int inputCount = scanf("%lg %lg %lg", &a, &b, &c);

	if (inputCount != 3) {
		printf("Not enought numbers\n");
		return 0;
	}

	int numberOfRoots = SolveSquare(a, b, c, &x1, &x2);

	PrintRoots(numberOfRoots, x1, x2);
	return 0;
}

int SolveSquare(double a, double b, double c, double* x1, double* x2)
{
	assert(x1 != NULL);
	assert(x2 != NULL);
	assert(x1 != x2);

	if (a == 0.0) return SolveLinear(b, c, x1);
	if (c == 0.0)
	{
		*x1 = 0.0;
		return SolveLinear(a, b, x2) + 1;
	}

	double discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0) return 0;
	if (discriminant == 0)
	{
		*x1 = (-b) / (2 * a);
		return 1;
	}

	double sqrtDisc = sqrt(discriminant);
	*x1 = (-b - sqrtDisc) / (2 * a);
	*x2 = (-b + sqrtDisc) / (2 * a);

	return 2;
}

int SolveLinear(double a, double b, double* x)
{
	assert(x != NULL);
	if (a == 0.0 && b == 0.0) return SS_INF_ROOTS;
	if (a == 0.0)             return 0;

	*x = -b / a;
	return 1;
}

void PrintRoots(int numberOfRoots, double x1, double x2)
{
	switch (numberOfRoots)
	{
	case 0:
		printf("Equation has 0 roots\n");
		break;
	case 1:
		printf("Equation has 1 root\nx1 = %lg\n", x1);
		break;
	case 2:
		printf("Equation has 2 roots\nx1 = %lg\nx2 = %lg\n", x1, x2);
		break;
	case SS_INF_ROOTS:
		printf("Equation has infinite number of roots\n");
		break;

	default:
		printf("Error");
		break;
	}
}























