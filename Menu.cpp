#include "pch.h"
#include "Menu.h"
#include "Graph.h"
#include "TSP.h"
#include "Genetic.h"
#include <iostream>
#include "SimulatedAnnealing.h"

class Genetic;
TSP algorithm;
Genetic gen;
Graph graph;

Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::showMenu()
{
	while (true)
	{
		system("cls");
		std::cout << "[1] Wczytaj z pliku\n" <<
			"[2] Wyswietl macierz\n" <<
			"[3] Wspolczynnik mutacji\n" <<
			"[4] Wspolczynnik krzyzowania\n" <<
			"[5] Wielkosc populacji\n" <<
			"[6] Metoda mutacji\n" 
			"[7] Czas\n"<<
			"[8] Algorytm genetyczny\n" <<
			"[9] Wyjscie\n";
			//"[4] BruteForce\n" <<
			//"[5] BnB\n";

		std::cout << "Wybierz opcje: ";
		std::string filename;
		std::string choice = getUserInput();
		double wsp;
		int size;
		std::string wsps;
		switch (std::stoi(choice))
		{
		case 1:
			system("cls");
			//graph.clear();
			std::cout << "Podaj nazwe pliku:\n";
			filename = getUserInput();
			size = graph.getMatrixSize(filename);
			graph = Graph::readFromFileAnnealing(filename, size);
			//graph.printGraph();
			break;
		case 2:
			system("cls");
			graph.printGraph();
			break;
		case 3:
			system("cls");
			std::cout << "Podaj wartosc wspolczynnika mutacji: \n";
			std::cin >> wsp;
			gen.setMutationRate(wsp);
			break;
		case 4:
		{
			system("cls");
			std::cout << "Podaj wartosc wspolczynnika krzyzowania: \n";
			std::cin >> wsp;
			gen.setCrossoverRate(wsp);
			break;
		}
		case 5:
		{
			system("cls");
			std::cout << "Podaj wielkosc populacji: \n";
			wsps = getUserInput();
			int popSize  = int(std::stoi(wsps));
			gen.setPopulationSize(popSize);
			break;
		}
		case 6:
			{
			system("cls");
			std::cout << "Podaj metode mutacji: \n";
			wsps = getUserInput();
			if (wsps == "swap")
				gen.setMutationChoice(1);
			else if (wsps == "scramble")
				gen.setMutationChoice(2);
			break;
			}
		case 7:
			{
			system("cls");
			std::cout << "Podaj czas dzialania algorytmu: \n";
			wsps = getUserInput();
			int time = int(std::stoi(wsps));
			gen.setTime(time);
			break;
			}
		case 8:
			gen.launchAlgorithm(graph, gen.getPopulationSize(), gen.getMutationRate(), gen.getCrossoverRate(), gen.getMutationChoice(), gen.getTime());
			system("pause");
			break;
		case 9:
			system("cls");
			exit(0);
			break;
		default:
			std::cout << "Wybrano zly przycisk.\n";
			system("pause");
			showMenu();
			break;
		}

		std::cout << "Wsp. mutacji: " << gen.getMutationRate() << std::endl;
		std::cout << "Wsp. krzyzowania: " << gen.getCrossoverRate() << std::endl;
		std::cout << "Populacja: " << gen.getPopulationSize() << std::endl;
		std::cout << "Metoda mutacji: " << gen.getMutationChoice() << std::endl;
		std::cout << "Czas: " << gen.getTime() << std::endl;
		system("pause");
	}
}

std::string Menu::getUserInput()
{
	std::string data;
	std::cin >> data;
	return data;
}
