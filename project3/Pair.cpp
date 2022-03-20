/*By::Cebastian Santiago
* CS315 Pair implementation
* of the class
*/
#include<iostream>
#include"Pair.hpp"


Pair::Pair(std::string attributeName, std::string attributeValue) {
	attributeName = _attributeName;
	attributeValue = _attributeStringValue;
}

Pair::Pair(std::string attributeName,double num_value) {
	attributeName = _attributeName;
	num_value = _attributeNumberValue;
}


double Pair::numberValue() {
	return _attributeNumberValue;
}

bool Pair::isDouble() {
	return _isNumber;
}

std::string Pair::stringValue() {
	return _attributeStringValue;
}

std::string Pair::attributeName() {
	return _attributeName;
}
