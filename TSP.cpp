#include "pch.h"
#include "TSP.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>

TSP::TSP()
{
}


TSP::~TSP()
{
}

int TSP::getCost()
{
	return cost;
}

std::vector<int> TSP::getPath()
{
	return path;
}

int TSP::reduce(std::vector<std::vector<int>> &matrix)
{
	int reductionCost = 0;
	std::vector<int> minColCosts;
	std::vector<int> minRowCosts;
	minRowCosts.resize(matrix.size());
	minColCosts.resize(matrix.size());
	
	for (int i = 0; i < matrix.size(); i++)
	{
		minRowCosts[i] = INT_MAX;
		minColCosts[i] = INT_MAX;
	}
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			if (matrix[i][j] != -1 && matrix[i][j] < minRowCosts[i])
					minRowCosts[i] = matrix[i][j];
		}
	}
	
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			if(matrix[i][j] != -1 && minRowCosts[i] != INT_MAX)
				matrix[i][j] -= minRowCosts[i];
			
		}
	}
	//kolumny
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			if (matrix[i][j] != -1 && matrix[i][j] < minColCosts[j])
				minColCosts[j] = matrix[i][j];
		}
	}
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			if (matrix[i][j] != -1 && minColCosts[j] != INT_MAX)
 				matrix[i][j] -= minColCosts[j];
		}
	}
	for (int i = 0; i < matrix.size(); i++)
	{
		if (minRowCosts[i] == INT_MAX)
			minRowCosts[i] = 0;
		if (minColCosts[i] == INT_MAX)
			minColCosts[i] = 0;
		reductionCost += minColCosts[i] + minRowCosts[i];
	}
		
	
	return reductionCost;
}

std::vector<std::vector<int>> TSP::setColAndRowToInf(std::vector<std::vector<int>> matrix, int row, int col)
{
	std::vector < std::vector<int>> newMatrix = matrix;
	if (row != col)
	{
		for (int n = 0; n < newMatrix.size(); n++)
		{
			newMatrix[row][n] = -1;
			newMatrix[n][col] = -1;
		}
	}
	newMatrix[col][row] = -1;
	return newMatrix;
}



TSP TSP::bruteForce(Graph graph)
{
	TSP brute;
	//koszt
	brute.cost = INT_MAX;
	//wektor odpowiadajacy sciezce i wierzcholkom
	std::vector<int> route;
	std::vector<int> vertices;
	//uzupelniamy wektor wierzcholkow
	for (int i = 0; i < graph.getVertexCount(); i++)
	{
		if (i != 0)
			vertices.push_back(i);
	}

	do
	{
		//obecny koszt przejscia
		int currentCost = 0;
		//wierzcholek startowy
		int start = 0;
		route.push_back(start);
		for (int i = 0; i < vertices.size(); i++)
		{
			//koszt przejscia - przy 1 iteracji to koszt przejscia z 0->1
			currentCost += graph.getCosts()[start][vertices[i]];
			//przejscie do kolejnego wierzcholka
			start = vertices[i];
			//dodanie wierzcholka do sciezki
			route.push_back(start);
		}
		//dodanie kosztu powrotu do poczatkowego miasta
		currentCost += graph.getCosts()[route.back()][0]; 
		//jezeli obecny koszt mniejszy niz dotychczas znaleziony
		if (currentCost < brute.cost)
		{
			//zamieniamy
			brute.cost = currentCost;
			//kopiowanie obecnej trasy
			brute.path = route;
			//wypisanie powrotu do poczatkowego miasta
			brute.path.push_back(route[0]);
		}
		else
		{
			//w przeciwnym razie czyscimy sciezke
			route.clear();
		}
		//funkcja zwracajaca wszystkie permutacje
	} while (std::next_permutation(vertices.begin(), vertices.end()));

	return brute;
}

TSP TSP::branchAndBound(Graph graph)
{
	TSP bb;
	//koszt przejscia
	bb.cost = INT_MAX;
	std::vector<std::vector<int>> reducedGraph = graph.getCosts();
	//obliczamy minimalny koszt przejscia
	int reductionCost = bb.reduce(reducedGraph);
	//wektor wierzcholkow
	std::priority_queue<vertex> vertices;
	
	//pierwszy wierzcholek = 0
	vertex root = {0, reductionCost, reducedGraph};
	//dodanie do wektora pierwszego wierzcholka
	vertices.push(root);
	do
	{	
		//obecnie przetwarzany wierzcholek 
		vertex currentVertex = vertices.top();
		//zdejmujemy z kolejki wierzcholek
		vertices.pop();
		if (currentVertex.number == 0)
			currentVertex.currentPath.push_back(0);
		//zaznaczamy ze wierzcholek zostal odwiedzony	
		currentVertex.visited.resize(graph.getVertexCount());
		currentVertex.visited[currentVertex.number] = true;
		//sprawdzamy kazdy wierzcholek wychodzacy z obecnego
		for (int i = 0; i < graph.getVertexCount(); i++)
		{
			//jezeli nie przeszlismy juz przez wierzcholek w sciezce
			if (!currentVertex.visited[i])
			{
				//tworzymy nowy wierzcholek
				vertex newVertex;
				//ustawiamy -1 na kolumnie i-tej oraz wierszu takim jak wierzcholek wyzej
				newVertex.reducedMatrix = bb.setColAndRowToInf(currentVertex.reducedMatrix, currentVertex.number, i);
				//kopiujemy odwiedzone wierzcho³ki i œcie¿kê
				newVertex.visited = currentVertex.visited;
				newVertex.currentPath = currentVertex.currentPath;
				//numer wierzcholka i
				newVertex.number = i;
				//dodajemy go do sciezki
				newVertex.currentPath.push_back(i);
				newVertex.visited[i] = true;
				//obliczamy koszt redukcji nowego wierzcholka
				int temp = bb.reduce(newVertex.reducedMatrix);
				//laczny koszt przejscia do tego wierzcholka
 				newVertex.cost = currentVertex.cost + currentVertex.reducedMatrix[currentVertex.number][i] + temp;
				
				//dodanie wierzcholka do wektora
				vertices.push(newVertex);
			}
			
		}
		//kopiujemy koszt i sciezke do obiektu
		bb.cost = currentVertex.cost;
		bb.path = currentVertex.currentPath;
	} while (bb.path.size() != graph.getCosts().size());
	//dodanie powrotu do sciezki
	bb.path.push_back(0);
	return bb;
}

void TSP::printMatrix(std::vector<std::vector<int>> matrix)
{
	std::cout << matrix.size() << std::endl;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			std::cout << matrix[i][j] << std::setw(3);
		}
		std::cout << "\n";
	}
}

void TSP::printPath()
{
	std::cout << this->cost << "\n";
	for (int i = 0; i < this->path.size(); i++)
	{
		if (i == this->path.size() - 1)
		{
			std::cout << this->path[i];
		}
		else std::cout << this->path[i] << " - ";
	}
	std::cout << "\n";
}


