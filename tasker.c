#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <string.h>

char* home_path;
char* data_file_path;

void init() {
    home_path = getenv("HOME");
    data_file_path = getenv("HOME");
    strcat(data_file_path, "/.tasker/data/tasks.data");
}

void print_tasks() {
    FILE* file_data_tasks;
    file_data_tasks = fopen(data_file_path, "r");
    char pointer;
    while ((pointer = fgetc(file_data_tasks)) != EOF) {
        printf("%c", pointer);
    }
    fclose(file_data_tasks);
}

void write_task(char* task) {
    FILE* file_data_tasks;
    file_data_tasks = fopen(data_file_path, "a");
    fputs(task, file_data_tasks);
    fputs("\n", file_data_tasks);
    fclose(file_data_tasks);
}

int main(int argc, char* argv[]) {
    init();
	if (argc == 1)
        return 0;
    if (!strcmp(argv[1], "read")) {
        print_tasks(); 
		return 0;
	}
	if (!strcmp(argv[1], "add")) {
		for (int i = 2; i < argc; i++) 
			write_task(argv[i]);
		return 0;
	}	
    return 0;
}
