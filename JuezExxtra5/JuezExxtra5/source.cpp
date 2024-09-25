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
#include<xhash>
//Todo O(1) siendo 1 mi numero favoorito
using namespace std;
using platos = string;

class Restaurante {

private:

	struct pairHash {
		size_t operator()(const pair<int, platos>& p) const {
			auto h1 = hash<int>{}(p.first);
			auto h2 = hash<platos>{}(p.second);
			return h1 ^ (h2 << 1);
		}
	};

	unordered_map<int, set<platos>> mesas;

	list<pair<int, platos>> pedidos;

	unordered_map<pair<int, platos>, list<list<pair<int, platos>>::iterator>, pairHash> accesoPedidos;

	


public:

	void nueva_mesa(int num)
	{
		if (mesas.count(num)) {
			throw domain_error("Mesa ocupada");
		}
		mesas.insert({ num, {} });
	}

	void nuevo_pedido(int mesa, const string& plato) 
	{
		if (!mesas.count(mesa)) {
			throw domain_error("Mesa vacia");
		}
		pedidos.push_back({ mesa, plato });
		accesoPedidos[{mesa, plato}].push_back(--pedidos.end());
		mesas.at(mesa).insert(plato);
	}

	void cancelar_pedido(int mesa, const string& plato) {
		if (!mesas.count(mesa)) {
			throw domain_error("Mesa vacia");
		}
		if (!accesoPedidos.count({mesa, plato})) {
			throw domain_error("Producto no pedido por la mesa");
		}
		pedidos.erase(*(--accesoPedidos.at({ mesa, plato }).end()));
		accesoPedidos.at({ mesa,plato }).pop_back();
		if (accesoPedidos.at({ mesa,plato }).empty()) {
			accesoPedidos.erase({ mesa,plato });
			mesas.at(mesa).erase(plato);

		}
	}

	pair<int, string> servir() {
		int mesa;
		platos plato;
		if (pedidos.empty())
		{
			throw domain_error("No hay pedidos pendientes");
		}
		mesa = pedidos.front().first;
		plato = pedidos.front().second;

		accesoPedidos.at({mesa, plato }).pop_front();
		if (accesoPedidos.at({ mesa, plato }).empty()) {
			accesoPedidos.erase({ mesa, plato });
			mesas.at(mesa).erase(plato);
		}
		pedidos.pop_front();

		return { mesa, plato };
	}
	vector<string> que_falta(int mesa) const {
		vector<string> sol;

		for (auto x : mesas.at(mesa)) {
			sol.push_back(x);
		}
		return sol;
	}


};



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada


	Restaurante restaurante;
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

			if (op == "nueva_mesa") {

				int j;
				std::cin >> j;

				restaurante.nueva_mesa(j);
			}

			else if (op == "nuevo_pedido") {

				int s;
				string r;
				std::cin >> s >> r;
				restaurante.nuevo_pedido(s, r);

			}

			else if (op == "cancelar_pedido") {
				int s;
				string r;
				std::cin >> s >> r;

				restaurante.cancelar_pedido(s, r);

			}
			else if (op == "servir") {
				auto res = restaurante.servir();

				cout << res.second << " " << res.first << "\n";
			}
			else if (op == "que_falta") {
				int n;
				cin >> n;
				vector<string> v = restaurante.que_falta(n);
				cout << "En la mesa " << n << " falta:\n";

				for (string el : v) {
					cout <<"  " << el << "\n";
				}
			}
		}
		catch (std::domain_error& e) {

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