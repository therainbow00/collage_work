/*
// Sample code to perform I/O:
#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include <stdio.h>

int main(){
	int num;
    char str[11];
	scanf("%d", &num);
    scanf("%s", str);

    printf("%d\n", num * 2);
    printf("%s\n", str);
    return 0;
}
