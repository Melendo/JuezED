
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

pair<int, int> resolver(const BinTree<int>& datos) {

    //Caso base
    if (datos.empty()) {
        return { 0, 0 };
    }
    
    //Recursión
    pair<int, int> iz, dr;
    
    iz = resolver(datos.left());
    dr = resolver(datos.right());


    //Calculo
    int ex, eq;

    eq = iz.first + dr.first;
    ex = max(iz.second, dr.second);

    if (datos.root() > 0 && eq == 0) {
        eq++;
    }
   

    return { eq, datos.root() + ex };


}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    BinTree<int> arbol(read_tree<int>(cin));
    
    auto sol = resolver(arbol);

    cout << sol.first << " " << sol.second << "\n";


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


