#pragma once
#include <vector>
#include "Graph.h"
#include <chrono>

class SimulatedAnnealing
{
public:
	SimulatedAnnealing();
	~SimulatedAnnealing();
	float calculateProbability(int currCost, int newCost, int currTemp);
	void launchAlgorithm(Graph graph, float coolingRate, float endTemp, double timeLimit);
	std::vector<int> randomPath(int size);
	int calculateCost(Graph graph, std::vector<int> path);
	double timeDifference(std::chrono::steady_clock::time_point begin, std::chrono::steady_clock::time_point end);
	std::vector<int> swap(std::vector<int> vec);
	std::vector<int> greedy(Graph graph, int size);
	double getBestTime();
	int getCost();
	double getTempEnd();
	std::vector<int> getPath();
	void printPath(std::vector<int> path);
private:
	std::vector<int> path;
	int cost;
	double bestTime;
	double temp;
};

