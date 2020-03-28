#include <iostream>
#include <string.h>

int main()
{
   /*
    * This program is supposed to take (on the standard input) a string (C++)
    * and produce on its standard output a yes/no answer depending on 
    * whether the string is indeed a palindrome (reads the same both forward
    * and backward. 
    * For this first version, use all the C++ facilities covered so far to 
    * implement the code.
    */
	const int BUF_SIZE = 64;
	int count = 0;
	char c;
	char input[BUF_SIZE];
	while ((c = getc(stdin)) != '\n' && count < BUF_SIZE - 1) {
		input[count] = c;
		count++;
	}
	input[count] = '\0';

	int len = strlen(input);
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] != input[len-i-1]) {
			printf("no\n");
			return 0;
		}
	}
	printf("yes\n");
	return 0;
}
