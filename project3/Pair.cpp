/*By::Cebastian Santiago
* CS315 Pair implementation
* of the class
*/
#include<iostream>
#include"Pair.hpp"


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
