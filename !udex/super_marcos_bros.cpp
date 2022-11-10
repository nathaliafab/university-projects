// https://iudex.io/problem/5dc181eb71f25900013e00a3/statement

#include <bits/stdc++.h>

using namespace std;

class Objeto
{
public:
    int x;
    int y;
    bool coin = false;

    Objeto(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
}

void bellman_ford(vector<pair<int, int>> adj[], int n, int s)
{
    vector<int> D(n, INT_MAX);
    vector<int> Dtemp(n);
    vector<int> F(n, -1);

    int v;
    double w;

    D[s] = 0;

    Dtemp = D;

    for (int k = 1; k <= n; k++)
    {
        D = Dtemp;
        for (int u = 0; u < n; u++)
        {
            for (auto it = adj[u].begin(); it != adj[u].end(); it++)
            {
                v = it->first;
                w = it->second;

                if (Dtemp[u] != INT_MAX && Dtemp[u] + w < D[v])
                {
                    D[v] = Dtemp[u] + w;
                    F[v] = u;
                }
            }
        }
        Dtemp = D;
    }

    for (int u = 0; u < n; u++)
    {
        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;

            if (Dtemp[u] != INT_MAX && Dtemp[u] + w < Dtemp[v])
            {
                cout << "LOOP" << endl;
                return;
            }
        }
    }

    cout << D[n - 1];

    int current = n - 1;
    vector<int> path;

    while (current != -1)
    {
        path.push_back(current);
        current = F[current];
    }

    for (auto it = path.rbegin(); it != path.rend(); it++)
        cout << " " << *it;

    cout << endl;

    F.clear();
    D.clear();
    path.clear();
}

int main(void)
{
    int T, N, M, x, y, index, D;
    vector<Objeto> pontos;

    cin >> T; // qt. de casos teste
    while (T > 0)
    {
        T--;

        cin >> N; // qt. de pontos na fase
        vector<pair<int, int>> adj[N];

        for (int i = 0; i < N; i++)
        {
            cin >> x >> y;
            Objeto *ponto = new Objeto(x, y);
            pontos.push_back(*ponto);
        }

        cin >> M; // qt. de moedas
        for (int i = 0; i < M; i++)
        {
            cin >> index;
            pontos[index].coin = true;
        }

        // ponto alcançáveis
        for (int i = 0; i < N; i++)
        {
            cin >> D;
            for (int j = 0; j < D; j++)
            {
                cin >> index;
                int gasto = pow(pontos[index].x - pontos[i].x, 2) + pow(pontos[index].y - pontos[i].y, 2);

                if (pontos[index].coin)
                    gasto = -gasto;

                addEdge(adj, i, index, gasto);
            }
        }

        bellman_ford(adj, N, 0);

        pontos.clear();
    }

    return 0;
}
