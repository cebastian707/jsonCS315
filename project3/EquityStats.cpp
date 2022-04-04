#include<iostream>
#include<iomanip>
#include "EquityStats.hpp"
#include"Pair.hpp"

EquityStats::EquityStats(EntitySet& instanceOfEntitySet){
	entityset.push_back(instanceOfEntitySet);
}


void EquityStats::calculateExponentialMovingAverage(double days){
	startinstance();
	double count = 0;
	double average = 0;
	double smooth = 2.0 / (1 + days);
	double current = 0;
	double cur_value = 0;

	for (size_t i = 0; i <= days-1; i++){
		count += instance[i].close();
	}
	average = count / days;

	avg.push_back(average);

	for (size_t i = days-1; i < instance.size(); i++) {
		if (i >= days){
			cur_value = instance[i].close();
			current = (cur_value * smooth) + average * (1-smooth);
			average = current;
			avg.push_back(current);
		}


	}
}

void EquityStats::print(std::vector<std::string> keys){
	for (size_t i = 0; i < entityset.size(); i++) {
		entityset[i].printInCSV(keys);
	}
}





std::vector<EntityInstance> EquityStats::startinstance(){
	for (size_t i = 0; i < entityset.size(); i++) {
		instance = entityset[i].getEntityInstances();
	}
	return instance;
}


