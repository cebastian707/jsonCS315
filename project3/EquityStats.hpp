#pragma once
#ifndef EquityStats_HPP
#define EquityStats_HPP
#include<vector>
#include<string>
#include"EntitySet.hpp"
#include"EntityInstance.hpp"
class EquityStats{
public:
	EquityStats(EntitySet& instanceOfEntitySet);
	void calculateExponentialMovingAverage(double tweleve);
	void print(std::vector<std::string> keys);
	double firstaverage(double days);
private:
	std::vector<EntityInstance> startinstance();
	std::vector<EntitySet> entityset;
	std::vector<EntityInstance> instance;
};
#endif // !EquityStats_HPP
