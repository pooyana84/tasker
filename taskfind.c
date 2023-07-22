#include <stdio.h>
#include <string.h>
#include "getdbpath.h"

int main(int argc, char *argv[]) {
	FILE *file = fopen(strcat(get_db_path(), "/tasks"), "r");
	if (file == NULL) {
		printf("task file not found\n");
		return 1;
	}
	char line[1000];
	for(int i = 0; fgets(line, 1000, file); i++) {
		for (int j = 0; line[j]; j++) {
			if (line[j] == '\n') {
				line[j] = '\0';
				break;
			}
		}
  		if (!strcmp(line, argv[1])) {
			printf("%i\n", i + 1);
			break;
		}
	}
}
