
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
    int num, val;
    ListLinkedSingle<int> lista1;
    ListLinkedSingle<int> lista2;

    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> val;
        lista1.push_back(val);
    }

    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> val;
        lista2.push_back(val);
    }
    // escribir solución

    lista1.intersect(lista2);
    lista1.display();
    cout << "\n";

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
