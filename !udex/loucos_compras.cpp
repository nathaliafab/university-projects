// https://iudex.io/problem/5fb6f4ff8a79af0001d93ec8/statement

#include <bits/stdc++.h>

using namespace std;

void findNumbers(int &R, vector<int> &preco, int precoAtual, int precoMax, unsigned int i, int qtAtual, int qtMin)
{
    if (precoAtual <= precoMax && qtAtual >= qtMin)
        R++;

    else if (precoAtual > precoMax || qtAtual > preco.size())
        return;

    while (i < preco.size() && precoAtual + preco[i] <= precoMax)
    {
        findNumbers(R, preco, precoAtual + preco[i], precoMax, i + 1, qtAtual + 1, qtMin);
        ++i;
    }
}

int combinationSum(int &R, vector<int> &preco, int precoMax, int qtMin)
{
    sort(preco.begin(), preco.end());

    findNumbers(R, preco, 0, precoMax, 0, 0, qtMin);

    return R;
}

int main(void)
{
    int K, L, M, Q, price;
    int counter = 0;

    cin >> K;

    while (K > 0)
    {
        K--;

        cin >> L; // número de itens disponíveis
        vector<int> P;

        for (int j = 0; j < L; j++)
        {
            cin >> price;
            P.push_back(price);
        }

        cin >> M >> Q;
        // M = menor quantidade de itens que se pode escolher
        // Q = quantia máxima que pode ser gasta

        int R = 0;
        R = combinationSum(R, P, Q, M);

        cout << "caso " << counter << ":" << " " << R << endl;
        // R = número total de possíveis maneiras de formar uma compra no valor máximo Q do prêmio,
        // escolhendo-se, no mínimo, M itens sendo, no máximo, uma unidade de cada tipo, dentre os itens disponíveis.

        counter++;
    }

    return 0;
}
