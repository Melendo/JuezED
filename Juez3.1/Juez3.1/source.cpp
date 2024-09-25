
// Autor/a: Nombre y apellidos
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include "lista.h"
// Introduce más librerías si son necesarias
using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, i, m, val;
    ListLinkedDouble<int> lista;
    cin >> N >> i >> m;

    if (N== 0 && i == 0 && m == 0)
        return false;

    for (int x = 0; x < N; x++) {
        cin >> val;
        lista.push_back(val);
    }

    // escribir sol

    lista.add_to(i, m);
    lista.display();
    std::cout << "\n";

    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}



