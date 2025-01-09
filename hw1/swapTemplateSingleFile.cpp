/*
* swapTemplateSingleFile.cpp 
* Ty Davis - 1/9/2025
* 
* Single file containing the declaration of the swapClass, and
* the implementation of all of the methods.
*
*/

#include <iostream>

// The class definition
template <class Type>
class swapClass {
public:
	void swap12(void);
	void swap13(void);
	void swap23(void);
	Type var1, var2, var3;
private:
	void swap(Type&, Type&);
};

// swapping 1 and 2
template <class Type>
void swapClass<Type>::swap12() {
	swap(var1, var2);
}

// swapping 1 and 3
template <class Type>
void swapClass<Type>::swap13() {
	swap(var1, var3);
}

// swapping 2 and 3
template <class Type>
void swapClass<Type>::swap23() {
	swap(var2, var3);
}

// The swap function
template <class Type>
void swapClass<Type>::swap(Type& first, Type& second) {
	Type temp = second;
	second = first;
	first = temp;
}

// Testing to make sure it runs
int main(void) {
	swapClass<int> swapInts;
	swapInts.var1 = 3;
	swapInts.var2 = 5;

	swapInts.swap12();
	printf("%d\n", swapInts.var1);
}
