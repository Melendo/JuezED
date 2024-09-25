#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
//
// * Implementacion del TAD Lista mediante listas enlazadas simples.
// *
#include <cassert>
#include <iostream>
#include <string>
#include <assert.h>
class ListLinkedSingle
{
private:
    struct Node
    {
        int value;
        Node* next;
    };

public:
    ListLinkedSingle() : head(nullptr)
    {
    }
    ~ListLinkedSingle()
    {
        delete_list(head);
    }

    ListLinkedSingle(const ListLinkedSingle&
        other) : head(copy_nodes(other.head))
    {
    }

    void push_front(const int& elem)
    {
        Node* new_node = new Node{ elem, head };
        head = new_node;
    }

    void push_back(const int& elem);


    void bubblesort();
    Node* intercambia_hasta(Node* fin);

    void pop_front()
    {
        assert(head != nullptr);
        Node* old_head = head;
        head = head->next;
        delete old_head;
    }

    void pop_back();

    int size() const;

    bool empty() const
    {
        return head == nullptr;
    };

    const int& front() const
    {
        assert(head != nullptr);
        return head->value;
    }

    int& front()
    {
        assert(head != nullptr);
        return head->value;
    }

    int& back() const
    {
        return last_node()->value;
    }

    int& back()
    {
        return last_node()->value;
    }

    const int& at(int index) const
    {
        Node* result_node = nth_node(index);
        assert(result_node != nullptr);
        return result_node->value;
    }

    int& at(int index)
    {
        Node* result_node = nth_node(index);
        assert(result_node != nullptr);
        return result_node->value;
    }

    void display(std::ostream& out) const;
    void display() const
    {
        display(std::cout);
    }

    void dettach(Node* nodo, Node* ant) {
        ant->next = nodo->next;
    }
    void attach(Node* nodo, Node* ant) {
        nodo->next = ant->next;
        ant->next = nodo;
    }

    Node* head;
    int num_elems;
    void delete_list(Node* start_node);
    Node* last_node() const;
    Node* nth_node(int n) const;
    Node* copy_nodes(Node* start_node) const;
};

ListLinkedSingle::Node* ListLinkedSingle::copy_nodes(Node* start_node) const
{
    if (start_node != nullptr)
    {
        Node*
            result = new Node{ start_node->value, copy_nodes(start_node->next) };
        return result;
    }
    else
    {
        return nullptr;
    }
}

void ListLinkedSingle::delete_list(Node* start_node)
{
    if (start_node != nullptr)
    {
        delete_list(start_node->next);
        delete start_node;
    }
}

void ListLinkedSingle::push_back(const int& elem)
{
    Node* new_node = new Node{ elem, nullptr };
    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        last_node()->next = new_node;
    }
}

void ListLinkedSingle::pop_back()
{
    assert(head != nullptr);
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node* previous = head;
        Node* current = head->next;

        while (current->next != nullptr)
        {
            previous = current;
            current = current->next;
        }

        delete current;
        previous->next = nullptr;
    }
}

int ListLinkedSingle::size() const
{
    int num_nodes = 0;

    Node* current = head;
    while (current != nullptr)
    {
        num_nodes++;
        current = current->next;
    }

    return num_nodes;
}

ListLinkedSingle::Node* ListLinkedSingle::last_node() const
{
    assert(head != nullptr);
    Node*
        current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    return current;
}

ListLinkedSingle::Node* ListLinkedSingle::nth_node(int n) const
{
    assert(0 <= n);
    int
        current_index = 0;
    Node*
        current = head;

    while (current_index < n && current != nullptr)
    {
        current_index++;
        current = current->next;
    }

    return current;
}

void ListLinkedSingle::display(std::ostream& out) const
{
    if (head != nullptr)
    {
        out << head->value;
        Node* current = head->next;
        while (current != nullptr)
        {
            out << " " << current->value;
            current = current->next;
        }
    }
    out << "\n";
}

//INDICAR EL COSTE: O(n)  siendo n el numero de
void ListLinkedSingle::bubblesort() {
    Node* fin = nullptr;
    do
    {
        fin = (intercambia_hasta(fin));
    } while (fin != head);
}

//INDICAR EL COSTE.O(n) siendo n el numero de elementos tal que 0<fin<=n
ListLinkedSingle::Node* ListLinkedSingle::intercambia_hasta(ListLinkedSingle::Node* fin) {
    Node* curr = head;
    Node* max = head, * maxAnt = nullptr;

    while (curr->next != fin) {
        if (max->value < curr->next->value) {
            maxAnt = curr;
            max = curr->next;
        }
        curr = curr->next;
    }

    if (max != curr) {
        if (maxAnt == nullptr)
            head = head->next;
        else
            dettach(max, maxAnt);

        attach(max, curr);
    }
    return max;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    int num;
    cin >> num;

    if (num == 0)
        return false;

    ListLinkedSingle l;

    int aux;
    for (int i = 0; i < num; i++) {
        cin >> aux;
        l.push_back(aux);
    }

    l.bubblesort();
    l.display();

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect
#endif

    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

// Nombre del alumno .....
// Usuario del Juez ......
