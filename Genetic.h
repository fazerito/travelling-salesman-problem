#pragma once
#include <vector>
#include <chrono>
#include <queue>

class Graph;

class Genetic
{
public:
	struct Chromosome
	{
		int cost;
		std::vector<int> path;

		friend bool operator <(const Chromosome& first, const Chromosome& second)
		{
			return first.cost > second.cost;
		}
	};
	Genetic();
	~Genetic();
	int calculateCost(Graph graph, std::vector<int> path);
	std::vector<Genetic::Chromosome> createPopulation(Graph graph, int size);
	double timeDifference(std::chrono::steady_clock::time_point begin, std::chrono::steady_clock::time_point end);
	Chromosome mutateFirst(Chromosome chromosome);
	std::vector<int> mutateSecond(Chromosome chromosome);
	void launchAlgorithm(Graph graph, int populationSize, double mutationRate, double crossoverRate, int mutationChoice, int timeLimit);
	Chromosome crossover(Chromosome chromosome1, Chromosome chromosome2);
	int getBestCost();
	std::vector<int> getBestPath();
	int getPopulationSize();
	void setPopulationSize(int populationSize);
	void setMutationRate(double mutationRate);
	double getMutationRate();
	void setCrossoverRate(double crossoverRate);
	double getCrossoverRate();
	void setTime(int time);
	int getTime();
	void setMutationChoice(int mutationChoice);
	int getMutationChoice();

private:
	int bestCost;
	std::vector<int> bestPath;
	int populationSize;
	double mutationRate;
	double crossoverRate;
	int time;
	int mutationChoice;
};

