#include <stdio.h>
#include <math.h>

void printBinary(unsigned int n) {
	for (int i = 7; i >= 0; i--) {
		int bit = (n >> i) & 1;
		printf("%d", bit);
	}
}

void printSquare(void) {
	double a, b, c;
	printf("Enter a : ");
	scanf_s("%lf", &a, (unsigned int)sizeof(a));
	printf("Enter b : ");
	scanf_s("%lf", &b, (unsigned int)sizeof(b));
	printf("Enter c : ");
	scanf_s("%lf", &c, (unsigned int)sizeof(c));

	if (a == 0) {
		printf("This is not square equation\n");
		return;
	}

	double descrim = (b * b) - (4 * a * c);
	if (descrim > 0) {
		double x1 = (-b + sqrt(descrim)) / (2 * a);
		double x2 = (-b - sqrt(descrim)) / (2 * a);
		printf("x1 = %lf\n", x1);
		printf("x2 = %lf\n", x2);
	}
	else if (descrim == 0) {
		double x = -b / (2 * a);
		printf("x = %lf\n", x);
	}
	else {
		printf("The sqrts can not be able\n");
	}
}


int main() {
	printf("Task 2 :\n");
	unsigned int a = 8;
	unsigned int b = 4;
	printf("Sum a + b  = "); // 12 
	printBinary(a + b);
	printf("\n");

	printf("Sub a - b  = "); // 4
	printBinary(a - b);
	printf("\n");

	printf("Mult a * b = "); // 32
	printBinary(a * b);
	printf("\n");

	printf("Div a / b = "); // 2
	printBinary(a / b);
	printf("\n");

	printf("a == b ");
	printBinary(a == b); // false
	printf("\n");

	printf("(a/2) == b ");
	printBinary((a  / 2 ) == b); // true
	printf("\n");

	printf("a || b == 8");
	printBinary(a || b == 8); // true
	printf("\n");

	printf("a && b % 3 == 0");
	printBinary(a && b % 3 == 0); // false
	printf("\n");

	unsigned int c = 3;
	printBinary(c);
	printf("\n");
	c++; // 4
	printBinary(c);
	printf("\n");
	--c; // 3
	printBinary(c); 
	printf("\n");
	printf("Invert c = ");
	printBinary(~c); // invert zeros to one, one to zeros | 252
	printf("\n");
	printf("Shift left 1 = ");
	printBinary(c << 1); // shift bites to left on 1 | 6
	printf("\n");
	printf("Shift right 1 = ");
	printBinary(c >> 1); // shift bites to right on 1 | 1
	printf("\n");
	
	printf("Task 3 :\n");
	unsigned int d;
	unsigned int* ptr = &d;
	scanf_s("%u", ptr, (unsigned int)sizeof(d));
	printf("%p\n", (void*)ptr);
	printf("%u\n", *ptr);

	printf("Task 4 :\n");
	printSquare();

	return 0;
}