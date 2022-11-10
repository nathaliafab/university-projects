// https://www.thehuxley.com/problem/1113

#include <stdio.h>

int main()
{
    int dia, mes, ano, qtDias;

    scanf("%d %d %d", &dia, &mes, &ano);

    switch (mes)
    {
    case 1:
        qtDias = 31;
        break;

    case 2:
        if (ano % 100 == 0 && ano % 400 == 0)
            qtDias = 29;

        else
            qtDias = 28;
        break;

    case 3:
        qtDias = 31;
        break;

    case 4:
        qtDias = 30;
        break;

    case 5:
        qtDias = 31;
        break;

    case 6:
        qtDias = 30;
        break;

    case 7:
        qtDias = 31;
        break;

    case 8:
        qtDias = 31;
        break;

    case 9:
        qtDias = 30;
        break;

    case 10:
        qtDias = 31;
        break;

    case 11:
        qtDias = 30;
        break;

    default:
        qtDias = 31;
    }

    if ((dia >= 1 && dia <= qtDias) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100))
        printf("valida");
    else
        printf("invalida");

    return 0;
}
