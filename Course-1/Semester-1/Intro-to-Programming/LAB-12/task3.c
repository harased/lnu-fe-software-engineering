#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 255

int main() {
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

	

	return 0;
}