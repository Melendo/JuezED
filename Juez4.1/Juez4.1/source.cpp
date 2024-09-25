
// Autor/a: Nombre y apellidos
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include "pila.h"

// Introduce más librerías si son necesarias
using namespace std;


bool resolver(const string& cadena) {
    StackLinkedList<char> pila;

    for (int i = 0; i < cadena.length(); i++) {
        if (cadena[i] == '[' || cadena[i] == '{' || cadena[i] == '(') {
            pila.push(cadena[i]);
        }
        else if (cadena[i] == ']' || cadena[i] == '}' || cadena[i] == ')') {
            if (pila.empty()) {
                return false;
            }
            else {
                char aux = ' ';
                if (pila.top() == '[')
                    aux = ']';
                else if (pila.top() == '{')
                    aux = '}';
                else if (pila.top() == '(')
                    aux = ')';

                if (cadena[i] != aux) {
                    return false;
                }
                else {
                    pila.pop();
                }
            }
        }
    }
    if (pila.empty()) {
        return true;

    }
    return false;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    string cadena;
    getline(cin, cadena);

    if (!std::cin)  // fin de la entrada
        return false;

    if (resolver(cadena)) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }

    // escribir sol

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


