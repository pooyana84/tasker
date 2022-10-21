#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <string.h>

char* home_path;

void print_tasks() {
    FILE* file_data_tasks;
    char pointer;
    file_data_tasks = fopen(strcat(home_path, "/.tasker/data/tasks.data"), "r");
    while ((pointer = fgetc(file_data_tasks)) != EOF) {
        printf("%c", pointer);
    }
}

int main(int argc, char* argv[]) {
    home_path = getenv("HOME");
    if (argc == 1)
        return 0;
    if (!strcmp(argv[1], "read"))
        print_tasks();
}
