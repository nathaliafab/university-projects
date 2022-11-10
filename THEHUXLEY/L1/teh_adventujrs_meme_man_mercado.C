// https://www.thehuxley.com/problem/3674

#include <stdio.h>

int main()
{
    int a, b, c, d;
    int a1 = 0, b1 = 0, c1 = 0, d1 = 0;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a < 0 || b < 0 || c < 0 || d < 0)
        printf("lurn maf :(\n");

    else
    {
        if (a == 0)
        {
            a1 = b * b;

            if (a1 > 0)
                b1 = 2;
        }

        if (b + b1 > c)
            c1 = a1 - c;

        if (c1 > 0)
        {
            if (d < 2000)
                d1 = 2000 - d;
        }

        else
        {
            d1 = 500;
            c1 = 0;
        }

        printf("%d laranjas\n%d bananas\n%d ovos\n%d mL de leite\n", a1, b1, c1, d1);
    }

    return 0;
}
