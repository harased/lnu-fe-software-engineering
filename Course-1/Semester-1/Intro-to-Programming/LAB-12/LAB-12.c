#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 255
#define BUFFER_SIZE 4096

int copy_file(const char* src_path, const char* dest_path) {
	FILE* src = fopen(src_path, "rb");
	if (src == NULL) {
		printf("Can not open file %s to read!\n", src_path);
		return 0;
	}

	FILE* dest = fopen(dest_path, "wb");
	if (dest == NULL) {
		printf("Can not create file %s to write!\n", dest_path);
		fclose(src);
		return 0;
	}

	char buffer[BUFFER_SIZE];
	size_t bytes_read;

	while ((bytes_read = fread(buffer, 1, sizeof(buffer), src)) > 0)
	{
		fwrite(buffer, 1, bytes_read, dest);
	}

	fclose(src);
	fclose(dest);
}

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
	 // task2
	char lines[MAX_LINES][MAX_LEN]; 
	FILE* file = fopen("mfile.txt", "r");
	int line = 0;
	int total_chars = 0;

	if (file != NULL)
	{
		while (line < MAX_LINES && fgets(lines[line], sizeof(lines[line]), file) != NULL)
		{
			printf("%s", lines[line]);

			int len = strlen(lines[line]);
			if (len > 0 && lines[line][len - 1] == '\n')
			{
				lines[line][len - 1] = '\0'; 
				len--;
			}

			total_chars += len;
			line++;
		}
		fclose(file);

		printf("\nAll sum lines : %d", line);
		if (line > 0) {
			float average = (float)total_chars / line;
			printf("\nAverage characters per line : %.2f\n", average);
		}

		FILE* xfile = fopen("xfile.txt", "w");
		if (xfile != NULL)
		{
			for (int i = line - 1; i >= 0; i--)
			{
				int len = strlen(lines[i]);

				for (int j = len - 1; j >= 0; j--)
				{
					fputc(lines[i][j], xfile);
				}

				fputc('\n', xfile); 
			}
			fclose(xfile);
			printf("Successfully saved to new file\n");
		}
	}
	// task 3

	const char* pdf_src = "example_lab11.pdf";
	const char* pdf_dest = "example_lab11_copy.pdf";

	printf("Copy file (%s -> %s) \n", pdf_src, pdf_dest);
	if (copy_file(pdf_src, pdf_dest)) {
		printf("PDF file succesfuly copied!\n");
	}

	const char* jpg_src = "cat.jpg";
	const char* jpg_dest = "cat_copy.jpg";

	printf("Copy file (%s -> %s)...\n", jpg_src, jpg_dest);
	if (copy_file(jpg_src, jpg_dest)) {
		printf("JPG file succesfuly copied!\n");
	}
	


	return 0;
}