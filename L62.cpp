#include <bits/stdc++.h>

#define ii     pair<int, int>
#define vii    vector<ii>
#define vvii   vector<vii>

using namespace std;

void construirMatriz(vvii& red) {
    int M, u, v, w;
    cin >> M;
    while (M--) {
        // u = compu 1, v = compu 2, w = longitud cable
        cin >> u >> v >> w;

        // hacer 0-based
        u--;
        v--;

        // agregar arista
        red[u].push_back(ii(w, v)); // [u]--w-->[v]
        red[v].push_back(ii(w, u)); // [v]--w-->[u]
    }
}

int prim(vvii& red) {
    int r = 0;  // longitud minima de cable

    set<int> visitados;
    priority_queue<ii, vii, greater<ii>> heap;

    // iniciar prim con las aristas del primer nodo
    for (ii arista : red[0]) {
        heap.push(arista);
    }
    visitados.insert(0);        // marcar el primer nodo como visitado

    // prim
    while (!heap.empty()) {
        ii conexion = heap.top();
        heap.pop();

        int longitud = conexion.first;
        int computadora = conexion.second;

        // si esta computadora ha sido visitada anteriormente
        if (visitados.find(computadora) != visitados.end()) {
            continue;       // ignorar esta conexion y continuar con el resto
        }

        visitados.insert(computadora);  // ahora sí está visitada
        r += longitud;

        // meter a sus conexiones a la cola
        for (ii arista : red[computadora]) {
            int destino = arista.second;

            // si el nodo destino no esta visitado
            if (visitados.find(destino) == visitados.end()) {
                heap.push(arista);
            }
        }
    }

    return r;
}

int main() {
    int N;
    cin >> N;

    // Matriz con las conecciones y longitud de cables entre computadoras
    vvii red(N);
    construirMatriz(red);

    /*
    Utilizar el algoritmo de Prim porque las computadoras podrian estar conectadas
    densamente y la red es conexa desde el inicio.
    */
   int r = prim(red);

   cout << r << "\n";
}