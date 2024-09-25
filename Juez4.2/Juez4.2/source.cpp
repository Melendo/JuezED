
// Autor/a: Nombre y apellidos
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
// Introduce más librerías si son necesarias
#include "queue.h"
using namespace std;

void resuelveCaso() {

    // leer los datos de la entrada
    QueueLinkedList<int> cola;
    QueueLinkedList<int> colegas;
    int pringao, aux;

    //lectura cola
    cin >> aux;
    while (aux != -1) {
        cola.push(aux);
        cin >> aux;
    }

    //lectura pringao
    cin >> pringao;

    //lectura colegas
    cin >> aux;
    while (aux != -1) {
        colegas.push(aux);
        cin >> aux;
    }

    cola.display();
    cola.colarse(colegas, pringao);
    cola.display();

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


