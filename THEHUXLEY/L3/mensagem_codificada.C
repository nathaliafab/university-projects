// https://www.thehuxley.com/problem/975

#include <stdio.h>

int main()
{
    char string[500];
    scanf("%499[^\n]", string);

    for (int i = 0; string[i] != '\0'; i++)
    {
        switch (string[i])
        {
        case '4':
            string[i] = 'a';
            break;

        case '5':
            string[i] = 'e';
            break;

        case '1':
            string[i] = 'i';
            break;

        case '0':
            string[i] = 'o';
            break;

        case '2':
            string[i] = 'u';
            break;
        }

        if (string[i] >= 'a' && string[i] <= 'z')
            if (i == 0 || string[i - 2] == '.')
                string[i] -= 32;
    }

    printf("%s", string);

    return 0;
}
