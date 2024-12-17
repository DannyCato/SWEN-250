#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define FALSE (0)
#define TRUE  (1)

int main(int argc, char** argv) {
	int tot_chars = 0 ;	/* total characters */
	int tot_lines = 0 ;	/* total lines */
	int tot_words = 0 ;	/* total words */

	int c, word = FALSE;
	while ((c = getchar()) != EOF) {
		tot_chars++;
		if (iscntrl(c)) {
			tot_lines++;
			word = FALSE;
			continue;
		}
		if (isspace(c) == 0) {
			if (word == FALSE) {
				tot_words++;
				word = TRUE;
			}
		} else {
			word = FALSE;
		}
	}

	printf(" %i  %i  %i\n", tot_lines, tot_words, tot_chars);

/*
	int BUFFERSIZE = 100;
	char buffer[BUFFERSIZE];
	char lastBuffer[BUFFERSIZE];
	int n = 0;
	int word = FALSE;


	while (1) {
        fgets(buffer, BUFFERSIZE, stdin);
        if (strcmp(buffer, lastBuffer) == 0) {
            n++;
            if (n >= 10) {
                break;
            }
            continue;
        }
		n = 0;
		tot_lines++;
        printf("%s",buffer);
        strcpy(lastBuffer, buffer);

		int i = 0;
		char c = 0;
		while (c != "\0") {
			printf("%c <- Current Char\n", c);
			c = buffer[i];
			if (isalnum(c)) {
				if (word == FALSE) {
					tot_words++;
					word = TRUE;
				}
				tot_chars++;
			} else {
				word = FALSE;
			}
			i++;

		}
    }

	printf("%i chars,", tot_chars);
	printf(" %i words,", tot_words);
	printf(" %i lines\n", tot_lines);

*/

	return 0 ;
}
