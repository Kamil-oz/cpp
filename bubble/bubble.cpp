#include <iostream>

using namespace std;

main(){
int table[] = {2,3,42,5,234,23,234,5678,4,4576,456,84,3,213,412,45};
int sizeOfTable = sizeof(table)/sizeof(table[0]);
for (int i = 1; i<sizeOfTable ;i++){
	for (int j = 0; j<sizeOfTable-1; j++){
		if (table[j]>table[j+1]){
			int temp = table[j];
			table[j]=table[j+1];
			table[j+1]=temp;
		}
	}

}
for (int i = 0; i<sizeOfTable ; i++){
	cout << table[i] << " " ;

}
return 0;
}
