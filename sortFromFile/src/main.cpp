#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;
/*

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void sort(int a[], int arrayLenght){
	int size = sizeof(int);
	qsort (a, arrayLenght,size,compare);
	for (int i=0; i < arrayLenght; i++){
		cout << a[i] << endl;
	}
}
*/

bool getArrayFromFile( vector<int> & inputArray, string nameOfFile){
	int temp;
	char wrongChar;
	ifstream inputFile;
	inputFile.open(nameOfFile.c_str());
	if (!inputFile.good()){
		cout << "File cannot be opened" << endl;
		return false;
	}
	while (!inputFile.eof()){
		inputFile.clear();
		inputFile >> temp;
		if (inputFile.bad()){
			cout << "Cannot read this file" << endl;
			inputFile.close();
			return false;
		} else
		if (inputFile.fail()){
			cout << "Cannot read this number" << endl;
			inputFile.clear();
			inputFile >> wrongChar;
		} else {
			inputArray.push_back(temp);
		}
	}
	inputFile.close();
	return true;
}

bool storeArrayToFile( vector<int> & outputArray, string outputNameOfFile){
	fstream outputFile;
	outputFile.open ("test.txt", fstream::out);

	for (vector<int>::iterator it=outputArray.begin(); it < outputArray.end(); it++)
	{
		outputFile << *it << " ";
	};
	outputFile.close();
	return 0;
}

int main(){
	vector<int> array;
	if(!getArrayFromFile(array,"unsorted")){
		cout << "error occurred" << endl;
		return 1;
	}
	sort(array.begin(),array.end());
	storeArrayToFile(array,"sorted");
	return 0;
}
