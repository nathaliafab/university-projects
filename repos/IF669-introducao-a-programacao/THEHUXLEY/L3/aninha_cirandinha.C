// https://www.thehuxley.com/problem/2909

#include <stdio.h>

int main()
{
    int n, casos, i;
    int horario, cres, decres, erro;
    scanf("%d", &casos);

    for (int j = 0; j < casos; j++)
    {
        cres = 0;
        decres = 0;
        erro = 0;

        scanf("%d", &n);

        int array[n];

        for (i = 0; i < n; i++)
            scanf("%d", &array[i]);

        if (n == 1)
            cres = 1;

        else
        {
            for (i = 0; !erro && i < n - 1; i++)
            {

                if (array[i] == array[i + 1] || array[0] == array[n - 1])
                    erro = 1;

                else if (array[i] == array[i + 1] - 1 || (i == 0 && array[i] == array[n - 1] + 1))
                    cres = 1;

                else if (array[i] == array[i + 1] + 1 || (i == 0 && array[i] == array[n - 1] - 1))
                    decres = 1;

                else if (i != 0 && ((array[i] < array[i + 1] && array[i] != array[i - 1] - 1) || (array[i] > array[i + 1] && array[i] != array[i - 1] + 1) || (decres && array[0] != array[n - 1] - 1) || (cres && array[0] != array[n - 1] + 1)))
                    erro = 1;

                else if (i == 0 && ((array[0] < array[1] && array[0] != array[n - 1] - 1) || (array[0] > array[1] && array[0] > array[n - 1] + 1)))
                    erro = 1;
            }
        }

        if (!erro)
        {
            if ((decres && !cres) || ((cres && decres) && (array[0] > array[1] && array[n - 1] == array[0] + 1)))
                horario = 0;

            else if ((!decres && cres) || ((cres && decres) && (array[0] < array[1] && array[n - 1] == array[0] - 1)))
                horario = 1;

            else
                horario = 2;
        }

        else
            horario = 2;

        printf("%s", horario == 1 ? "SIM, HORARIO\n" : horario == 0 ? "SIM, ANTI-HORARIO\n"
                                                                    : "NAO\n");
    }

    return 0;
}
