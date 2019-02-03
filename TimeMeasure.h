#pragma once
#include <vector>

class TimeMeasure
{
private:
	double PCFreq;
	__int64 CounterStart;
public:
	TimeMeasure();
	~TimeMeasure();
	double getCounter() const;
	void startCounting();
	void saveToFile(std::vector<int>& czasy, std::string filename);
	void saveFile(std::vector<std::vector<int>>& czasy, std::string filename);
};