#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vi>
#define nodo pair<int, vi>

using namespace std;

struct Nodo {
    int costo;
    vi contenedores;

    Nodo (int costo, vi contenedores) {
        this->costo = costo;
        this->contenedores = contenedores;
    }
};

int main() {
    vi pesos(8); // el peso del i-esimo contenedor

    // leer pesos
    int p;
    for (int i = 0; i < 8; i++) {
        cin >> p;
        pesos[i] = p;
    }

    vi inicio(8);
    vi objetivo(8);
    // leer configuracion esperada
    char c;
    for (int i = 0; i < 8; i++) {
        cin >> c;
        objetivo[i] = c - 'A';  // A=0, B=1, C=2, ..., H=7
        inicio[i] = i;
    }

    /*
        Los posibles movimientos de cada contenedor segun su posicion
        A0 B1 C2 D3
        E4 F5 G6 H7
    */
    vvi posibles = {
        {1, 2, 3, 4},
        {0, 2, 3, 5},
        {0, 1, 3, 6},
        {0, 1, 2, 7},
        {0},
        {1},
        {2},
        {3}
    };

    // cola de prioridad con todos los nodos del grafo para hacer dijkstra
    priority_queue<nodo, vector<nodo>, greater<nodo>> heap;

    // almacenar todas las permutaciones generadas y el costo minimo actual para llegar a ellas
    map<vi, int> generadas = map<vi, int>();

    nodo nodoInicial(0, inicio);
    heap.push(nodoInicial);

    while (!heap.empty()) {
        nodo nodoActual = heap.top(); heap.pop();

        int costoActual = nodoActual.first;
        vi permActual = nodoActual.second;

        if (permActual == objetivo) {
            cout << costoActual << "\n";
            return 0;                       // terminar programa si llegamos la solucion
        }

        // generar permutaciones
        for (int i = 0; i < 8; i++) {
            for (int j : posibles[i]) {
                if (i >= j)
                    continue;   // no repetir permutaciones
                
                // realizar un movimiento y calcular su costo
                vi permNueva = permActual;
                swap(permNueva[i], permNueva[j]);
                int costoNuevo = costoActual + pesos[permNueva[i]] + pesos[permNueva[j]];

                // si la nueva configuracion es mas optima comparada con las generadas previamente
                if (!generadas.count(permNueva) || generadas[permNueva] > costoNuevo) {
                    // actualizar permutacion mas optima
                    generadas[permNueva] = costoNuevo;

                    // actualizar heap
                    nodo nodoNuevo(costoNuevo, permNueva);
                    heap.push(nodoNuevo);
                }
            }
        }
    }

    cout << "No hay camino.\n";
    return 0;
}