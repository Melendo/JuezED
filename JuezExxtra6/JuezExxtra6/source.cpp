#include <stdio.h>

#include<fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_map> 
#include <list> 
#include<vector>
#include <map>
#include<set>
#include<unordered_set>
#include<cmath>
#include <iterator>
#include <exception>¡

using namespace std;

using artista = string;
using obra = string;

class GaleriaArte {

private:

	struct infoObra {
		list<obra>::iterator posObra;
		artista artista;
		int precio;
	};

	list<obra> galeria;
	unordered_map<obra, infoObra> obras;
	map<int, set<artista>> top_ventas;
	unordered_map<artista, int> ventas_artista;

public:

	void nueva_obra(obra c, artista a, int p)//O(1) siendo 1 mi numero favorito
	{
		if (obras.count(c)) {
			throw invalid_argument("Obra ya en la galeria");
		}
		infoObra olaquease;
		galeria.push_back(c);
		olaquease = { --galeria.end(), a, p };
		
		obras.insert({ c, olaquease});
		if (!ventas_artista.count(a)) {
			ventas_artista.insert({ a, 0 });

		}
	}

	void venta_obra(obra c) {//O(log(n) + log(x)) siendo n el úmero de elementos del mapa top_ventas + siendo x en num de elementos del set de top_ventas
		if (!obras.count(c)) {
			throw invalid_argument("Obra no existente");
		}
		else {
			infoObra aux = obras.at(c);
			galeria.erase(aux.posObra);
			ventas_artista.at(aux.artista) += aux.precio;
			obras.erase(c);

			if (top_ventas.empty() || ventas_artista.at(aux.artista) >= (--top_ventas.end())->first) {
				top_ventas[ventas_artista.at(aux.artista)].insert(aux.artista);
			}
		}

	}


	vector<string> mas_vendidos() const { //O(n) siendo n el numero de artistas del set de la ultima posicion de top_ventas
		vector<artista> sol;
		if (!top_ventas.empty()) {
			for (auto x : (--top_ventas.end())->second) {
				sol.push_back(x);
			}
		}
		return sol;

	}

	vector<string> obras_por_antiguedad(int k) const {//O(n) siendo n el mínimo entre k y el size de galeria
		vector<obra> sol;
		auto it = galeria.begin();
		for (int i = 0; i < min(k, (int)galeria.size()); i++) {
			sol.push_back(*it);
			it++;
		}
		return sol;
	}


};



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada


	GaleriaArte ga;
	std::string op;
	std::cin >> op;
	if (!std::cin)
		return false;
	if (op == "FIN") {
		std::cout << "---\n";
		return true;
	}
	while (op != "FIN") {

		try {

			if (op == "nueva_obra") {

				string c, a;
				int p;
				std::cin >> c >> a >> p;

				ga.nueva_obra(c, a, p);
			}

			else if (op == "venta_obra") {

				string c;
				std::cin >> c;
				ga.venta_obra(c);

			}

			else if (op == "mas_vendidos") {

				vector<string> res;
				res = ga.mas_vendidos();
				cout << "Los artistas que mas han vendido son:\n";
				for (auto x : res) {
					cout << x << "\n";
				}
			}
			else if (op == "obras_por_antiguedad") {
				int k;
				cin >> k;
				vector<string> res = ga.obras_por_antiguedad(k);

				cout << "Obras mas antiguas en la galeria:\n";
				for (int i = 0; i < res.size(); i++) {
					cout << res[i] << "\n";
				}
			}

		}
		catch (std::invalid_argument& e) {

			std::cout << "ERROR: " << e.what() << "\n";
		}

		std::cin >> op;

	}

	std::cout << "---\n";

	return true;

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

#endif
	while (resuelveCaso());//Resolvemos todos los casos
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
}