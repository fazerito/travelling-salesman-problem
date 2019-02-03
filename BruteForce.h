#pragma once
#include <vector>

class BruteForce
{
public:
	BruteForce();
	~BruteForce();
private:
	int cost;
	std::vector<int> path;
};