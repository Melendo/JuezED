
// Autor/a: Nombre y apellidos
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la soluci�n
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include "header.h"
// Introduce m�s librer�as si son necesarias
using namespace std;


// resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
void resuelveCaso() {

    string entrada;
    ListLinkedSingle<char> dest;
    // leer los datos de la entrada

    cin >> entrada;

    ListLinkedSingle<char> ls(entrada);

    // escribir soluci�n

    ls.destripar(dest);
    ls.display();
    dest.display();
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


