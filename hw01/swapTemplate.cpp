/*
* swapTemplate.cpp 
* Ty Davis - 1/9/2025
* 
* The implemenation of the methods of the class declared in
* swapTemplate.h.
*
*/

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
