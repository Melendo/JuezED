
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



void resuelveCaso() {

    // leer los datos de la entrada
    int val;
    ListLinkedSingle<int> lista1;
    ListLinkedSingle<int> lista2;

    cin >> val;
    while (val != 0) {
        lista1.push_back(val);
        cin >> val;
    }

    cin >> val;
    while (val != 0) {
        lista2.push_back(val);
        cin >> val;
    }
    // escribir solución
    lista1.mezclar(lista2);
    lista1.display();
    std::cout << "\n";
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}

