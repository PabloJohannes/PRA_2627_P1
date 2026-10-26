#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
		Node<T>* first;
		int n;

    public:
		ListLinked() : first(nullptr), n(0) {}
        
		~ListLinked() {
			while(first != nullptr){
				Node<T>* aux = first->next;
				delete first;
				first = aux;
			}
		}

		bool empty() override {
			return n == 0;
		}

		int size() override {
			return n;
		}

		T get(int pos) override {
			if(pos>=n || pos < 0){
				throw std::out_of_range("Posición inválida!");
			}
			Node<T>* aux = first;
			for(int i=0; i<pos; i++){
				aux = aux->next;
			}
			return aux->data;
		}
		T remove(int pos) override {
			T aux = get(pos);
			Node<T>* aux2 = first->next;
			if(pos==0){
				delete first;
				first = aux2;
			}else{
				Node<T>* aux3 = first;
				for(int i=1;i<pos;i++){
					aux3 = aux2;
					aux2 = aux2->next;
				}
				aux3->next = aux2->next;
				delete aux2;
			}
			n--;
			return aux;
		}

		void insert(int pos, T e) override {
			if(pos>n || pos < 0){
				throw std::out_of_range("Posición inválida!");
			}
			if(pos==0){
				first = new Node(e,first);
			}else{
				Node<T>* aux = first;
				for(int i=1; i<pos; i++){
					aux=aux->next;
				}
				aux->next = new Node(e,aux->next);
			}
			n++;
		}

		void append(T e) override {
			insert(n,e);
		}

		void prepend(T e) override {
			insert(0,e);
		}

		int search(T e) override {
			int c = 0;
			Node<T>* aux = first;
			while(c<n){
				if(aux->data==e){
				return c;
				}
				aux = aux->next;
				c++;
			}
			return -1;
		}

		T operator[](int pos) {
			return get(pos);
		}

		friend std::ostream& operator<<(std::ostream &out, ListLinked &list) { //no lo pongo por	ue en el ejercicio no lo pone, pero en realidad es puena idea poner "const" antes de el parámetro de ListLinked
			out << "List => [";
			if(list.n!=0){
				Node<T>* aux = list.first;
				for(int i=0; i<list.n; i++){
					out << "\n  " << aux->data;
					aux = aux->next;
				}
				out << "\n";
			}
			out << "]";
			return out;
		}
};

#endif //LIST_LINKED_H
