
// Autor/a: Nombre y apellidos
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include <deque>
#include <stack>
// Introduce más librerías si son necesarias
using namespace std;

deque<int> resolver(deque<int> &datos) {
    deque<int> sol;
    stack<int> aux;
  
    bool found;
    while (!datos.empty()) {
        found = false;
        while (!aux.empty() && !found) {
            if (aux.top() > datos.front()) {
                sol.push_back(aux.top());
                found = true;
            }
            else 
                aux.pop();
            
        }
        if (aux.empty()) 
            sol.push_back(-1);

        aux.push(datos.front());
        datos.pop_front();       
    }
    return sol;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int x;
    deque<int> datos;
    cin >> x;
    if (x == -1)  // fin de la entrada
        return false;
    while (x != -1) {
        datos.push_back(x);
        cin >> x;
    }
    deque<int> sol = resolver(datos);
    while (!sol.empty()) {
        if(sol.front() == -1)
            cout << "NO HAY\n";
        else
            cout << sol.front() << "\n";
        sol.pop_front();
    }
    cout << "---\n";
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


