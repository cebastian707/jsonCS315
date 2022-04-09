#pragma once
#ifndef EquityStats_HPP
#define EquityStats_HPP
#include<fstream>
#include<vector>
#include<string>
#include"EntitySet.hpp"
#include"EntityInstance.hpp"
class EquityStats{
public:
	EquityStats(EntitySet& instanceOfEntitySet);
	void calculateExponentialMovingAverage(int tweleve);
	void calculateMACD();
	void calculateSignal(int days);
	void print(std::vector<std::string> keys);
	double firstaverage(int days);
private:
	int day = 0;
	std::vector<EntityInstance> startinstance();
	std::vector<EntitySet> entityset;
	std::vector<EntityInstance> instance;
};
#endif // !EquityStats_HPP
