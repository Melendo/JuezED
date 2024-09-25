#include <iostream>
#include <fstream>
#include <stack>
#include <deque>
#include <string>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;

deque<string> resolver(const vector<string>& vaccines) {
    deque<string> sol;
    stack<string> acciones;

    if (vaccines.size() == 0) {
        return sol;
    }
    else {
        for (int i = 0; i < vaccines.size(); i++) {
            //Suprimir
            if (vaccines[i] == "*" && sol.size() > 0) {
                acciones.push(sol.back() + "*");
                sol.pop_back();

            }
            //ControlZ
            else if (vaccines[i] == "+" && acciones.size() > 0) {
                if (acciones.top()[acciones.top().length() - 1] == '*') {
                    acciones.top().pop_back();
                    sol.push_back(acciones.top());
                    acciones.pop();
                }
                else {
                    sol.pop_back();
                    acciones.pop();
                }
            }
            //Aniadir palabra
            else if(vaccines[i] != "*" && vaccines[i] != "+") {
                acciones.push(vaccines[i]);
                sol.push_back(vaccines[i]);
            }
        }

    }
    return sol;
}


void resuelveCaso() {

    // leer los datos de la entrada
    string cadena;
    getline(cin, cadena);

    vector<string> acciones;
    int x = 0, i = 0;
    acciones.push_back("");
    while (i < cadena.size()) {
        if (cadena[i] == ' ') {
            x++;
            acciones.push_back("");
        }
        else
            acciones[x] += cadena[i];
        i++;
    }

    deque<string> sol = resolver(acciones);

    while (!sol.empty()) {
        cout << sol.front() << " ";
        sol.pop_front();
    }
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
    cin.ignore();
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta