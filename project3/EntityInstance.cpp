#include<iostream>
#include<string>
#include<vector>
#include"EntityInstance.hpp"
#include"Pair.hpp"


void EntityInstance::addPair(Pair& pair) {
	entityPairs.push_back(pair);
}

int EntityInstance::numAttributes() {
	return 0;
}
