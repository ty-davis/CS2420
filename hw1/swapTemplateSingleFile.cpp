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

template <class Type>
void printSwapClass(const swapClass<Type>& obj) {
	std::cout << "Var 1: " << obj.var1 << '\n';
	std::cout << "Var 2: " << obj.var2 << '\n';
	std::cout << "Var 3: " << obj.var3 << '\n';
}

template <class Type>
void testSwapClass(swapClass<Type>& obj) {
	Type orig1 = obj.var1;
	Type orig2 = obj.var2;
	Type orig3 = obj.var3;
	bool success = true;

	std::cout << "Before swap:\n";
	printSwapClass(obj);

	std::cout <<  " -- Swap 1 & 2 -- \n";
	obj.swap12();
	success &= (orig1 == obj.var2 && orig2 == obj.var1 && orig3 == obj.var3);
	// printSwapClass(obj);

	std::cout <<  " -- Swap 1 & 3 -- \n";
	obj.swap13();
	success &= (orig1 == obj.var2 && orig2 == obj.var3 && orig3 == obj.var1);
	// printSwapClass(obj);

	std::cout <<  " -- Swap 2 & 3 -- \n";
	obj.swap23();
	success &= (orig1 == obj.var3 && orig2 == obj.var2 && orig3 == obj.var1);
	// printSwapClass(obj);
	
	std::cout << "Result:\n";
	printSwapClass(obj);
	
	if (success) {
		std::cout << "Passed";
	} else {
		std::cout << "FAILED";
	}
}

// Testing to make sure it runs
int main(void) {
	// Test with integers
	swapClass<int> swapInts;
	swapInts.var1 = 3;
	swapInts.var2 = 5;
	swapInts.var3 = -103202;
	testSwapClass(swapInts);

	// Test with strings
	swapClass<std::string> swapStrs;
	swapStrs.var1 = "Windows";
	swapStrs.var2 = "MacOS";
	swapStrs.var3 = "Linux";
	testSwapClass(swapStrs);
}
