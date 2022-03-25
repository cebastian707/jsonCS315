/*By::Cebastian Santiago
* EntityInstance Functions
*/
#include<iostream>
#include<string>
#include<vector>
#include"EntityInstance.hpp"
#include"Pair.hpp"
#include"JSONParser.hpp"


void EntityInstance::print() {
	for (size_t i = 0; i < entityPairs.size(); i++) {
		std::cout << entityPairs[i].attributeName() << std::endl;
	}
}

double EntityInstance::close() {
	return close_value;
}


std::vector<std::string>EntityInstance::attributeNames() {
	return key;
}


void EntityInstance::addPair(Pair& pair) {
	nums += 1;
	key.push_back(pair.attributeName());
	entityPairs.push_back(pair);

	if (pair.attributeName() == "Close:") {
		close_value = pair.numberValue();
	}
	
}

int EntityInstance::numAttributes() {
	return nums;
}



