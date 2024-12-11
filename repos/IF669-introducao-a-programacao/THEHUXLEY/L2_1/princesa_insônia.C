// https://www.thehuxley.com/problem/2401

#include <stdio.h>

int main()
{
    int k, i, m, n, d, feridos = 0;

    scanf("%d %d %d %d %d", &k, &i, &m, &n, &d);

    for (int count = 1; count <= d; count++)
    {
        if (count % k == 0 || count % i == 0 || count % m == 0 || count % n == 0)
            feridos++;
    }

    printf("%d", feridos);

    return 0;
}
