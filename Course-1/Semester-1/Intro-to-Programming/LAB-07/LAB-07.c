#include <stdio.h>

void simpleChecker(int number) {
	if (number <= 1)
	{
		printf("Number is not simple\n");
		return;
	}
	int isSimple = 1;
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0) {
			isSimple = 0;
			break;
		}
	}

	if (isSimple) {
		printf("Number is simple\n");

	}
	else {
		printf("Number is not simple\n");
	}

}

int recSum(int n) {
	if (n >= 100) {	
		return 100;
	}
		return n + recSum(n + 1);
}

double f(double x, double N, double A) {
	return N * x + A;
}

double bisFunc(double N, double A, double a, double b, double eps) {
	if (f(a, N, A) * f(b, N, A) >= 0) {
		printf("Error the function interval has equal signs\n");
		return 0;
	}
	double c;
	while ((b - a) >= eps) {
		c = (a + b) / 2.0;
		if (f(c, N, A) == 0) {
			return c;
		}

		if (f(a, N, A) * f(c, N, A) < 0) {
			b = c;
		}
		else {
			a = c;
		}
	}
	return (a + b) / 2;
}

int main() {
	double N = 1;
	double A = 200;
	double a = -100.0;
	double b = 100.0;
	double eps = 0.001;
	printf("%.4f", bisFunc(N, A, a, b, eps));
	return 0;
}