#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char c;
    int count = 0;
    int word_count = 0;
	while ((c = fgetc(stdin)) != EOF)
	{
	       if (!isspace(c))
           {
               count++;
           }
           else if (isspace(c))
           {
               word_count++;
           }
           printf(":%d: ", count);
           printf("|%d| ", word_count);
           printf(" average word length is %d ", count / word_count);
	}
    return 0;
}
