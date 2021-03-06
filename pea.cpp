#include "pch.h"
#include <iostream>
#include "Menu.h"
#include <ctime>
#include <fstream>
#include "TimeMeasure.h"
#include <vector>
#include "SimulatedAnnealing.h"
#include "Genetic.h"
#include <sstream>
#include <cstdlib>

//TimeMeasure pomiary;

//std::vector<std::vector<int>> drogi;
//std::vector<int> koszty;

//void test(int popul, int time, double coef, int muation, double cross, int size)
//{
//	gen.setPopulationSize(popul);
//	gen.setMutationRate(coef);
//	gen.setCrossoverRate(cross);
//	gen.setTime(time);
//
//	std::ostringstream ss, ss1, ss2, ss3, ss4;
//	ss << muation;
//	ss1 << size;
//	ss2 << cross;
//	ss3 << popul;
//	ss4 << time;
//	std::string nazwaPlikuAlgorytm = "Metoda " + ss.str() + " Wierzcholki-" + ss1.str() + "Krzyzowanie " + ss2.str() + "Populacja" + ss3.str() + "Wyniki-Czas = " + ss4.str() + ".txt";
//	std::string nazwaPlikuDrogi = "Metoda " + ss.str() + " Wierzcholki-" + ss1.str() + "Krzyzowanie " + ss2.str() + "Populacja" + ss3.str() + "Drogi-Czas = " + ss4.str() + ".txt";
//
//	for (int j = 0; j < 5; j++)
//	{
//		gen.launchAlgorithm(graph, popul, coef, cross, muation, time);
//		drogi.push_back(gen.getBestPath());
//		czasyAlgorytm.push_back(gen.getTime());
//		koszty.push_back(gen.getBestCost());
//	}
//	pomiary.saveToFile(koszty, nazwaPlikuAlgorytm);
//	pomiary.saveFile(drogi, nazwaPlikuDrogi);
//	czasyAlgorytm.clear();
//	drogi.clear();
//	koszty.clear();
//}

