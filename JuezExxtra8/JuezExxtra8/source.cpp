
// Autor/a: Nombre y apellidos
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la solución
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
// Introduce más librerías si son necesarias
#include <vector>
#include <cmath>
#include "header.h"
using namespace std;


int recursion(const vector<BinTree<int>>& aux, int max_padre) {
	int max_nivel = 0;
	int res = 0;

	if (!aux.empty()) {
		vector<BinTree<int>> hijos;
		for (int i = 0; i < (int)aux.size(); i++) {
			if (!aux[i].left().empty()) {
				hijos.push_back(aux[i].left());
				max_nivel = max(max_nivel, aux[i].left().root());
			}
			if (!aux[i].right().empty()) {
				hijos.push_back(aux[i].right());
				max_nivel = max(max_nivel, aux[i].right().root());
			}
		}
		if (!hijos.empty())
			res = recursion(hijos, max_nivel);

		if (max_nivel > max_padre) res++;
	}

	return res;
}
// función que resuelve el problema
int num_aventajados(const BinTree<int>& tree) {

	if (tree.empty()) return 0;

	return recursion({ tree }, tree.root());
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	// leer los datos de la entrada
	BinTree<int> a = read_tree<int>(cin);
	// escribir solución
	cout << num_aventajados(a) << "\n";
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

