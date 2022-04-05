/*BY Cebastian Santiago 
* EntitySet Functions
*/
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include"EntityInstance.hpp"
#include"EntitySet.hpp"

void EntitySet::printInCSV(std::vector<std::string> key_values){ 
	for (size_t i = 0; i < key_values.size(); i++) {
		std::cout<<"   " << key_values[i] << ",         ";
	}

	for (size_t i = 0; i < instances.size(); i++) {
		instances[i].printInCSV(key_values);
	}
}

void EntitySet::printIncsv(std::ofstream& out, std::vector<std::string> key){
	for (size_t i = 0; i < key.size(); i++) {
		out << key[i] << ",";
	}

	for (size_t i = 0; i < instances.size(); i++) {
		instances[i].printIncsv(out, key);
	}
}




void EntitySet::printInJSON() {
	std::cout << "[" << std::endl;

	for (size_t i = 0; i < instances.size(); i++) {
		instances[i].printInJSON();
		if (i != instances.size()-1){
			std::cout << "," << std::endl;
		}

	}
	std::cout << std::endl;
	std::cout<< "]" << std::endl;

}


EntitySet::EntitySet() {

}

std::vector<EntityInstance> EntitySet::getEntityInstances() {	
	return instances;
}

void EntitySet::addEntity(EntityInstance&sets) {
	instances.push_back(sets);
}
