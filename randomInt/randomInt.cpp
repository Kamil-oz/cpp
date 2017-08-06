#include <iostream>
#include <cstdlib>
#include <ctime>
//printing array of 10 integers with random numbers 1-100 without repeats

using namespace std;

int getRandom(){
return rand()%100+1;
}

bool isUnique(int iArray[], int size, int random){
	for (int i = 0; i < size; i++){
		if (random == iArray[i]){
			return false;
		}
	}	
	return true;
}

void fillArrayWithRandomIntegers(int iArray[], int size){
	for (int i=0; i<size; i++){
		int temp;
		do {
		temp = getRandom();
		} while (!isUnique(iArray, size, temp));
		iArray[i]=temp;
	}
}

void show(int iArray[], int size){
	for (int i=0; i<size;i++){
		cout << iArray[i] << " ";
	}
	cout << endl;
}

int main(){
	srand(time(0));
	int array[10];
	int sizeOfArray = sizeof(array)/sizeof(array[0]); 
	fillArrayWithRandomIntegers(array, sizeOfArray); 	
	show(array, sizeOfArray);
return 0;
}
