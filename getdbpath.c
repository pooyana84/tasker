#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>
#include <string.h>

char* get_db_path() {
	char *db_path;
	if ((db_path = getenv("HOME")) == NULL) {
		db_path = getpwuid(getuid())->pw_dir;
	}
	strcat(db_path, "/.task");
	return db_path;
}