int main()
{
	srand(time(NULL));
	Menu::showMenu();
	//graph = graph.readFromFileAnnealing("ftv47.atsp", graph.getMatrixSize("ftv47.atsp"));

	/*for (int i = 0; i < 5; i++)
		gen.launchAlgorithm(graph, 50, 0.01, 0.8, 1, 60);*/
	
	/*test(50, 40, 0.01, 1, 0.8, 48);
	test(50, 60, 0.01, 1, 0.8, 48);
	test(100, 20, 0.01, 1, 0.8, 48);
	test(100, 60, 0.01, 1, 0.8, 48);
	test(500, 20, 0.01, 1, 0.8, 48);
	test(500, 40, 0.01, 1, 0.8, 48);*/

	/*test(50, 40, 0.01, 2, 0.8, 48);
	test(50, 60, 0.01, 2, 0.8, 48);*/
	//test(100, 40, 0.01, 2, 0.8, 48);
	//test(100, 60, 0.01, 2, 0.8, 48);
	//test(500, 60, 0.01, 2, 0.8, 48);
	//test(500, 40, 0.01, 2, 0.8, 48);

	//graph = graph.readFromFileAnnealing("ftv170.atsp", graph.getMatrixSize("ftv170.atsp"));

	/*test(50, 20, 0.01, 2, 0.8, 171);
	test(50, 40, 0.01, 2, 0.8, 171);
	test(50, 60, 0.01, 2, 0.8, 171);
	test(100, 20, 0.01, 2, 0.8, 171);
	test(100, 40, 0.01, 2, 0.8, 171);
	test(100, 60, 0.01, 2, 0.8, 171);
	test(500, 20, 0.01, 2, 0.8, 171);
	test(500, 40, 0.01, 2, 0.8, 171);
	test(500, 60, 0.01, 2, 0.8, 171);*/

	
	/*graph = graph.readFromFileAnnealing("rbg403.atsp", graph.getMatrixSize("rbg403.atsp"));

	test(50, 60, 0.01, 1, 0.8, 403);
	test(50, 90, 0.01, 1, 0.8, 403);
	test(50, 120, 0.01, 1, 0.8, 403);
	test(100, 60, 0.01, 1, 0.8, 403);
	test(100, 90, 0.01, 1, 0.8, 403);
	test(100, 120, 0.01, 1, 0.8, 403);
	test(500, 60, 0.01, 1, 0.8, 403);
	test(500, 90, 0.01, 1, 0.8, 403);
	test(500, 120, 0.01, 1, 0.8, 403);
	test(50, 60, 0.01, 2, 0.8, 403);
	test(50, 90, 0.01, 2, 0.8, 403);
	test(50, 120, 0.01, 2, 0.8, 403);
	test(100, 60, 0.01, 2, 0.8, 403);
	test(100, 90, 0.01, 2, 0.8, 403);
	test(100, 120, 0.01, 2, 0.8, 403);
	test(500, 60, 0.01, 2, 0.8, 403); 
	test(500, 90, 0.01, 2, 0.8, 403); 
	test(500, 120, 0.01, 2, 0.8, 403); */

	//SimulatedAnnealing sa;
	//std::ofstream file;
	//std::string filename[] = { "47_wyniki.txt", "170_wyniki.txt", "403_wyniki_nowe.txt" };
	//float coolingRates[]{ 0.995, 0.996, 0.997 };
	/*for (int i = 0; i < 10; i++)
	{
		graph = graph.readFromFileAnnealing("ftv47.atsp", graph.getMatrixSize("ftv47.atsp"));
		sa.launchAlgorithm(graph, coolingRates[0], 0.001, 20);
		file.open(filename[0], std::ios::app);
		if (file.good())
		{
			file << "Koszt: " << sa.getCost()<< ", w czasie " << sa.getBestTime() << ", wsp. chlodzenia: " << coolingRates[0] << "temp.k: " << sa.getTempEnd() << std::endl;
			for (int i = 0; i < sa.getPath().size(); i++)
			{
				if (i == sa.getPath().size() - 1)
				{
					file << sa.getPath()[i];
				}
				else file << sa.getPath()[i] << " - ";
			}
			file << "\n";
		}
		file.close();
	}
	for (int i = 0; i < 10; i++)
	{
		graph = graph.readFromFileAnnealing("ftv47.atsp", graph.getMatrixSize("ftv47.atsp"));
		sa.launchAlgorithm(graph, coolingRates[1], 0.001, 20);
		file.open(filename[0], std::ios::app);
		if (file.good())
		{
			file << "Koszt: " << sa.getCost() << ", w czasie " << sa.getBestTime() << ", wsp. chlodzenia: " << coolingRates[1] << " temp.k: " << sa.getTempEnd() << std::endl;
			for (int i = 0; i < sa.getPath().size(); i++)
			{
				if (i == sa.getPath().size() - 1)
				{
					file << sa.getPath()[i];
				}
				else file << sa.getPath()[i] << " - ";
			}
			file << "\n";
		}

		file.close();
	}
	
	for (int i = 0; i < 10; i++)
	{
		graph = graph.readFromFileAnnealing("ftv47.atsp", graph.getMatrixSize("ftv47.atsp"));
		sa.launchAlgorithm(graph, coolingRates[2], 0.001, 20);
		file.open(filename[0], std::ios::app);
		if (file.good())
		{
			file << "Koszt: " << sa.getCost() << ", w czasie " << sa.getBestTime() << ", wsp. chlodzenia: " << coolingRates[2] << ", temp. k: " << sa.getTempEnd() <<std::endl;
			for (int i = 0; i < sa.getPath().size(); i++)
			{
				if (i == sa.getPath().size() - 1)
				{
					file << sa.getPath()[i];
				}
				else file << sa.getPath()[i] << " - ";
			}
			file << "\n";
		}
		file.close();
	}
	for (int i = 0; i < 10; i++)
	{
		graph = graph.readFromFileAnnealing("ftv47.atsp", graph.getMatrixSize("ftv47.atsp"));
		sa.launchAlgorithm(graph, coolingRates[0], 0.001, 30);
		file.open(filename[0], std::ios::app);
		if (file.good())
		{
			file << "Koszt: " << sa.getCost() << ", w czasie " << sa.getBestTime() << ", wsp. chlodzenia: " << coolingRates[0] << "temp.k: " << sa.getTempEnd() << std::endl;
			for (int i = 0; i < sa.getPath().size(); i++)
			{
				if (i == sa.getPath().size() - 1)
				{
					file << sa.getPath()[i];
				}
				else file << sa.getPath()[i] << " - ";
			}
			file << "\n";
		}
		file.close();
	}
	for (int i = 0; i < 10; i++)
	{
		graph = graph.readFromFileAnnealing("ftv47.atsp", graph.getMatrixSize("ftv47.atsp"));
		sa.launchAlgorithm(graph, coolingRates[1], 0.001, 30);
		file.open(filename[0], std::ios::app);
		if (file.good())
		{
			file << "Koszt: " << sa.getCost() << ", w czasie " << sa.getBestTime() << ", wsp. chlodzenia: " << coolingRates[1] << " temp.k: " << sa.getTempEnd() << std::endl;
			for (int i = 0; i < sa.getPath().size(); i++)
			{
				if (i == sa.getPath().size() - 1)
				{
					file << sa.getPath()[i];
				}
				else file << sa.getPath()[i] << " - ";
			}
			file << "\n";
		}

		file.close();
	}

	for (int i = 0; i < 10; i++)
	{
		graph = graph.readFromFileAnnealing("ftv47.atsp", graph.getMatrixSize("ftv47.atsp"));
		sa.launchAlgorithm(graph, coolingRates[2], 0.001, 30);
		file.open(filename[0], std::ios::app);
		if (file.good())
		{
			file << "Koszt: " << sa.getCost() << ", w czasie " << sa.getBestTime() << ", wsp. chlodzenia: " << coolingRates[2] << ", temp. k: " << sa.getTempEnd() << std::endl;
			for (int i = 0; i < sa.getPath().size(); i++)
			{
				if (i == sa.getPath().size() - 1)
				{
					file << sa.getPath()[i];
				}
				else file << sa.getPath()[i] << " - ";
			}
			file << "\n";
		}
		file.close();
	}
	for (int i = 0; i < 10; i++)
	{
		graph = graph.readFromFileAnnealing("ftv170.atsp", graph.getMatrixSize("ftv170.atsp"));
		sa.launchAlgorithm(graph, 0.995, 0.01, 30);
		file.open(filename[1], std::ios::app);
		if (file.good())
		{
			file << "Koszt: " << sa.getCost() << ", w czasie" << sa.getBestTime()<< ", wsp. chlodzenia: " << coolingRates[0] << " temp.k: " << sa.getTempEnd()  << std::endl;
			for (int i = 0; i < sa.getPath().size(); i++)
			{
				if (i == sa.getPath().size() - 1)
				{
					file << sa.getPath()[i];
				}
				else file << sa.getPath()[i] << " - ";
			}
			file << "\n";

		}
		file.close();
	}
	for (int i = 0; i < 10; i++)
	{
		graph = graph.readFromFileAnnealing("ftv170.atsp", graph.getMatrixSize("ftv170.atsp"));
		sa.launchAlgorithm(graph, coolingRates[1], 0.01, 30);
		file.open(filename[1], std::ios::app);
		if (file.good())
		{
			file << "Koszt: " << sa.getCost() << ", w czasie " << sa.getBestTime() << ", wsp. chlodzenia: " << coolingRates[1] << " temp.k: " << sa.getTempEnd() << std::endl;
			for (int i = 0; i < sa.getPath().size(); i++)
			{
				if (i == sa.getPath().size() - 1)
				{
					file << sa.getPath()[i];
				}
				else file << sa.getPath()[i] << " - ";
			}
			file << "\n";

		}

		file.close();
	}
	
	for (int i = 0; i < 10; i++)
	{
		graph = graph.readFromFileAnnealing("ftv170.atsp", graph.getMatrixSize("ftv170.atsp"));
		sa.launchAlgorithm(graph, coolingRates[2], 0.01, 30);
		file.open(filename[1], std::ios::app);
		if (file.good())
		{
			file << "Koszt: " << sa.getCost() << ", w czasie " << sa.getBestTime() << ", wsp. chlodzenia: " << coolingRates[2] << " temp.k: " << sa.getTempEnd() << std::endl;
			for (int i = 0; i < sa.getPath().size(); i++)
			{
				if (i == sa.getPath().size() - 1)
				{
					file << sa.getPath()[i];
				}
				else file << sa.getPath()[i] << " - ";
			}
			file << "\n";

		}
		file.close();
	}
	for (int i = 0; i < 5; i++)
	{
		graph = graph.readFromFileAnnealing("rbg403.atsp", graph.getMatrixSize("rbg403.atsp"));
		sa.launchAlgorithm(graph, 0.995, 0.1, 30);
		file.open(filename[2], std::ios::app);
		if (file.good())
		{
			file << "Koszt: " << sa.getCost() << ", w czasie" << sa.getBestTime() << ", wsp. chlodzenia: " << ".999" << " temp.k: " << sa.getTempEnd() << std::endl;
			for (int i = 0; i < sa.getPath().size(); i++)
			{
				if (i == sa.getPath().size() - 1)
				{
					file << sa.getPath()[i];
				}
				else file << sa.getPath()[i] << " - ";
			}
			file << "\n";

		}
		file.close();
	}
	for (int i = 0; i < 5; i++)
	{
		graph = graph.readFromFileAnnealing("rbg403.atsp", graph.getMatrixSize("rbg403.atsp"));
		sa.launchAlgorithm(graph, 0.996, 0.01, 30);
		file.open(filename[2], std::ios::app);
		if (file.good())
		{
			file << "Koszt: " << sa.getCost() << ", w czasie" << sa.getBestTime() << ", wsp. chlodzenia: " << ".998" << " temp.k: " << sa.getTempEnd() << std::endl;
			for (int i = 0; i < sa.getPath().size(); i++)
			{
				if (i == sa.getPath().size() - 1)
				{
					file << sa.getPath()[i];
				}
				else file << sa.getPath()[i] << " - ";
			}
			file << "\n";

		}
		file.close();
	}
	for (int i = 0; i < 5; i++)
	{
		graph = graph.readFromFileAnnealing("rbg403.atsp", graph.getMatrixSize("rbg403.atsp"));
		sa.launchAlgorithm(graph, 0.997, 0.01, 30);
		file.open(filename[2], std::ios::app);
		if (file.good())
		{
			file << "Koszt: " << sa.getCost() << ", w czasie" << sa.getBestTime() << ", wsp. chlodzenia: " << ".997" << " temp.k: " << sa.getTempEnd() << std::endl;
			for (int i = 0; i < sa.getPath().size(); i++)
			{
				if (i == sa.getPath().size() - 1)
				{
					file << sa.getPath()[i];
				}
				else file << sa.getPath()[i] << " - ";
			}
			file << "\n";

		}
		file.close();
	}
	*/
	/*
	std::vector<double>czasy47;
	std::vector<double>czasy170;
	std::vector<double>czasy403;
	
	int N = 5;
	for (int i = 0; i < 100; i++)
	{
		graf.createRandom(N);
		pomiary.startCounting();
		algorytm.bruteForce(graf);
		czasy47.push_back(pomiary.getCounter());
		pomiary.startCounting();
		algorytm.branchAndBound(graf);
		czasyBranch.push_back(pomiary.getCounter());
		std::cout << N << " - Wielkosc    " << i << " - Zrobione\n";
	}
	pomiary.saveToFile(czasyBrute, "bruteForce6.txt");
	pomiary.saveToFile(czasyBranch, "branchAndBound6.txt");
	czasyBrute.clear();
	czasyBranch.clear();

	N = 7;
	for (int i = 0; i < 100; i++)
	{
		graf.createRandom(N);
		pomiary.startCounting();
		algorytm.bruteForce(graf);
		czasyBrute.push_back(pomiary.getCounter());
		pomiary.startCounting();
		algorytm.branchAndBound(graf);
		czasyBranch.push_back(pomiary.getCounter());
		std::cout << N << " - Wielkosc    " << i << " - Zrobione\n";
	}
	pomiary.saveToFile(czasyBrute, "bruteForce7.txt");
	pomiary.saveToFile(czasyBranch, "branchAndBound7.txt");
	czasyBrute.clear();
	czasyBranch.clear();
	N = 8;
	for (int i = 0; i < 100; i++)
	{
		graf.createRandom(N);
		pomiary.startCounting();
		algorytm.bruteForce(graf);
		czasyBrute.push_back(pomiary.getCounter());
		pomiary.startCounting();
		algorytm.branchAndBound(graf);
		czasyBranch.push_back(pomiary.getCounter());
		std::cout << N << " - Wielkosc    " << i << " - Zrobione\n";
	}
	pomiary.saveToFile(czasyBrute, "bruteForce8.txt");
	pomiary.saveToFile(czasyBranch, "branchAndBound8.txt");
	czasyBrute.clear();
	czasyBranch.clear();
	N = 9;
	for (int i = 0; i < 100; i++)
	{
		graf.createRandom(N);
		pomiary.startCounting();
		algorytm.bruteForce(graf);
		czasyBrute.push_back(pomiary.getCounter());
		pomiary.startCounting();
		algorytm.branchAndBound(graf);
		czasyBranch.push_back(pomiary.getCounter());
		std::cout << N << " - Wielkosc    " << i << " - Zrobione\n";
	}
	pomiary.saveToFile(czasyBrute, "bruteForce9.txt");
	pomiary.saveToFile(czasyBranch, "branchAndBound9.txt");
	czasyBrute.clear();
	czasyBranch.clear();
	N = 10;
	for (int i = 0; i < 100; i++)
	{
		graf.createRandom(N);
		pomiary.startCounting();
		algorytm.bruteForce(graf);
		czasyBrute.push_back(pomiary.getCounter());
		pomiary.startCounting();
		algorytm.branchAndBound(graf);
		czasyBranch.push_back(pomiary.getCounter());
		std::cout << N << " - Wielkosc    " << i << " - Zrobione\n";
	}
	pomiary.saveToFile(czasyBrute, "bruteForce10.txt");
	pomiary.saveToFile(czasyBranch, "branchAndBound10.txt");
	czasyBrute.clear();
	czasyBranch.clear();
	N = 11;
	for (int i = 0; i < 100; i++)
	{
		graf.createRandom(N);
		pomiary.startCounting();
		algorytm.bruteForce(graf);
		czasyBrute.push_back(pomiary.getCounter());
		pomiary.startCounting();
		algorytm.branchAndBound(graf);
		czasyBranch.push_back(pomiary.getCounter());
		std::cout << N << " - Wielkosc    " << i << " - Zrobione\n";
	}
	pomiary.saveToFile(czasyBrute, "bruteForce11.txt");
	pomiary.saveToFile(czasyBranch, "branchAndBound11.txt");
	czasyBrute.clear();
	czasyBranch.clear();
	N = 12;
	for (int i = 0; i < 100; i++)
	{
		graf.createRandom(N);
		//pomiary.startCounting();
		//algorytm.bruteForce(graf);
		//czasyBrute.push_back(pomiary.getCounter());
		pomiary.startCounting();
		algorytm.branchAndBound(graf);
		czasyBranch.push_back(pomiary.getCounter());
		std::cout << N << " - Wielkosc    " << i << " - Zrobione\n";
	}
	//pomiary.saveToFile(czasyBrute, "bruteForce12.txt");
	pomiary.saveToFile(czasyBranch, "branchAndBound12.txt");
	//czasyBrute.clear();
	czasyBranch.clear();
	N = 14;
	for (int i = 0; i < 100; i++)
	{
		graf.createRandom(N);
		pomiary.startCounting();
		algorytm.branchAndBound(graf);
		czasyBranch.push_back(pomiary.getCounter());
		std::cout << N << " - Wielkosc    " << i << " - Zrobione\n";
	}
	pomiary.saveToFile(czasyBranch, "branchAndBound14.txt");
	czasyBranch.clear();
	N = 16;
	for (int i = 0; i < 100; i++)
	{
		graf.createRandom(N);
		pomiary.startCounting();
		algorytm.branchAndBound(graf);
		czasyBranch.push_back(pomiary.getCounter());
		std::cout << N << " - Wielkosc    " << i << " - Zrobione\n";
	}
	pomiary.saveToFile(czasyBranch, "branchAndBound16.txt");
	czasyBranch.clear();
	N = 18;
	for (int i = 0; i < 100; i++)
	{
		graf.createRandom(N);
		pomiary.startCounting();
		algorytm.branchAndBound(graf);
		czasyBranch.push_back(pomiary.getCounter());
		std::cout << N << " - Wielkosc    " << i << " - Zrobione\n";
	}
	pomiary.saveToFile(czasyBranch, "branchAndBound18.txt");
	czasyBranch.clear();
	int N = 17;
	for (int i = 0; i < 100; i++)
	{
		graf.createRandom(N);
		pomiary.startCounting();
		algorytm.branchAndBound(graf);
		czasyBranch.push_back(pomiary.getCounter());
		std::cout << N << " - Wielkosc    " << i << " - Zrobione\n";
	}
	pomiary.saveToFile(czasyBranch, "branch5.txt");
	czasyBranch.clear();*/
	system("pause");
}
static void path(std::vector<int> path, std::ofstream file)
{
	for (int i = 0; i < path.size(); i++)
	{
		if (i == path.size() - 1)
		{
			file << path[i];
		}
		else file << path[i] << " - ";
	}
	file << "\n";
}

