#include <stdio.h>
#include <string.h>
#include "getdbpath.h"

void print_task(char *task) {
	printf("%s", task);	
}

int main (int argc, char *argv[]) {
	FILE *file = fopen(strcat(get_db_path(), "/tasks"), "r");
	if (file == NULL) {
		printf("task file not found\n");
		return 1;
	}
	char line[200];
	while(fgets(line, 200, file)) {
  		print_task(line);
	}
	fclose(file);
}
