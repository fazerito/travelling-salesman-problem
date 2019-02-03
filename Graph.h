#pragma once
#include <vector>
#include <string>

class Graph
{
public:
	Graph();
	Graph(int vertexCount);
	~Graph();
	void createGraph(int vertexCount);
	int getVertexCount();
	std::vector<std::vector<int>> getCosts();
	static Graph readFromFile(std::string filename);
	static Graph readFromFileAnnealing(std::string file, int size);
	int getMatrixSize(std::string filename);
	void createRandom(int vertexCount);
	void printGraph();
	void clear();
	
private: 
	std::vector <std::vector <int> > costs;
	int vertexCount;
};
