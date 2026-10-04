#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define COUNT 7


struct Laptop {
	int id;
	char manufacturer[100];
	int displaySize;
	char displayResolution[100];
	char processorType[100];
	int ram;
	char storageType[100];
	int storageCap;
	char graphType[100];
	int batteryCap;
	int price;
};

struct Player {
	char lastName[50];
	char firstName[50];
	int height;
	int weight;
	int age;
	char hairColor[30];
};

int main() {

	struct Player players[COUNT];

	printf("=== Players info ===\n\n");
	for (int i = 0; i < COUNT; i++) {
		printf("--- Player #%d ---\n", i + 1);

		printf("Surname : ");
		scanf("%s", players[i].lastName);

		printf("Name : ");
		scanf("%s", players[i].firstName);

		printf("Height : ");
		scanf("%d", &players[i].height);

		printf("Weight : ");
		scanf("%d", &players[i].weight);

		printf("Age : ");
		scanf("%d", &players[i].age);

		printf("Color hair : ");
		scanf("%s", players[i].hairColor);

		printf("\n");
	}

	for (int i = 0; i < COUNT - 1; i++) {
		for (int j = 0; j < COUNT - i - 1; j++) {
			if (players[j].age < players[j + 1].age) {
				struct Player temp = players[j];
				players[j] = players[j + 1];
				players[j + 1] = temp;
			}
		}
	}

	printf("\n=== Sorted list with age ===\n");
	printf("%-3s | %-15s | %-15s | %-4s | %-4s | %-4s | %-12s\n",
		"N", "Surname", "Name", "Age", "Height", "Weight", "Color hair");
	printf("-----------------------------------------------------------------------\n");

	for (int i = 0; i < COUNT; i++) {
		printf("%-3d | %-15s | %-15s | %-4d | %-4d | %-4d | %-12s\n",
			i + 1,
			players[i].lastName,
			players[i].firstName,
			players[i].age,
			players[i].height,
			players[i].weight,
			players[i].hairColor
		);
	}


	struct Laptop laptops[10] = {
	{1, "Apple", 13, "2560x1664", "Apple M2", 8, "SSD", 256, "Integrated", 52, 1100},
	{2, "Lenovo", 15, "1920x1080", "Intel Core i5-12450H", 16, "SSD", 512, "Integrated", 45, 650},
	{3, "ASUS", 16, "2560x1600", "AMD Ryzen 7 7840HS", 16, "SSD", 1000, "Dedicated (NVIDIA RTX 4060)", 90, 1400},
	{4, "Dell", 13, "1920x1200", "Intel Core i7-1360P", 16, "SSD", 512, "Integrated", 54, 1250},
	{5, "HP", 15, "1920x1080", "Intel Core i3-1215U", 8, "SSD", 256, "Integrated", 41, 450},
	{6, "Acer", 15, "1920x1080", "Intel Core i5-11400H", 16, "SSD", 512, "Dedicated (NVIDIA GTX 1650)", 57, 700},
	{7, "MSI", 17, "2560x1440", "Intel Core i9-13900H", 32, "SSD", 2000, "Dedicated (NVIDIA RTX 4080)", 99, 2800},
	{8, "Samsung", 14, "2880x1800", "Intel Core i7-1360P", 16, "SSD", 1000, "Integrated", 63, 1500},
	{9, "Gigabyte", 15, "1920x1080", "Intel Core i5-12500H", 16, "SSD", 512, "Dedicated (NVIDIA RTX 4050)", 54, 900},
	{10, "Microsoft", 13, "2256x1504", "Intel Core i5-1235U", 8, "SSD", 256, "Integrated", 47, 1000}
	};


	printf("ID | Brand | Display | RAM | Storage | Price\n");
	printf("--------------------------------------------\n");
	for (int i = 0; i < 10; i++) {
		printf("%2d | %-10s | %d\" | %2dGB | %s %dGB | $%d\n",
			laptops[i].id,
			laptops[i].manufacturer,
			laptops[i].displaySize,
			laptops[i].ram,
			laptops[i].storageType,
			laptops[i].storageCap,
			laptops[i].price
		);
	}


	int choose;
	printf("Write id or (0 to return) : ");
	scanf("%d", &choose);
	if (choose > 10 || choose < 0)
	{
		printf("Write id in range from 1 to 10\n");
		return 1;
	}
	if (choose == 0) {
		return 0;
	}
	int idx = choose - 1;
	printf("ID: %d | %s | %d\" | %s | %s | %dGB RAM | %s %dGB | %s | %dWh | $%d\n",
		laptops[idx].id,
		laptops[idx].manufacturer,
		laptops[idx].displaySize,
		laptops[idx].displayResolution,
		laptops[idx].processorType,
		laptops[idx].ram,
		laptops[idx].storageType,
		laptops[idx].storageCap,
		laptops[idx].graphType,
		laptops[idx].batteryCap,
		laptops[idx].price
	);

	return 0;
}