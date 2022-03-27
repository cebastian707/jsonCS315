/*By::Cebastian Santiago
* EntityInstance Functions
*/
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include"EntityInstance.hpp"
#include"Pair.hpp"
#include"JSONParser.hpp"


EntityInstance::EntityInstance() {
	close_value = 0;
	nums = 0;
}

void EntityInstance::print() {
	std::cout << std::setw(6) << "{" << std::endl;
	for (size_t i = 0; i < entityPairs.size(); i++) {
		std::cout <<"      "<< entityPairs[i].attributeName() << " ";

		if (entityPairs[i].isDouble()) {
			std::cout << std::setprecision(13) << entityPairs[i].numberValue();
		}
		
		std::cout << entityPairs[i].stringValue();
		
		
		if (i != entityPairs.size()-1){
			std::cout << ',' << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::setw(6) << "}" << std::endl;
}

double EntityInstance::close() {
	std::string close = "\"Close\" :";
	for (size_t i = 0; i < entityPairs.size(); i++) {
		if (entityPairs[i].attributeName() == close) {
			close_value = entityPairs[i].numberValue();
			break;
		}
	}
	return close_value;
}


std::vector<std::string>EntityInstance::attributeNames() {
	for (size_t i = 0; i < entityPairs.size(); i++) {
		key.push_back(entityPairs[i].attributeName());
	}
	return key;
}


void EntityInstance::addPair(Pair& pair) {
	nums += 1;
	entityPairs.push_back(pair);
}

int EntityInstance::numAttributes() {
	return nums;
}



