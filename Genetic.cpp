#include "pch.h"
#include "Genetic.h"
#include "Graph.h"
#include <chrono>
#include <algorithm>
#include <iostream>
#include <random>
#include <map>
#include <cstdlib>


Genetic::Genetic()
{
	this->mutationRate = 0.01;
	this->crossoverRate = 0.8;
	this->populationSize = 50;
	this->mutationChoice = 1;
	this->time = 30;
}


Genetic::~Genetic()
{
}

int Genetic::calculateCost(Graph graph, std::vector<int> path)
{
	int cost = 0;
	for (int i = 0; i < path.size() - 1; i++)
	{
		cost += graph.getCosts()[path[i]][path[i + 1]];
	}
	cost += graph.getCosts()[path.size() - 1][0];
	return cost;
}

std::vector<Genetic::Chromosome> Genetic::createPopulation(Graph graph, int sizeOfPopulation)
{
	std::vector<Chromosome> population;
	Chromosome chromosome;
	for (int j = 0; j < sizeOfPopulation
; j++)
	{	
		chromosome.path.clear();
		for (int i = 0; i < graph.getCosts().size(); i++)
		{
			chromosome.path.push_back(i);
		}
		std::random_shuffle(chromosome.path.begin(), chromosome.path.end());
		chromosome.cost = calculateCost(graph, chromosome.path);
		population.push_back(chromosome);
	}
		
	return population;
}

double Genetic::timeDifference(std::chrono::steady_clock::time_point begin,
	std::chrono::steady_clock::time_point end)
{
	return std::chrono::duration_cast<std::chrono::seconds>(end - begin).count();
}

Genetic::Chromosome Genetic::mutateFirst(Chromosome chromosome)
{

	int city1, city2;
	do
	{
		city1 = rand() % chromosome.path.size();
		city2 = rand() % chromosome.path.size();

	} while (city1 == city2);

	std::swap(chromosome.path.at(city1), chromosome.path.at(city2));

	return chromosome;
}

std::vector<int> Genetic::mutateSecond(Chromosome chromosome)
{
	int begin = rand() % (chromosome.path.size() - 7);
	std::random_shuffle(chromosome.path.begin() + begin, chromosome.path.begin() + (begin + 6));
	
	return chromosome.path;
}

void Genetic::launchAlgorithm(Graph graph, int populationSize, double mutationRate, double crossoverRate, int mutationChoice, int timeLimit)
{
	
	std::vector<Chromosome> population = createPopulation(graph, populationSize);

	//liczba z przedzialu 0-1
	std::random_device rd;  
	std::mt19937 gen(rd()); 
	std::uniform_real_distribution<double> dis(0.0, 1.0);
	std::chrono::steady_clock::time_point timeStart = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point timeStop = std::chrono::steady_clock::now();
	double currentTime = timeDifference(timeStart, timeStop);
	while (timeLimit > currentTime)
	{
		
		int currentPopulationSize = population.size();
		for(int i = 0; i < currentPopulationSize; i++)
		{
			if (crossoverRate > dis(gen))
			{
			//selekcja
				int parentsIndexes[4];
				int parentOneIndex;
				int parentTwoIndex;

				for (int j = 0; j < 4; j++)
				{
					parentsIndexes[j] = rand() % population.size();
				}
				if (calculateCost(graph, population[parentsIndexes[0]].path) < calculateCost(graph, population[parentsIndexes[1]].path))
					parentOneIndex = parentsIndexes[0];
				else
					parentOneIndex = parentsIndexes[1];
				
				if (calculateCost(graph, population[parentsIndexes[2]].path) < calculateCost(graph, population[parentsIndexes[3]].path))
					parentTwoIndex = parentsIndexes[2];
				else
					parentTwoIndex = parentsIndexes[3];
			//krzyzowanie
			
				Chromosome newChromosome = crossover(population[parentOneIndex], population[parentTwoIndex]);
				newChromosome.cost = calculateCost(graph, newChromosome.path);
				population.push_back(newChromosome);
			}
		}
		
		for (int i = 0; i < population.size(); i++)
		{
			
			//mutacja metoda swap
			if (mutationChoice == 1 && dis(gen) < mutationRate)
			{
				int randNum = rand() % population.size();
				population[randNum] = mutateFirst(population[randNum]);
				population[randNum].cost = calculateCost(graph, population[randNum].path);
			}
			//mutacja metoda scramble
			if (mutationChoice == 2 && dis(gen) < mutationRate)
			{
				population[i].path = mutateSecond(population[i]);
				population[i].cost = calculateCost(graph, population[i].path);
			}
		}


		std::sort(population.rbegin(), population.rend());
		while (population.size() > populationSize)
		{
			population.pop_back();
		}

		timeStop = std::chrono::steady_clock::now();
		currentTime = timeDifference(timeStart, timeStop);
	}
	bestCost = population[0].cost;
	bestPath = population[0].path;
	std::cout << "Min. koszt: " << bestCost << std::endl;

}

Genetic::Chromosome Genetic::crossover(Chromosome chromosome1, Chromosome chromosome2)
{
	Chromosome newChromosome;

	for (int i = 0; i < floor(chromosome1.path.size() / 2); i++)
	{
		newChromosome.path.push_back(chromosome1.path[i]);
	}
	for (int i = 0; i < chromosome2.path.size(); i++)
	{
		if (std::find(newChromosome.path.begin(), newChromosome.path.end(), chromosome2.path[i]) != newChromosome.path.end())
		{
			continue;
		}
		else
		{
			newChromosome.path.push_back(chromosome2.path[i]);
		}
	}

	return newChromosome;
}

int Genetic::getBestCost()
{
	return bestCost;
}

std::vector<int> Genetic::getBestPath()
{
	return bestPath;
}

int Genetic::getPopulationSize()
{
	return populationSize;
}

void Genetic::setPopulationSize(int populationSize)
{
	   this->populationSize = populationSize;
}

void Genetic::setMutationRate(double mutationRate)
{
	this->mutationRate = mutationRate;
}

double Genetic::getMutationRate()
{
	return mutationRate;
}

void Genetic::setCrossoverRate(double crossoverRate)
{
	this->crossoverRate = crossoverRate;
}

double Genetic::getCrossoverRate()
{
	return crossoverRate;
}

void Genetic::setTime(int time)
{
	this->time = time;
}

int Genetic::getTime()
{
	return time;
}

void Genetic::setMutationChoice(int mutationChoice)
{
	this->mutationChoice = mutationChoice;
}

int Genetic::getMutationChoice()
{
	return mutationChoice;
}
