// problem 5, remove spaces

#include <stdio.h>
#include <string.h>

int main()
{
	char with_spaces[51], no_spaces[51];
	int c, d;
	printf("Enter some text: ");
	gets(with_spaces);
	int length;
	length = strlen(with_spaces);
	d = 0;
	for (c = 0; c < length; c++)
	{
		if (with_spaces[c] != ' ')
		{
			no_spaces[d] = with_spaces[c];
			d++;
		}
	}
	no_spaces[d] = '\0';

	printf("String after removing spaces: %s\n", no_spaces);

   return 0;
}
