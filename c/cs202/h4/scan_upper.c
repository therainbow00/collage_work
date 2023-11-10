#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char c;
	while ((c = fgetc(stdin)) != EOF)
	{
		printf("%c", toupper(c));
	}
    return 0;
}
