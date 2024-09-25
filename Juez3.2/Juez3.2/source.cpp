
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
    int piv, num, val;
    ListLinkedDouble<int> ls;

    cin >> num;

   

    if (!std::cin)  // fin de la entrada
        return false;

    cin >> piv;

    for (int i = 0; i < num; i++) {
        cin >> val;
        ls.push_back(val);
    }

    ls.particion(piv);
    ls.display();

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



