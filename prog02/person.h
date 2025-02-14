// definition of person class

class personType {
	friend ostream& operator << (ostream&, const personType &);
	
public:
	bool operator>=(const personType&) const;
	bool operator==(const personType&) const;
	
	personType(string first = "", string last = "", int idnum = -1);
	
private:
	string fName;
	string lName;
	int    idNum;
};

