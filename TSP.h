#pragma once
#include "Graph.h"
#include <vector>
#include <queue>

class TSP
{
public:
	struct vertex {
		int number;
		int cost;
		std::vector<std::vector<int>> reducedMatrix;
		std::vector<bool> visited;
		std::vector<int> currentPath;
		friend bool operator < (const vertex& other, const vertex& second) 
		{
			return other.cost < second.cost;
		}
	};
	TSP();
	~TSP();
	int getCost();
	std::vector<int> getPath();
	int reduce(std::vector<std::vector<int>> &matrix);
	std::vector<std::vector<int>> setColAndRowToInf(std::vector<std::vector<int>> matrix, int col, int row);
	static TSP bruteForce(Graph graph);
	static TSP branchAndBound(Graph graph);
	void printMatrix(std::vector<std::vector<int>> matrix);
	void printPath();

private:
	int cost;
	std::vector<int> path;
};

