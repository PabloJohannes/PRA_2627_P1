#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {

	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE;
	public:
		ListArray() : max(2), MINSIZE(2) {
			
		}

};
