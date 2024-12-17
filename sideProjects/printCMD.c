#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	printf("There are %d arguments\n", argc);

	for (int i = 0; i < argc; i++) 
	{
		printf("#%d\t", i);
		printf("%s\n", argv[i]);
	}
}
