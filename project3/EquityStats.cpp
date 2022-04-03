#include "EquityStats.hpp"
#include"Pair.hpp"

EquityStats::EquityStats(EntitySet& instanceOfEntitySet){
	entityset.push_back(instanceOfEntitySet);
}

double EquityStats::calculateExponentialMovingAverage(double tweleve){
	startinstance();
	average(tweleve);
	




	return 0.0;
}

double EquityStats::average(double avgdays){
	double count = 0;
	double average = 0;
    
	for (size_t i = 0; i < instance.size(); i++) {
		if (i == avgdays) {
			average = count / avgdays;
			return average;
		}
		count += instance[i].close();
	}
	
	return 0.0;
}



std::vector<EntityInstance> EquityStats::startinstance(){
	for (size_t i = 0; i < entityset.size(); i++) {
		instance = entityset[i].getEntityInstances();
	}
	return instance;
}


