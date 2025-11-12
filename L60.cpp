#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vi>
#define lli long long int
#define INF 1e18

using namespace std;

int main() {
    int N;
    cin >> N;

    vi x(N), y(N);

    int xi, yi;
    for (int i = 0; i < N; i++) {
        cin >> xi >> yi;

        x[i] = xi;
        y[i] = yi;
    }

    vi minDist(N, INF);
    vector<bool> used(N, false);

    minDist[0] = 0;
    lli total = 0;

    for (int i = 0; i < N; i++) {
        int u = -1;
        lli best = INF;

        // Buscar el nodo no usado con menor distancia al árbol
        for (int j = 0; j < N; ++j) {
            if (!used[j] && minDist[j] < best) {
                best = minDist[j];
                u = j;
            }
        }

        used[u] = true;
        total += best;

        // Actualizar distancias a los nodos no usados
        for (int v = 0; v < N; ++v) {
            if (!used[v]) {
                lli d = llabs(x[u] - x[v]) + llabs(y[u] - y[v]);
                if (d < minDist[v])
                    minDist[v] = d;
            }
        }
    }

    cout << total << "\n";
}