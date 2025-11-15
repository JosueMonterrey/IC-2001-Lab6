#include <bits/stdc++.h>

#define vd vector<double>
#define vvd vector<vd>

using namespace std;

void leerTasas(int N, vvd& W) {
    double tasa;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> tasa;
            W[i][j] = -log(tasa);     // W[i][j] = -log(M[i][j])
        }
    }
}

void floydWarshall(int N, vvd& W) {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
            }
        }
    }
}

bool hayCicloNegativo(int N, vvd& W) {
    const double EPS = -1e-9;
    for (int i = 0; i < N; i++) {
        if (W[i][i] < EPS)
            return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;

    vvd W(N, vd(N));     // matriz N*N

    leerTasas(N, W);        // leer las tasas de cambio y aplicar transformacion -log(M[i][j])

    floydWarshall(N, W);

    bool hayCicloArbitraje = hayCicloNegativo(N, W);

    if (hayCicloArbitraje)
        cout << "YES\n";
    else
        cout << "NO\n";
}