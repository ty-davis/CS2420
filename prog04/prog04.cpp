/* 
 * prog04.cpp
 * Ty Davis 3/18/2025
 * 
 * Program that prompts the user for a file containing
 * any number of random integers. Displays some of those integers
 * and then sorts them while measuring the amount of time
 * taken. Implements both bubble sort and quick sort.
 * 
 */

#include <ctime>    // timing stuff
#include <iostream> // i/o streams
#include <fstream>  // file i/o
#include <vector>   // resizeable arrays

using namespace std;   // don't want to type std:: a billion times

/* print the first few and last few of the vector to show that it is sorted */
void printFirstLast(int amount, vector<int> vec) {
	int vecSize = vec.size();
	int i;
	if (vecSize < amount * 2) {
		cout << "Entire array:\n";

		for (i=0; i < vecSize; i++) {
			cout << vec.at(i) << "\n";
		}
		return;
	}

	cout << "First " << amount << " numbers:\n";
	for (i=0; i < amount; i++) {
		cout << vec.at(i) << "\n";
	}

	cout << "Last " << amount << " numbers:\n";
	for (i=vecSize-amount; i < vecSize; i++) {
		cout << vec.at(i) << "\n";
	}
}

void bubbleSort(vector<int>& vec) {
	int i, j; // for iteration
	int temp;

	for (i=0; i<vec.size(); i++) {
		bool didSwap = false;
		for (j=vec.size()-1; j > i; j--) {
			if (vec.at(j) < vec.at(i)) {
				temp = vec.at(j);       // swap vec[i] and vec[j]
				vec.at(j) = vec.at(i);
				vec.at(i) = temp;
				didSwap = true;
			}
		}
		if (!didSwap) {
			break;
		}
	}
}

int partition(vector<int>& vec, int p, int r) {
	int x = vec.at(r);
	int i = p - 1;
	int temp;
	for (int j = p; j < r; j++) {
		if (vec.at(j) <= x) {
			i ++;
			temp = vec.at(j); // swap vec[i] and vec[j]
			vec.at(j) = vec.at(i);
			vec.at(i) = temp;
		}
	}
	temp = vec.at(i+1); // swap vec[i+1] and vec[r]
	vec.at(i+1) = vec.at(r);
	vec.at(r) = temp;
	return i + 1;
}

void quickSort(vector<int>& vec, int p, int r) {
	int q;
	if (p < r) {
		q = partition(vec, p, r);	
		quickSort(vec, p, q-1);
		quickSort(vec, q+1, r);
	}	
}


int main() {
	string filename = "";
	string inputStr = "";
	ifstream inFile;    // input text file
	

	/* reading the file */
	cout << "Please enter the name of the data file.\n > ";
	cin >> filename;

	inFile.open(filename);
	if (!inFile) {
		cerr << "Unable to open inut file, exiting...\n";
		exit(1);
	}


	vector<int> numbers;
	vector<int> tempNumbers;

	int val;
	while (inFile.read((char*)&val, sizeof(int))) {
		numbers.push_back(val);
	}

	tempNumbers = numbers; // copy to avoid ruining the original data
	cout << " --- Numbers before sorting --- \n";
	printFirstLast(7, numbers);

	/* begin profiling the algorithms */
	clock_t c_start;
	clock_t c_end;
	time_t start_time;
	tm *ltm;
	long double time_elapsed_sec;

	start_time =  time(0);
	ltm = localtime(&start_time);
	cout << " --- Initiate sorting with bubble sort. Starting timer at " << ltm->tm_hour << ":" << ltm->tm_min << "... --- \n";

	c_start = clock(); // start clock
	bubbleSort(tempNumbers);
	c_end = clock(); // end clock

	time_elapsed_sec = (long double)(c_end - c_start) / CLOCKS_PER_SEC;
	printFirstLast(7, tempNumbers);
	cout << " --- Done sorting! Sorting took " << time_elapsed_sec << " seconds --- \n";

	tempNumbers = numbers;

	start_time = time(0);
	ltm = localtime(&start_time);
	cout << " --- Initiate sorting with quick sort. Starting timer at " << ltm->tm_hour << ":" << ltm->tm_min << "... --- \n";

	c_start = clock();
	quickSort(tempNumbers, 0, tempNumbers.size() - 1);
	c_end = clock();
	time_elapsed_sec = (long double)(c_end - c_start) / CLOCKS_PER_SEC;
	
	printFirstLast(7, tempNumbers);
	cout << " --- Done sorting! Sorting took " << time_elapsed_sec << " seconds --- \n";

	return 0;
}
