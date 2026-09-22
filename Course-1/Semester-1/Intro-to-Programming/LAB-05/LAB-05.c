#include <stdio.h>

int main(void){
	int num1, num2;
	// task 2
	printf("Enter number one : ");
	scanf_s("%d", &num1);
	printf("Enter number two : ");
	scanf_s("%d", &num2);
	num1 > num2 ? printf("True\n") : printf("False\n");

	// task 3
	int a, b, c;
	printf("Enter side a : ");
	scanf_s("%d", &a); // 3 5 5
	printf("Enter side b : ");
	scanf_s("%d", &b); // 4 5 5
	printf("Enter side c : ");
	scanf_s("%d", &c); // 5 5 3
	
	if (a + b > c && a + c > b && b + c > a) {
		printf("Triangle can be possible\n");
		if (a == b && b == c) {
			printf("Triangle is equilateral\n");
		}
		else if (a != b && b != c && a != c) {
			printf("Triangle is scalene\n");
		}
		else {
			printf("Triangle is isosceles\n");	
		}
		if ((c * c) == (a * a + b * b)) {
			printf("Triangle is rectangular\n");
		}
		else if ((c * c) < (a * a + b * b)) {
			printf("Triangle is acute-angled\n");
		}
		else {
			printf("Triangle is obtuse\n");	
		}
	}
	else {
		printf("Triangle can't be possible\n");
	}

	// task 4
	int num;
	printf("Enter a three digit number (100-999) : ");
	scanf_s("%d", &num);

	if (num < 100 || num > 999) {
		printf("Error: Please enter a number between 100 and 999.\n");
		return 1;
	}

	int hundreds = num / 100;
	int tens = (num / 10) % 10; 
	int units = num % 10;

	const char* h_str[] = { "", "one hundred", "two hundred", "three hundred", "four hundred", "five hundred", "six hundred", "seven hundred", "eight hundred", "nine hundred" };
	const char* t_str[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	const char* teen_str[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	const char* u_str[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	printf("%s ", h_str[hundreds]);

	if (tens == 1) {
		printf("%s\n", teen_str[units]);
	}
	else {
		if (tens > 1) {
			printf("%s ", t_str[tens]);
		}
		if (units > 0) {
			printf("%s", u_str[units]);
		}
		printf("\n");
	}
	
	return 0;
}