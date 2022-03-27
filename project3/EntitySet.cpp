/*BY Cebastian Santiago 
* EntitySet Functions
*/
#include<iostream>
#include"EntityInstance.hpp"
#include"EntitySet.hpp"



void EntitySet::print() {
	std::cout << "[" << std::endl;

	for (size_t i = 0; i < instances.size(); i++) {
		instances[i].print();
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
