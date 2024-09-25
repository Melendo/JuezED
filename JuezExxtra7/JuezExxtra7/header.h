/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

 /*
  * Implementación del TAD Lista mediante listas enlazadas simples.
  *
  * Esta versión introduce un puntero al último elemento.
  */

#ifndef __LIST_LINKED_SINGLE_H
#define __LIST_LINKED_SINGLE_H

#include <cassert>
#include <iostream>
#include <string>

using namespace std;


template<typename Elem>
class ListLinkedSingle {
private:
	struct Node {
		Elem value;
		Node* next;
	};

public:
	ListLinkedSingle() {
		head = new Node;
		head->next = nullptr;
		last = head;
	}

	ListLinkedSingle(const string& texto) {
		head = new Node;
		head->next = nullptr;
		last = head;

		for (int i = 0; i < texto.length(); i++) {
			this->push_back(texto[i]);
		}
	}

	~ListLinkedSingle() {
		delete_list(head);
	}

	ListLinkedSingle(const ListLinkedSingle& other)
		: head(copy_nodes(other.head)) {
		last = last_node();
	}

	void push_front(const Elem& elem) {
		Node* new_node = new Node{ elem, head->next };
		if (head->next == nullptr) { last = new_node; }
		head->next = new_node;
	}

	void push_back(const Elem& elem);

	void pop_front() {
		assert(head->next != nullptr);
		Node* old_head = head->next;
		head->next = head->next->next;
		if (head->next == nullptr) { last = head; }
		delete old_head;
	}

	void pop_back();

	int size() const;

	bool empty() const {
		return head->next == nullptr;
	};

	const Elem& front() const {
		assert(head->next != nullptr);
		return head->next->value;
	}

	Elem& front() {
		assert(head->next != nullptr);
		return head->next->value;
	}

	const Elem& back() const {
		return last->value;
	}

	Elem& back() {
		return last->value;
	}

	const Elem& operator[](int index) const {
		Node* result_node = nth_node(index);
		assert(result_node != nullptr);
		return result_node->value;
	}

	Elem& operator[](int index) {
		Node* result_node = nth_node(index);
		assert(result_node != nullptr);
		return result_node->value;
	}

	ListLinkedSingle& operator=(const ListLinkedSingle& other) {
		if (this != &other) {
			delete_list(head);
			head = copy_nodes(other.head);
			last = last_node();
		}
		return *this;
	}

	void display(std::ostream& out) const;

	void display() const {
		display(std::cout);
	}

	void detach(Node* ant) {
		ant->next = ant->next->next;
	}

	void attach(Node* n, Node* ant) {
		n->next = ant->next;
		ant->next = n;
	}

	void destripar(ListLinkedSingle& dest) {
		Node* lastChar = nullptr;
		Node* aux = head;
		Node* aux2 = dest.head;

		if (aux->next != nullptr) {
			while (aux->next != nullptr) {
				if (aux->next->value > 47 && aux->next->value < 58 && lastChar == nullptr) {
					Node* curr = aux->next;
					detach(aux);
					dest.attach(curr, aux2);
					aux2 = aux2->next;
					dest.last = curr;
				}
				else if (aux->next->value <= 47 || aux->next->value >= 58) {
					lastChar = aux->next;
					aux = aux->next;
				}
				else if (aux->next->value > 47 && aux->next->value < 58 && lastChar != nullptr) {
					aux = aux->next;

				}

			}
			if (lastChar != nullptr && lastChar->next != nullptr) {
				aux2->next = lastChar->next;
				dest.last = last;
				last = lastChar;
				lastChar->next = nullptr;
			}
		}


	}

private:
	Node* head;
	Node* last;



	void delete_list(Node* start_node);
	Node* last_node() const;
	Node* nth_node(int n) const;
	Node* copy_nodes(Node* start_node) const;

};

template<typename Elem>
typename ListLinkedSingle<Elem>::Node* ListLinkedSingle<Elem>::copy_nodes(Node* start_node) const {
	if (start_node != nullptr) {
		Node* result = new Node{ start_node->value, copy_nodes(start_node->next) };
		return result;
	}
	else {
		return nullptr;
	}
}

template<typename Elem>
void ListLinkedSingle<Elem>::delete_list(Node* start_node) {
	if (start_node != nullptr) {
		delete_list(start_node->next);
		delete start_node;
	}
}

template<typename Elem>
void ListLinkedSingle<Elem>::push_back(const Elem& elem) {
	Node* new_node = new Node{ elem, nullptr };
	last->next = new_node;
	last = new_node;
}

template<typename Elem>
void ListLinkedSingle<Elem>::pop_back() {
	assert(head->next != nullptr);
	Node* previous = head;
	Node* current = head->next;

	while (current->next != nullptr) {
		previous = current;
		current = current->next;
	}

	delete current;
	previous->next = nullptr;
	last = previous;
}

template<typename Elem>
int ListLinkedSingle<Elem>::size() const {
	int num_nodes = 0;

	Node* current = head->next;
	while (current != nullptr) {
		num_nodes++;
		current = current->next;
	}

	return num_nodes;
}

template<typename Elem>
typename ListLinkedSingle<Elem>::Node* ListLinkedSingle<Elem>::last_node() const {
	Node* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	return current;
}

template<typename Elem>
typename ListLinkedSingle<Elem>::Node* ListLinkedSingle<Elem>::nth_node(int n) const {
	assert(0 <= n);
	int current_index = 0;
	Node* current = head->next;

	while (current_index < n && current != nullptr) {
		current_index++;
		current = current->next;
	}

	return current;
}

template<typename Elem>
void ListLinkedSingle<Elem>::display(std::ostream& out) const {
	out << "[";
	if (head->next != nullptr) {
		out << head->next->value;
		Node* current = head->next->next;
		while (current != nullptr) {
			out << ", " << current->value;
			current = current->next;
		}
	}
	out << "]\n";
}


template<typename Elem>
std::ostream& operator<<(std::ostream& out, const ListLinkedSingle<Elem>& l) {
	l.display(out);
	return out;
}

#endif