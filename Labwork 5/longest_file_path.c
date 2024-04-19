#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024

int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

int max(int a, int b) {
    return a > b ? a : b;
}

int longest_path_recursive(const char *dir_path, int depth) {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH_LENGTH];
    int max_length = 0;

    if (!(dir = opendir(dir_path)))
        return 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;

            snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
            if (is_directory(path))
                max_length = max(max_length, longest_path_recursive(path, depth + 1));
        } else {
            snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
            max_length = max(max_length, strlen(path));
        }
    }

    closedir(dir);
    return max_length;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    char *dir_path = argv[1];
    int longest_path_length = longest_path_recursive(dir_path, 0);

    if (longest_path_length > 0)
        printf("Longest file path in directory '%s' is %d characters.\n", dir_path, longest_path_length);
    else
        printf("No files found in directory '%s'.\n", dir_path);

    return 0;
}
