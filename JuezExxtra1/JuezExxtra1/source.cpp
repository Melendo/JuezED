
// Autor/a: Nombre y apellidos
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include "header.h"

// Introduce más librerías si son necesarias
using namespace std;


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int num, aux;
    ListLinkedDouble<int> lista;

    cin >> num;

    if (num == 0)
        return false;

    for (int i = 0; i < num; i++) {
        cin >> aux;
        lista.push_back(aux);
    }

    // escribir sol
    lista.stalinSort();
    lista.display();

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


