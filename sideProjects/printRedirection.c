#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 100

/**
 * 	Strongly based off of https://stackoverflow.com/a/19468457
 * 	Used to make sense of Input Redirection and how to effecitively
 * 	read from the input stream and then close out when done with it
 */

int main() 
{
    char buffer[BUFFERSIZE];
    char lastBuffer[BUFFERSIZE];
    int n = 0;
    while (1) {
        fgets(buffer, BUFFERSIZE, stdin);
        if (strcmp(buffer, lastBuffer) == 0) {
            n++;
            if (n >= 10) {
                break;
            }
            continue;
        }
        printf("Read: %s",buffer);
        strcpy(lastBuffer, buffer);
    }
    return 0;
}
