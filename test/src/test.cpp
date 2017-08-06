//============================================================================
// Prime Algoritm
// Gets graph in : vertex vertex distance
// Gives minimum spanning tree with distances
//============================================================================
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Path{
public:
	int vertex1;
	int vertex2;
	int distance;

public:
	Path (int vert1,int vert2, int dist){
		this->vertex1=vert1;
		this->vertex2=vert2;
		this->distance=dist;
	}

};


void sortGraph( vector<Path> & pathToSort){
	vector<Path> temp;
	int pathSize = pathToSort.size();
	for (int i=1; i<pathSize; i++){
		for (int j=0 ; j<pathSize-1; j++){
			if (pathToSort[j].distance < pathToSort[j+1].distance){
				swap(pathToSort[j],pathToSort[j+1]);
			}
		}
	}
}

bool getGraphFromFile( vector<Path> & inputPath, string nameOfFile){
	int vertex1, vertex2, path;
	char wrongChar;
	ifstream inputFile;
	inputFile.open(nameOfFile.c_str());
	if (!inputFile.good()){
		cout << "File cannot be opened" << endl;
		return false;
	}
	while (!inputFile.eof()){
		inputFile.clear();
		inputFile >> vertex1 >> vertex2 >> path;
	//	cout << vertex1 << vertex2 << path << endl;
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
			inputPath.push_back(Path(vertex1,vertex2,path));
		}
	}
	inputFile.close();
	return true;
}

void drawGraph(vector<Path> & graphToDraw){
	for ( int i=0; i<graphToDraw.size() ;i++){
		cout << graphToDraw[i].vertex1 << graphToDraw[i].vertex2 << graphToDraw[i].distance << endl;
	}
}

vector<int> getVertex(vector<Path> & inputGraph){
	vector<int> resoult;
	for ( int i=0; i<inputGraph.size(); i++){
		resoult.push_back(inputGraph[i].vertex1);
		resoult.push_back(inputGraph[i].vertex2);
	}
	sort(resoult.begin(),resoult.end());

	for ( int i =0; i<resoult.size();i++){
		cout << resoult[i] << endl;
	}

	for ( int i =0; i<resoult.size()-1;i++){
		if (resoult[i]==resoult[i+1]){
			resoult.erase(resoult.begin()+i);
			i--;
		}
	}
	cout << endl;
	for ( int i =0; i<resoult.size();i++){
		cout << resoult[i] << endl;
	}
	return resoult;
}

vector<Path> getMinimalSpanningTree (vector<Path> & inputGraph){
	vector<Path> minimalSpanningTree, listToCheck;
	vector<int> vertex;
	sortGraph(inputGraph);
	minimalSpanningTree.push_back(inputGraph[inputGraph.size()-1]);
	inputGraph.pop_back();
	vertex = getVertex(inputGraph);
	while (inputGraph.size()!=0){

	}
//	listToCheck
	cout << endl;
	drawGraph(minimalSpanningTree);

	return minimalSpanningTree;
}


int main()
{
	vector<Path> graph;
	if(!getGraphFromFile(graph,"data")){
			cout << "error occurred" << endl;
			return 1;
	}
	//drawGraph(graph);
	//getMinimalSpanningTree(graph);
	//swap(graph[1],graph[2]);
	vector<int> vert = getVertex(graph);
	cout << endl;
//	drawGraph(graph);

	}
