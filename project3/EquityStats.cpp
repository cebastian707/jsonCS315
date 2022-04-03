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
	double smooth = 2.0;
	double smooth_answer = 0;
	double _days = days;
	double current = 0;


	for (size_t i = 0; i < instance.size(); i++) {
		if (i == 0){
			std::cout <<  instance[i].close() << std::endl;

		}
		
		
	}
}





std::vector<EntityInstance> EquityStats::startinstance(){
	for (size_t i = 0; i < entityset.size(); i++) {
		instance = entityset[i].getEntityInstances();
	}
	return instance;
}


