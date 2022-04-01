/*By::Cebastian Santiago
* CS315 Pair implementation
* of the class
*/
#include<iostream>
#include<iomanip>
#include"Pair.hpp"


void Pair::printInCSV() {
	if (isDouble()){
		std::cout << std::setprecision(13)<< _attributeNumberValue << " ";
	}

	else{
		std::cout << _attributeStringValue <<" ";
	}
}


void Pair::printInJSON(int numspaces) {
	for (size_t i = 0; i <= numspaces; i++){
		std::cout << " ";
	}

	std::cout  << _attributeName;

	if (isDouble()){
		std::cout << std::setprecision(13) << _attributeNumberValue << std::endl;
	}
	
	else{
		std::cout << _attributeStringValue << std::endl;
	}
}



Pair::Pair(std::string attributeName, std::string attributeValue) {
	_isNumber = false;
	_attributeName = attributeName;
	_attributeStringValue = attributeValue;
}

Pair::Pair(std::string attributeName,double num_value) {
	_isNumber = true;
	_attributeName = attributeName;
    _attributeNumberValue = num_value;

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
