#include <stdio.h>

void update(int *a, int *b) {
    // Complete this function
    int abs(), temp = *a;

    *a = temp + *b;
    *b = abs(temp - *b);

}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    printf("Enter two intergers (space in between intergers is required): ");
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d\n", a, b);

    return 0;
}
