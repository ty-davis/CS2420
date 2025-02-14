#include <iostream>
#include <iomanip>
#include <string>


using namespace std;
#include "person.h"
// Thiis file implements the methods for person type

// overload comparison for sorting by sortedListADT
bool personType::operator>=(const personType & otherPerson) const {
	bool retval = false;
	
	if (this->lName.compare(otherPerson.lName) > 0)
		retval = true;
	else if (this->lName == otherPerson.lName)
		retval = (this->fName.compare(otherPerson.fName) >= 0);
	return retval;
}

// overload comparison for search
bool personType::operator==(const personType & otherPerson) const {
	bool equal = true;
	
	if (otherPerson.lName != this->lName) {
		equal = false;
	} else if (otherPerson.fName != this->fName) {
		equal = false;
	} else if (otherPerson.idNum != this->idNum) {
		equal = false;
	}
	return equal;
}

personType::personType(string first, string last, int idnum){
	fName = first;
	lName = last;
	idNum = idnum;
}

// Overloaded output stream to disply personType
ostream& operator<< (ostream& theStream, const personType& thePerson) {
	theStream << "First: " << setw(20) << thePerson.fName 
				<< "  Last: " << setw(20) << thePerson.lName 
				<< "  ID#: " << thePerson.idNum;
	return theStream;
}
 
