// Nombre del alumno ..... Paula Oramas Badillo
// Usuario del Juez ...... F49


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Arbin.h"

using namespace std;


// funcion que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	Arbin<string> a;
	a = a.leerArbol(".");
	tGrupo g = enanos(a);
	// escribir sol
	if (g.n > 0) cout << g.lider << " " << g.n << "\n";
	else cout << "Ninguno\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}