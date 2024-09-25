
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
void resuelveCaso() {

    // variables
    int num, val;
    ListLinkedSingle<int> ls1;
    ListLinkedSingle<int> ls2;


    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> val;
        ls1.push_front(val);
    }
    for (int i = 0; i < num; i++) {
        cin >> val;
        ls2.push_front(val);
    }

    // leer los datos de la entrada
    ls1.repetir(ls2);
    ls1.display();

    // escribir solución
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



