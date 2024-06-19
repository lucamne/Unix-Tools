#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if (argc < 2) {
		fprintf(stderr,"usage: wcat <file1> <file2>...\n");
		exit(1);
	}
	
	FILE* fs;
	size_t buffer_size = 1000;
	char* string_buffer = malloc(buffer_size * sizeof(char));
	for (int i = 1; i < argc; i++) {
		fs = fopen(argv[i], "r");
		// check if file was successfully opened
		if (fs == NULL) {
			fprintf(stderr,"Could not open %s\n",argv[i]);
			exit(1);
		}
		// read and print file line by line
		while (fgets(string_buffer, buffer_size, fs) != NULL) {
		       printf("%s", string_buffer);
		}
		// close file stream
		fclose(fs);
	}
	return 0;
}
