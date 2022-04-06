/*BY::Cebastian Santiago 
* 
*/
#include<iostream>
#include<iomanip>
#include<fstream>
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
	EntitySet set;
	
	average = firstaverage(days);


	if (days == 12) {
		Pair pair("EMA-12", average);
		instance[11].addPair(pair);
	}

	else if (days == 26) {
		Pair pair("EMA-26", average);
		instance[25].addPair(pair);
	}

	entityset.clear();
	
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
				Pair pair("EMA-26", average);
				instance[i].addPair(pair);
			}

		}
	}

	for (size_t i = 0; i < instance.size(); i++) {
		set.addEntity(instance[i]);

	}
	entityset.push_back(set);
}

void EquityStats::calculateMACD(){
	EntitySet set;
	double MACD_Result = 0;
	entityset.clear();

	for (size_t i = 0; i < instance.size(); i++) {
		if (instance[i].EMA12() != 0 || instance[i].EMA26() != 0) {
			MACD_Result = instance[i].EMA12() - instance[i].EMA26();
			if (i >= 25){
				Pair pair("MACD", MACD_Result);
				instance[i].addPair(pair);
			}
		}
	}

	for (size_t i = 0; i < instance.size(); i++) {
		set.addEntity(instance[i]);
	}
	entityset.push_back(set);
}

void EquityStats::calculateSignal(double days){
	EntitySet set;
	int x = 0;
	int j = 0;
	double count = 0;
	double current = 0;
	double average = 0;
	double smooth = 2.0 / (1 + days);
	entityset.clear();


	for (size_t i = 0; i < instance.size(); i++) {
		if (instance[i].MACD() != 0) {
			count += instance[i].MACD();
			j = i;
			x++;
			if (x == 9){
				break;
			}
		}
	}

	
	average = count / days;
	Pair pair("Signal", average);
	instance[j].addPair(pair);

	for (size_t i = j+1; i < instance.size(); i++) {
		current = (instance[i].MACD() * smooth) + average * (1 - smooth);
		average = current;
		Pair pair("Signal", current);
		instance[i].addPair(pair);
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

void EquityStats::printcsv(std::ofstream& out,std::vector<std::string> key){
	for (size_t i = 0; i < entityset.size(); i++) {
		entityset[i].printIncsv(out,key);
	}
}

double EquityStats::firstaverage(int days){
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