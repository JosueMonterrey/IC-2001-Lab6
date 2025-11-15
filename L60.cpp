#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vi vector<int>          // vi: vector de int
#define vvi vector<vi>          // vvi: vector de vector de int
#define pii pair<int, int>      // pii: pair de int e int
#define arista pair<int, pii>   // arista: <distancia, <coordX, coordY>>
#define cola_prioridad priority_queue<arista, vector<arista>, greater<arista>> // mucho texto


class UnionFind {
    private:
    vi uf;

    public:
    UnionFind(int n) {
        uf = vi(n);

        for (int i = 0; i < n; i++)
            uf[i] = i;
    }

    void Union(int x, int y) {
        int rx = Find(x);
        int ry = Find(y);

        if (rx != ry) {
            uf[ry] = rx;
        }
    }

    int Find(int x) {
        if (uf[x] == x)
            return x;
        
        uf[x] = Find(uf[x]);
        return uf[x];
    }
};

int manhattan(pii c1, pii c2) {
    return abs(c1.first - c2.first) + abs(c1.second - c2.second);
}

void leerCoords(vector<pii>& C) {
    int x, y;
    for (int i = 0; i < C.size(); i++) {
        cin >> x >> y;
        C[i] = pii(x, y);
    }
}

cola_prioridad calcularAristas(vector<pii>& C) {
    cola_prioridad heap;

    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C.size(); j++) {
            if (j >= i)
                break;
                
            int dist = manhattan(C[i], C[j]);
            heap.push(arista(dist, pii(i, j)));
        }
    }

    return heap;
}

ll kruskal(int N, cola_prioridad& heap) {
    ll r = 0;
    UnionFind UF(N);

    while (!heap.empty()) {
        arista a = heap.top(); heap.pop();

        int dist = a.first;
        int x = a.second.first;
        int y = a.second.second;

        if (UF.Find(x) != UF.Find(y)) {
            UF.Union(x, y);
            r += dist;
        }
    }

    return r;
}

int main() {
    int N;
    cin >> N;

    // lista de todos los puntos que necesitan riego
    vector<pii> coords(N);
    leerCoords(coords);

    // cola de prioridad para realizar kruskal
    cola_prioridad heap = calcularAristas(coords);   

    // crear un MST con el algoritmo de kruskal
    int total = kruskal(N, heap);

    cout << total << "\n";
}