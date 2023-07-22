#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "getdbpath.h"


int add_task(char *task) {
	FILE *file = fopen(strcat(get_db_path(), "/tasks"), "a");
	if (file == NULL) {
		return 1;
	}
	fprintf(file, "%s\n", task);
	fclose(file);
	return 0;
}

int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		if(add_task(argv[i])) {
			printf("there was a problem adding %s\n", argv[i]);
		}
	}
	printf("done\n");
}
