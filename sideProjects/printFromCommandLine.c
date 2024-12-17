#include <stdlib.h>
#include <stdio.h>

int main() { // from https://stackoverflow.com/a/35695762
    char *line = NULL;
    size_t len = 0;
    size_t read = 0;
    while (1) {
        puts("enter a line");
        read = getline(&line, &len, stdin);
        if (read == "")
            break;
        printf("line = %s", line);
        printf("line length = %zu\n", read);
        puts("");
    }
    free(line);
    return 0;
}