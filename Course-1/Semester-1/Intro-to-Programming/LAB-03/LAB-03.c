#include <stdio.h>

void printBinary(unsigned int n) {
	for (int i = 7; i >= 0; i--) {
		int bit = (n >> i) & 1;
		printf("%d", bit);
	}
}

void printTable(void) {
	char name1[30], email1[30], color1[30];
	char name2[30], email2[30], color2[30];

	printf("Enter your name : ");
	scanf_s("%29s", name1, (unsigned int)sizeof(name1));
	printf("Enter your email : ");
	scanf_s("%29s", email1, (unsigned int)sizeof(email1));
	printf("Enter your color : ");
	scanf_s("%29s", color1, (unsigned int)sizeof(color1));

	printf("Enter your name : ");
	scanf_s("%29s", name2, (unsigned int)sizeof(name2));
	printf("Enter your email : ");
	scanf_s("%29s", email2, (unsigned int)sizeof(email2));
	printf("Enter your color : ");
	scanf_s("%29s", color2, (unsigned int)sizeof(color2));

	printf("\n+----+----------------------+---------------------------+-----------------+\n");
	printf("| %-2s | %-20s | %-25s | %-15s |\n", "No", "Name", "Email", "Color");
	printf("+----+----------------------+---------------------------+-----------------+\n");
	printf("| %-2d | %-20s | %-25s | %-15s | \n", 1, name1, email1, color1);
	printf("| %-2d | %-20s | %-25s | %-15s | \n", 2, name2, email2, color2);
	printf("+----+----------------------+---------------------------+-----------------+\n");
}

int main(void) {
	printf("Task 1\n");
	printf("Hello world!\n");

	printf("Task 2\n");
	int number = 67;
	printf("Integers\n");
	printf("Decimal : %d\n", number);
	printf("Octal : %o\n", number);
	printf("Hex : %x\n", number);
	printf("Binary :\n");
	printBinary(number);
	printf("\n");

	double numberrl = 13.13131313131313131313;
	printf("Real numbers\n");
	printf("Float : %f\n", numberrl);
	printf("Float with precision : %.2f\n", numberrl);
	printf("Exponential : %e\n", numberrl);
	printf("Flex : %g\n", numberrl);

	char ch = 'A';
	char str[] = "Hello World!";
	int* ptr = &number;
	printf("Chars, Strings, Pointers\n");
	printf("Char : %c\n", ch);
	printf("String : %s\n", str);
	printf("Pointer : %p\n", ptr);

	printf("Task 3\n");
	printTable();

	return 0;
}