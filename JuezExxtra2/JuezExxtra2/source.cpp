
// Autor/a: Nombre y apellidos
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include <list>
#include <stack>

// Introduce más librerías si son necesarias
using namespace std;

// función que resuelve el problema
void resolver(list<int>& lista) {

    stack<int> picha;
    int aux;

    auto it = lista.begin();

    while (it != lista.end()) {
        if (*it > 0) {
            picha.push(*it);
            ++it;
        }
        else if (*it == 0) {
            if (picha.empty()) {
                 it = lista.erase(it);
            }
            else {
                *it = (picha.top() * -1);
                picha.pop();
                it++;
            }
        }
        else {
            if (picha.empty()) {
                it = lista.erase(it);
            }
            else if ((picha.top()*-1) == *it) {
                ++it;
                picha.pop();
            }
            else {
                it = lista.erase(it);
            }
        }

    }
    while (!picha.empty()) {
        lista.push_back((picha.top() * -1));
        picha.pop();
    }



}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    list<int> lista;
    int num, aux;

    cin >> num;

    if (!std::cin)  // fin de la entrada
        return false;
    

    for (int i = 0; i < num; i++) {
        cin >> aux;
        lista.push_back(aux);
    }

    resolver(lista);


    for (auto x : lista) {
        cout << x << " ";
    }
    cout << "\n";

    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("dato.txt");
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


