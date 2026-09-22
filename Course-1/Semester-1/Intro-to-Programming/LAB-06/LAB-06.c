#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vowconChecker() {
	char sentence[100];
	printf("Enter your sentence : ");
	fgets(sentence, sizeof(sentence), stdin);
	sentence[strcspn(sentence, "\n")] = '\0';
	size_t length = strlen(sentence);
	printf("%d\n", length);
	int counter_vow = 0, counter_con = 0;
	for (size_t i = 0; i < length; i++)
	{
		char c = tolower(sentence[i]);
		switch (c)
		{
		case 'a':
		case 'o':
		case 'u':
		case 'e':
		case 'y':
		case 'i':
			counter_vow++;
			break;
		default:
			if (c >= 'a' && c <= 'z') {
				counter_con++;
			}
			break;
		}
	}
	printf("Vowels : %d\n", counter_vow);
	printf("Consonants : %d\n", counter_con);
}

int main(void){
	// task 1
	vowconChecker();

	// task 2
	int number = 1;
	int pos_in_list = 20;
	int sum = 0;
	while (number <= 100)
	{
		if (number == 33 || number == pos_in_list) {
			number++;
			continue;
		}
		sum += number;
		number++;
	}
	printf("%d\n", sum);

	// task 3
	int real_number;
	do {
		printf("Enter your number : ");
		scanf_s("%d", &real_number);
		if (real_number < 7 || real_number > 12) {
			printf("Number is possible in range from [7] to [12]\n");
		}
	} while (real_number < 7 || real_number > 12);
	double numbers[12];
	double sum_task_3 = 0;
	double min, max;

	printf("Enter %d real numbers : \n", real_number);
	for (int i = 0; i < real_number; i++) {
		printf("Number %d : ", i + 1);
		scanf_s("%lf", &numbers[i]);

		sum_task_3 += numbers[i];
		if (i == 0) {
				min = numbers[i];
			max = numbers[i];
		}
		else {
			if (numbers[i] < min) {
				min = numbers[i];
			}
		if (numbers[i] > max) {
				max = numbers[i];
			}
		}
	}

	double average = sum_task_3 / real_number;

	printf("\n");
	printf("Result\n");
	printf("Sum : %f\n", sum_task_3);
	printf("Avg : %f\n", average);
	printf("Min : %f\n", min);
	printf("Max : %f\n", max);


	return 0;
}
