/*BY::Cebastian Santiago 
* 
*/
#include<iostream>
#include<iomanip>
#include "EquityStats.hpp"
#include"Pair.hpp"
#include"EntityInstance.hpp"
#include"EntitySet.hpp"

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
	EntityInstance inst;
	EntitySet set;
	
	average = firstaverage(days);
	Pair pair("EMA-12", average);
	instance[11].addPair(pair);

	entityset.clear();
	//entityset.push_back(set);
	
	for (size_t i = days-1; i < instance.size(); i++) {
		if (days == 12) {
			if (i >= days) {
				cur_value = instance[i].close();
				current = (cur_value * smooth) + average * (1 - smooth);
				average = current;
				Pair pair("EMA-12", average);
				instance[i].addPair(pair);
			}

		}

		else if( days == 26){
			if (i >= days) {
				cur_value = instance[i].close();
				current = (cur_value * smooth) + average * (1 - smooth);
				average = current;
			}

		}
	}

	for (size_t i = 0; i < instance.size(); i++) {
		set.addEntity(instance[i]);

	}



	entityset.push_back(set);
}
  
void EquityStats::print(std::vector<std::string> keys){
	for (size_t i = 0; i < entityset.size(); i++) {
		entityset[i].printInCSV(keys);
	}
}

double EquityStats::firstaverage(double days){
	double count = 0;
	double avg = 0;

	for (size_t i = 0; i <= days - 1; i++) {
		count += instance[i].close();
	}
	avg = count / days;
	return avg;
}





std::vector<EntityInstance> EquityStats::startinstance(){
	for (size_t i = 0; i < entityset.size(); i++) {
		instance = entityset[i].getEntityInstances();
	}
	return instance;
}


