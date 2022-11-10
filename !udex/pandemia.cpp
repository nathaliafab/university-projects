// https://iudex.io/problem/605cbe1b51aa87000155c826/statement

#include <iostream>

using namespace std;

class Hospital
{
public:
    int casos;
    int indice;
    Hospital(int n, int i)
    {
        casos = n;
        indice = i;
    }
};

Hospital **bubble_up(Hospital **hospital, int p)
{
    int i = p;
    while (i > 0 && hospital[i]->casos >= hospital[(i - 1) / 2]->casos)
    {
        swap(hospital[i], hospital[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    return hospital;
}

Hospital **heap_insert(Hospital **hospital, int C, int H, int N)
{
    Hospital *temp = new Hospital(C, H);
    hospital[N - 1] = temp;
    bubble_up(hospital, N - 1);
    return hospital;
}

void bubble_down(Hospital **hospital, int p, int N)
{
    int l = 2 * p + 1, r = 2 * p + 2, m = p;
    if (l < N && (hospital[l]->casos > hospital[m]->casos || (hospital[l]->casos == hospital[m]->casos && hospital[l]->indice > hospital[m]->indice)))
        m = l;

    if (r < N && (hospital[r]->casos > hospital[m]->casos || (hospital[r]->casos == hospital[m]->casos && hospital[r]->indice > hospital[m]->indice)))
        m = r;

    if (m != p)
    {
        swap(hospital[m], hospital[p]);
        bubble_down(hospital, m, N);
    }
}

void build_heap(Hospital **hospital, int N)
{
    for (int i = (N / 2) - 1; i >= 0; i--)
        bubble_down(hospital, i, N);
}

void heap_extract(Hospital **hospital, int i, int N)
{
    swap(hospital[i], hospital[N - 1]);
    N--;
    bubble_down(hospital, i, N);
}

Hospital **updateID(Hospital **hospital, int N, int H)
{
    Hospital **hospitalByID = new Hospital *[H];

    for (int i = 0; i < H; i++)
        hospitalByID[i] = NULL;

    for (int i = 0; i < N; i++)
        hospitalByID[hospital[i]->indice] = hospital[i];

    return hospitalByID;
}

int main(void)
{
    int i, N, H, C, R, casosTotal = 0;
    string evento;

    cin >> N;
    Hospital **hospital = new Hospital *[N];
    Hospital **hospitalByID = NULL;

    for (i = 0; i < N; i++)
    {
        cin >> C;
        Hospital *temp = new Hospital(C, i);
        hospital[i] = temp;
        casosTotal += hospital[i]->casos;
    }

    build_heap(hospital, N);
    hospitalByID = updateID(hospital, N, N);

    do
    {
        cin >> evento;
        // NEW H C: cadastra de um um novo hospital com id H (sequencial) e C casos iniciais
        if (evento == "NEW")
        {
            cin >> H >> C;
            int novaCapacidade = N + 1;
            casosTotal += C;

            Hospital **novoHospital = new Hospital *[novaCapacidade];
            for (i = 0; i < N; i++)
                novoHospital[i] = hospital[i];

            heap_insert(novoHospital, C, H, novaCapacidade);
            delete[] hospital;
            hospital = novoHospital;
            N = novaCapacidade;

            cout << hospital[0]->indice << " " << hospital[0]->casos << endl;

            hospitalByID = updateID(hospital, N, H + 1);
        }

        // DEL H: remove o hospital com id H
        else if (evento == "DEL")
        {
            cin >> H;

            for (i = 0; i < N; i++)
            {
                if (hospital[i]->indice == H)
                {
                    casosTotal -= hospital[i]->casos;
                    if (casosTotal < 0)
                        casosTotal = 0;

                    heap_extract(hospital, i, N);
                    N--;
                    break;
                }
            }

            if (N <= 0)
                cout << -1 << " " << -1 << endl;

            else
                cout << hospital[0]->indice << " " << hospital[0]->casos << endl;
        }

        // IN H C: incrementa o número de casos do hospital H em C unidades
        else if (evento == "IN")
        {
            cin >> H >> C;

            hospitalByID[H]->casos += C;
            casosTotal += C;

            cout << hospitalByID[H]->casos << endl;
            build_heap(hospital, N);
        }

        // OUT H C: decrementa o número de casos do hospital H em C unidades
        else if (evento == "OUT")
        {
            cin >> H >> C;

            hospitalByID[H]->casos -= C;
            if (hospitalByID[H]->casos < 0)
                hospitalByID[H]->casos = 0;

            casosTotal -= C;
            if (casosTotal < 0)
                casosTotal = 0;

            cout << hospitalByID[H]->casos << endl;
            build_heap(hospital, N);
        }

        // PAY R: dispara uma rodada de distribuição de uma quantidade total R em recursos para os hospitais
        else if (evento == "PAY")
        {
            cin >> R;
            int P = R;
            if (casosTotal <= R)
            {
                for (i = 0; i < N; i++)
                    hospital[i]->casos = 0;

                R = casosTotal;
                casosTotal = 0;
            }

            else
            {
                while (R > 0)
                {
                    hospital[0]->casos--;
                    if (hospital[0]->casos < 0)
                        hospital[0]->casos = 0;
                    casosTotal--;
                    R--;
                    build_heap(hospital, N);
                }
            }

            cout << P - R << endl;
        }
    } while (evento != "END");

    cout << casosTotal << endl;

    return 0;
}
