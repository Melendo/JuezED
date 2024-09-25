/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Facultad de Inform�tica
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

 /*
  Introduce aqu� los nombres de los componentes del grupo:

  Componente 1:
  Componente 2:
  */

#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

const int MAX_ELEMS = 2000;


class Multiconjunto {
public:

    // Implementa las operaciones necesarias.
    // No olvides el coste!

private:
    struct Elem {
        int valor;
        int multiplicidad;
    };
    Elem elems[MAX_ELEMS];
    int num_elems;
};


// Funci�n que trata un caso de prueba.
// Devuelve false si se ha le�do el 0 que marca el fin de la entrada,
// o true en caso contrario.
bool tratar_caso() {
    // Implementar

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (tratar_caso()) {}

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // Descomentar en Windows si la consola se cierra inmediatamente
    // system("PAUSE");
#endif
    return 0;
}
