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

int main()
{
    int t, test_case[t] = {};
    printf("number of test cases (1 - 100,000 and must be differnt from each other): ");
    scanf("%d\n", &t);

    for (int i = 1; i <= t; i++)
    {
        scanf("%d\n", &t);
        test_case[i] = t;
    }
    for (int l = 1; l <= )

    int count = 1;
    for (int j = 3, k = 10; j < 106, k <= 106; j += 12, k += 12)
    {
        printf("A[%d]: %d  |  A[%d]: %d\n", count, j, count, k);
        count++;
    }

    int A[] = {3, 10, 15, 22, 27, 34, 39, 46, 51, 58, 63, 70, 75, 82, 87, 94, 99, 106};

    return 0;
}
