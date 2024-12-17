#include <stdlib.h>
#include <stdio.h>

int main()
{
	puts("Fahrenheit-Celsius");
	for (int i = 0; i < 301; i += 20) {
		printf("    %d", i);

		int count = 0;
		int num;
		if (i == 0)
		{
                	num = i + 1;
		}
		else 
		{
			num = i;
		}
                while (num > 0)
                {
                        count++;
                        num /= 10;
                }
		for (int j = 8; j - count > 0; j--) {
			printf(" ");
		}

		printf("%d\n", tempConvert(i));
	}
	return 0;
}

int tempConvert(int num)
{
	return 5 * (num - 32) / 9;
}

/**
 *  Fahrenheit-Celsius
 *  123456789012345678
 *  ____Num______Num
 *  ____N________Num
 *
 */
