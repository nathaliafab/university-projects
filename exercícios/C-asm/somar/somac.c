#include <stdio.h>
extern int soma(int, int, int);

int main(void)
{
    int a = 1, b = 4, c = 5, value;
    value = soma(a, b, c);
    printf("soma(%d, %d, %d) = %d\n", a, b, c, value);
}