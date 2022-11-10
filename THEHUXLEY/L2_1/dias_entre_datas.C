// https://www.thehuxley.com/problem/46

#include <stdio.h>

int main()
{
    int diaI, mesI, anoI, diaF, mesF, anoF;
    int diasTemp = 0, i, qtDias = 0;

    scanf("%d/%d/%d %d/%d/%d", &diaI, &mesI, &anoI, &diaF, &mesF, &anoF);

    if (anoI <= anoF)
    {
        for (i = anoI; i < anoF; i++)
        {
            if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0 && i % 100 == 0))
                qtDias += 366;
            else
                qtDias += 365;
        }
    }

    else
    {
        for (i = anoF; i < anoI; i++)
        {
            if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0 && i % 100 == 0))
                qtDias -= 366;
            else
                qtDias -= 365;
        }
    }

    for (i = 1; i < mesI; i++)
    {
        switch (i)
        {
        case 2:
            if ((anoI % 4 == 0 && anoI % 100 != 0) || (anoI % 400 == 0 && anoI % 100 == 0))
                diasTemp = 29;
            else
                diasTemp = 28;
            break;
        case 4:
            diasTemp = 30;
            break;
        case 6:
            diasTemp = 30;
            break;
        case 9:
            diasTemp = 30;
            break;
        case 11:
            diasTemp = 30;
            break;
        default:
            diasTemp = 31;
            break;
        }

        diaI += diasTemp;
    }

    for (i = 1; i < mesF; i++)
    {
        switch (i)
        {
        case 2:
            if ((anoF % 4 == 0 && anoF % 100 != 0) || (anoF % 400 == 0 && anoF % 100 == 0))
                diasTemp = 29;
            else
                diasTemp = 28;
            break;
        case 4:
            diasTemp = 30;
            break;
        case 6:
            diasTemp = 30;
            break;
        case 9:
            diasTemp = 30;
            break;
        case 11:
            diasTemp = 30;
            break;
        default:
            diasTemp = 31;
            break;
        }

        diaF += diasTemp;
    }

    qtDias += diaF - diaI;

    printf("%d", qtDias);

    return 0;
}
