#include <stdio.h>

int main() {
	// Files
	//fprintf(file), w , a, 

	// task 1
	int n;
	printf("Write please line count do u want to write : ");
	scanf_s("%d", &n);
	getchar(); // vs enter
	if (n < 10)
	{
		printf("Count of lines must be at least 10");
	}
	else {
		FILE* file = fopen("mfile.txt", "w");
		for (int i = 1; i <= n; i++)
		{
			char value[255];
			fgets(value, sizeof(value), stdin);
			fputs(value, file);
		}
		fclose(file);
	}

	return 0;
}