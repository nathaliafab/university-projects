// https://www.thehuxley.com/problem/1183

#include <stdio.h>

int main()
{
    int i, flag = 1, asciiValue[127] = {0}, tamanho = 0;
    char string1[500], string2[500];

    scanf("%499[^\n] %499[^\n]", string1, string2);

    for (i = 0; string1[i] != '\0'; i++)
    {
        if (string1[i] != ' ' && string1[i] != '!' && string1[i] != ',' && string1[i] != '.' && string1[i] != '?')
        {
            if (string1[i] >= 'A' && string1[i] <= 'Z')
                string1[i] += 32;

            asciiValue[string1[i]]++;
            tamanho++;
        }
    }

    for (i = 0; flag && string2[i] != '\0'; i++)
    {
        if (string2[i] != ' ' && string2[i] != '!' && string2[i] != ',' && string2[i] != '.' && string2[i] != '?')
        {
            if (string2[i] >= 'A' && string2[i] <= 'Z')
                string2[i] += 32;

            if (asciiValue[string2[i]] > 0)
            {
                asciiValue[string2[i]]--;
                tamanho--;
            }

            else
                flag = 0;
        }
    }

    if (tamanho != 0)
        flag = 0;

    flag ? printf("True") : printf("False");

    return 0;
}
