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
	
private:
	std::vector<EntityInstance> startinstance();
	std::vector<EntitySet> entityset;
	std::vector<EntityInstance> instance;
};




#endif // !EquityStats_HPP
