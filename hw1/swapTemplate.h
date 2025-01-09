/*
* swapTemplateSingleFile.cpp 
* Ty Davis - 1/9/2025
* 
* The header file showing the definition of the swapClass class.
*
*/

// make sure it doesn't recursively define the class
#ifndef SWP_H
#define SWP_H

// The class definition
template <class Type>
class swapClass {
	public:
		void swap12();
		void swap13();
		void swap23();
		Type var1, var2, var3;
	private:
		void swap(Type&, Type&);
};

// include because it is a template class
#include "swapTemplate.cpp"
#endif
