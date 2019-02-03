#include "pch.h"
#include "Graph.h"
#include <fstream>
#include <iostream>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <sstream>

Graph::Graph()
{

}

Graph::Graph(int vertexCount)
{
	createGraph(vertexCount);
}


Graph::~Graph()
{
}

void Graph::createGraph(int vertexCount)
{
	this->vertexCount = vertexCount;
	this->costs.resize(vertexCount);
	for (int i = 0; i < vertexCount; i++)
	{
		this->costs[i].resize(vertexCount);
	}
}

int Graph::getVertexCount()
{
	return vertexCount;
}

std::vector<std::vector<int>> Graph::getCosts()
{
	return costs;
}

Graph Graph::readFromFile(std::string filename)
{
	int vertex, cost;
	Graph graph;
	std::fstream file;
	file.open(filename, std::ios::in);

	if (file.good())
	{
		while (!file.eof())
		{
			file >> vertex;
			graph = Graph(vertex);
			for (int i = 0; i < vertex; i++)
			{
				for (int j = 0; j < vertex; j++)
				{
					file >> cost;
					graph.costs[i][j] = cost;
				}
			}
			break;
		}
		file.close();
	}
	else
	{
		std::cout << "Blad. Sprawdz nazwe pliku.\n";
		system("pause");
	}
	return graph;
}

Graph Graph::readFromFileAnnealing(std::string filename, int size)
{
	Graph graph = Graph(size);
	std::fstream file;
	file.open(filename, std::ios::in);
	std::string cost;
	while (cost != "EOF")
	{
		file >> cost;
		if (cost == "EDGE_WEIGHT_SECTION")
		{
			for (int i = 0; i < size; ++i)
			{
				for (int j = 0; j < size; ++j)
				{
					file >> cost;
					if (cost != "EOF")
					{
						std::remove_if(cost.begin(), cost.end(), isspace);
						int n = std::stoi(cost);
						graph.costs[i][j] = n;
					}					
				}
			}
		}
	}
	return graph;
}

int Graph::getMatrixSize(std::string filename)
{
	int size = -1;
	std::string line;
	std::fstream file;
	file.open(filename, std::ios::in);

	do
	{
		std::getline(file, line);
		int pos = line.find("DIMENSION: ");
		if (pos != std::string::npos)
		{
			//"DIMENSION: " zawiera 11 znakow
			pos += 11;
			size = std::stoi(line.substr(pos));
		}
	} while (line.find("EDGE_WEIGHT_SECTION") == std::string::npos);

	return size;
}

void Graph::createRandom(int vertexCount)
{
	this->costs.resize(vertexCount);
	this->vertexCount = vertexCount;
	for (int i = 0; i < vertexCount; i++)
	{
		this->costs[i].resize(vertexCount);
	}
	for (int i = 0; i < vertexCount; i++)
	{
		for (int j = 0; j < vertexCount; j++)
		{
			int random = rand() % 80;
			if (i == j)
				this->costs[i][j] = -1;
			else
				this->costs[i][j] = random;
		}
	}
}

void Graph::printGraph()
{
	std::cout << this->vertexCount << std::endl;
	for (int i = 0; i < this->vertexCount; i++)
	{
		for (int j = 0; j < this->vertexCount; j++)
		{
			std::cout << this->costs[i][j] << std::setw(3);
		}
		std::cout << "\n";
	}
	system("pause");
}



void Graph::clear()
{
	this->vertexCount = 0;
	for (int i = 0; i < this->costs.size(); i++)
	{
		this->costs[i].clear();
	}
	this->costs.clear();
}


