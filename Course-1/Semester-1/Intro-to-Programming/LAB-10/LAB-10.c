#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

size_t strLenFunc(char* text) {
	char* end = text;
	while (*end != '\0') {
		end++;
	}
	return end - text;
}

int* toPoint(int x, int y) {
	int* arr = (int*)malloc(2 * sizeof(int));
	if (arr == NULL) {
		printf("Error to allocate memory\n");
		return NULL;
	}

	arr[0] = x;
	arr[1] = y;

	return arr;
}

double addCalc(double number, double number_two) {
	return number + number_two;
}

double subCalc(double number, double number_two) {
	return number - number_two;
}

double multCalc(double number, double number_two) {
	return number * number_two;
}

double divCalc(double number, double number_two) {
	if (number_two == 0.0) {
		printf("Division by zero cannot be possible");
		return 0;
	}
	return number / number_two;
}

typedef double (*CalcFunc)(double, double);


int main() {

	CalcFunc operations[4] = { addCalc, subCalc, multCalc, divCalc };

	double num1, num2;
	char op;

	printf("Enter expression : ");

	if (scanf("%lf %c %lf", &num1, &op, &num2) != 3) {
		printf("Invalid format!\n");
		return 1;
	}

	int index = -1;

	switch (op) {
	case '+': index = 0; break;
	case '-': index = 1; break;
	case '*': index = 2; break;
	case '/': index = 3; break;
	default:
		printf("Unknown operator '%c'\n", op);
		return 1;
	}

	double result2 = operations[index](num1, num2);

	printf("Result : %g\n", result2);

	int *result = toPoint(5, 10);

	if (result != NULL) {
		printf("First number : %d\n", result[0]);
		printf("Second number : %d\n", result[1]);
		free(result);
		result = NULL;
	}
		
	printf("%d", strLenFunc("Hello"));
	return 0;
}