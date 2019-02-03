#include "pch.h"
#include "SimulatedAnnealing.h"
#include "Graph.h"
#include <algorithm>
#include <math.h>
#include <ctime>
#include <iostream>
#include <queue>
#include "TSP.h"
#include <chrono>
#include "TimeMeasure.h"
#include <fstream>


SimulatedAnnealing::SimulatedAnnealing()
{
}


SimulatedAnnealing::~SimulatedAnnealing()
{
}

float SimulatedAnnealing::calculateProbability(int currentCost, int nCost, int currTemp)
{
	return powf(2.7182818f, -(float(nCost - currentCost) / currTemp));

}

void SimulatedAnnealing::launchAlgorithm(Graph graph, float coolingRate, float endTemp, double timeLimit)
{
	srand(time(NULL));
	int currCost = 0;
	int newCost = 0;
	std::chrono::steady_clock::time_point timeStart, timeStop;
	double currentTime;
	TimeMeasure timer;
	//pierwsza sciezka = algorytm zachlanny
	std::vector<int> currPath = greedy(graph, graph.getCosts().size());
	//liczenie kosztu sciezki
	currCost = calculateCost(graph, currPath);
	cost = currCost;
	//temperatura poczatkowa uzalezniona od poczatkowego kosztu przejscia
	temp = currCost * 0.005;
	timeStart = std::chrono::steady_clock::now();
	timer.startCounting();
	timeStop = std::chrono::steady_clock::now();
	currentTime = timeDifference(timeStart, timeStop);
	while (timeLimit > currentTime)
	{
		for (int i = 0; i < currPath.size() / 4; i++)
		{
			std::vector<int> newPath = currPath;
			//zamiana 2 losowych miast
			newPath = swap(newPath);
			//przeliczenie nowego kosztu
			newCost = calculateCost(graph, newPath);
			if (newCost <= currCost)
			{
				currCost = newCost;
				currPath = newPath;

				if (newCost < cost)
				{
					cost = newCost;
					path = currPath;
					bestTime = timer.getCounter();
				}
			}
			else
			{
				//losowa liczba z przedzialu od 0 do 1
				double random = ((double)rand() / (RAND_MAX));
				double probability = calculateProbability(currCost, newCost, temp);
				//sprawdzam gorszy wynik
				if (random < probability)
				{
					currCost = newCost;
					currPath = newPath;
				}
			}
		}
		//chlodzenie
		temp *= coolingRate;
		timeStop = std::chrono::steady_clock::now();
		currentTime = timeDifference(timeStart, timeStop);
		std::cout << "czas: " << currentTime << std::endl;
		//std::cout << "temp. k: " << temp << "\n";
	}
	std::cout << "najlepszy wynik " << cost << " w: " << bestTime << std::endl;

}

std::vector<int> SimulatedAnnealing::randomPath(int length)
{
	std::vector<int> path;
	for (int i = 0; i < length; i++)
		path.push_back(i);
	std::random_shuffle(path.begin(), path.end());
	return path;
}

int SimulatedAnnealing::calculateCost(Graph graph, std::vector<int> path)
{
	int cost = 0;
	for (int i = 0; i < path.size() - 1; i++)
	{
		cost += graph.getCosts()[path[i]][path[i + 1]];
	}
	cost += graph.getCosts()[path.size() - 1][0];
	return cost;
}

double SimulatedAnnealing::timeDifference(std::chrono::steady_clock::time_point begin,
	std::chrono::steady_clock::time_point end)
{
	return std::chrono::duration_cast<std::chrono::seconds>(end - begin).count();
}

std::vector<int> SimulatedAnnealing::swap(std::vector<int> vec)
{
	std::vector<int> newPath = vec;
	int firstCity = rand() % newPath.size();
	int secondCity;
	do
	{
		secondCity = rand() % newPath.size();
	} while (firstCity == secondCity);
	std::swap(newPath.at(firstCity), newPath.at(secondCity));
	return newPath;
}

std::vector<int> SimulatedAnnealing::greedy(Graph graph, int size)
{
	std::vector<bool> visited;
	visited.resize(size);
	std::vector<int> path;
	std::vector<int> temp;
	int minCost = INT_MAX;
	int currCost = 0;
	visited[0] = true;
	path.push_back(0);
	std::vector<std::vector<int>> matrix = graph.getCosts();
	while(path.size() != size)
	{
		int currVertex = path.back();
		visited[currVertex] = true;
		for (int j = 0; j < graph.getCosts().size(); j++)
		{
			if (currVertex != j && visited[j] == false)
			{
				currCost = matrix[currVertex][j];
				if (currCost < minCost)
				{
					minCost = currCost;
					temp.push_back(j);
				}
			}
		}
		minCost = INT_MAX;
		path.push_back(temp.back());
		visited[path.back()] = true;
	}
		
	return path;
}

double SimulatedAnnealing::getBestTime()
{
	return bestTime;
}

int SimulatedAnnealing::getCost()
{
	return cost;
}

double SimulatedAnnealing::getTempEnd()
{
	return temp;
}

std::vector<int> SimulatedAnnealing::getPath()
{
	return path;
}