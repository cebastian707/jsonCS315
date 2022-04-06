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
	void calculateExponentialMovingAverage(double tweleve);
	void calculateMACD();
	void calculateSignal(double days);
	void print(std::vector<std::string> keys);
	void printcsv(std::ofstream& out,std::vector<std::string> key);
	double firstaverage(int days);
private:
	std::vector<EntityInstance> startinstance();
	std::vector<EntitySet> entityset;
	std::vector<EntityInstance> instance;
};
#endif // !EquityStats_HPP
