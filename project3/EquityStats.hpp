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
	double calculateExponentialMovingAverage(double tweleve);
	double average(double avgdays);
	
private:
	std::vector<EntityInstance> startinstance();
	std::vector<EntitySet> entityset;
	std::vector<EntityInstance> instance;
};




#endif // !EquityStats_HPP
