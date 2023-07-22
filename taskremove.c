#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "getdbpath.h"

int main(int argc, char *argv[]) {
	FILE *file = fopen(strcat(get_db_path(), "/tasks"), "a");
	FILE *temp = fopen(strcat(get_db_path(), "/temp"), "w");
	int index = argv[1][0] - '0';
	char line[1000];
	for (int i = 1; fgets(line, 1000, file); i++) {
		if (i == index) {
			continue;
		}
		fprintf(temp,"%s", line);
	}
	fclose(file);
	fclose(temp);
	remove(strcat(get_db_path(), "/tasks"));
	rename(strcat(get_db_path(), "/temp"), strcat(get_db_path(), "/tasks"));
}
