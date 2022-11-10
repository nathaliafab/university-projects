// https://www.thehuxley.com/problem/3678

#include <stdio.h>

int main()
{
    int A, B, C, D, qtSaque, qtManju, qtYaki;

    scanf("%i %i %i %i", &A, &B, &C, &D);
    A *= 15;

    qtSaque = D * 4;
    qtManju = D * 5;
    qtYaki = D * 3;

    if (qtSaque > A) // && qtManju > B && qtYaki <= C)
    {
        if (qtManju > B && qtYaki > C)
            printf("Partiu Festa do Japa...Japacama\n");

        else if (qtManju > B && qtYaki <= C)
            printf("Faltaram %d saques e %d manjus\n", qtSaque - A, qtManju - B);

        else if (qtManju <= B && qtYaki > C)
            printf("Faltaram %d saques e %d yakitoris\n", qtSaque - A, qtYaki - C);

        else
            printf("Faltaram %d saques\n", qtSaque - A);
    }

    else if (qtManju > B)
    {
        if (qtYaki > C)
            printf("Faltaram %d manjus e %d yakitoris\n", qtManju - B, qtYaki - C);

        else
            printf("Faltaram %d manjus\n", qtManju - B);
    }

    else
        qtYaki > C ? printf("Faltaram %d yakitoris\n", qtYaki - C) : printf("Partiu Festa do Japa!\n");

    return 0;
}
