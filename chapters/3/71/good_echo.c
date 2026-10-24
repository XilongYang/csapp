#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4

int echo() {
    char buffer[BUFSIZE];
    while (fgets(buffer, BUFSIZE, stdin)) {
        if (EOF == fputs(buffer, stdout)) {
            return EXIT_FAILURE;
        }
        if (strchr(buffer, '\n') != NULL) {
            break;
        }
    }
    if (ferror(stdin)) {
        return EXIT_FAILURE;
    }
    if (fflush(stdout) == EOF) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int main(void)
{
    return echo();
}
