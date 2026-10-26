#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {

	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;
	

		void resize(int new_size) {
			T* newArr = new T[new_size];
			for(int i=0;i<n;i++){
				newArr[i] = arr[i];
			}
			delete[] arr;
			arr = newArr;
			max = new_size;
		}

	public:
		ListArray() {
			max = MINSIZE;
			n = 0;
			arr = new T[MINSIZE];
		}
		
		~ListArray() override {
			delete[] arr;
		}

		bool empty() override {
			return n == 0;
		}

		int size() override {
			return n;
		}

		T get(int pos) override {
			if(pos>=n || pos < 0){
				throw std::out_of_range("fuera de rango");
			}
			return arr[pos];
		}

		T remove(int pos) override {
			T aux = get(pos);
			for(int i = pos; i < (n-1); i++){
				arr[i] = arr[i+1];
			}
			n--;
			if(n<(max/2)){
				resize(n+2);
			}
			return aux;
		}

		void insert(int pos, T e) override {
			if(pos>n || pos < 0){
				throw std::out_of_range("fuera de rango");
			}
			if((n+1) >= max){
				resize((2*max));
			}
			for(int i=(n-1); i>=pos; i--){
				arr[i+1] = arr[i];
			}
			arr[pos] = e;
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
			while(c<n){
				if(arr[c]==e){
				return c;
				}
				c++;
			}
			return -1;
		}

		T operator[](int pos) {
			return get(pos);
		}

		friend std::ostream& operator<<(std::ostream &out, ListArray<T> &list);
};

		template <typename T>
		std::ostream& operator<<(std::ostream &out, ListArray<T> &list) {
			out << "List => [";
			for(int i=0;i<list.n;i++){
				out << "\n  " << list.arr[i];
			}
			if(list.n!=0){
				out << "\n";
			}
			out << "]";
			return out;
		}
