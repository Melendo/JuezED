// Nombre del alumno ..... Paula Oramas Badillo
// Usuario del Juez ...... F49


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Arbin.h"

using namespace std;


// funcion que resuelve el problema

pair<int, string> funcioneee(const Arbin<string>& abc){
	int tam;
	string lider;
	pair<int, string> Iz = { 0,"" }, Dr = { 0,"" };
	if (abc.hijoDr().esVacio() && abc.hijoIz().esVacio()) {
		return { 1, abc.raiz() };
	}
	
	if (!abc.hijoDr().esVacio()) {
		Dr = funcioneee(abc.hijoDr());

	}
	if (!abc.hijoIz().esVacio()) {
		Iz = funcioneee(abc.hijoIz());

	}

	tam = Dr.first + Iz.first;

	if (Dr.first < Iz.first) {
		lider = Iz.second;
	}
	else if (Dr.first == Iz.first) {
		lider = min(Dr.second, Iz.second);
	}
	else {
		lider = Dr.second;
	}

	if (abc.raiz() == "Orcos") {
		if (tam == 1) {
			return { 0, "" };
		}
		else {
			tam /= 2;
		}
	}
	return { tam, lider };

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	Arbin<string> a;
	pair<int, string> aba;
	a = a.leerArbol(".");

	// escribir sol

	aba = funcioneee(a);

	if (aba.first == 0) {
		cout << "Ninguno\n";

	}
	else {
		cout << aba.second << " " << aba.first << "\n";
	}


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