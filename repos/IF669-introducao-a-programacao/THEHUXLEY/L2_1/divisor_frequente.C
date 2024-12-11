// https://www.thehuxley.com/problem/2403

#include <stdio.h>

int main()
{
    int d, x, n = 0, counter = 0, dfrec, xtemp;
    scanf("%d", &x);

    for (int i = 1, d = 2; i <= x; i++, d++)
    {
        xtemp = x;
        n = 0;

        while (xtemp % d == 0)
        {
            xtemp /= d;
            n++;
        }

        if (n > counter)
        {
            counter = n;
            dfrec = d;
        }
    }

    printf("mostFrequent: %d, frequency: %d", dfrec, counter);
    return 0;
}
