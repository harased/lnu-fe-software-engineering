#include <stdio.h>
#include <string.h>

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