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

void EntityInstance::printIncsv(std::ofstream& out, std::vector<std::string> key) {
	out << std::endl;
	for (size_t i = 0; i < key.size(); i++) {
		if (_isclose(key[i])) {
			out << std::fixed << std::setprecision(4) << close() << ",";
		}

		else if (_isdate(key[i])) {
			out << date() << ",";
		}

		else if (_isvolume(key[i])) {
			out << volume() << ",";
		}


		else if (_isopen(key[i])) {
			out << std::fixed << std::setprecision(4) << open() << ",";

		}

		else if (_isdividends(key[i])) {
			out << std::fixed << std::setprecision(4) << dividends() << ",";
		}

		else if (_ishigh(key[i])) {
			out << std::fixed << std::setprecision(4) << high() << ",";
		}

		else if (_isLow(key[i])) {
			out << std::fixed << std::setprecision(4) << low() << ",";
		}

		else if (_istimestamp(key[i])) {
			out << timestamp() << ",";
		}

		else if (_isstocksplit(key[i])) {
			out << std::fixed << std::setprecision(4) << stocksplit() << ",";
		}


		else {
			out << "    ";
		}

	}
}

bool EntityInstance::_isLow(std::string key){
	std::string low = "Low";

	if (low == key){
		return true;
	}

	return false;
}

void EntityInstance::printInCSV(std::vector<std::string> key_values) {
	std::cout << std::endl;
	
	for (size_t i = 0; i < key_values.size(); i++) {
		if (_isclose(key_values[i])) {
			std::cout<< "    " << std::fixed << std::setprecision(4) << close() << ",";
		}
		
		else if(_isdate(key_values[i])){
			std::cout  << date() << ",       ";
		}
		
		else if (_isvolume(key_values[i])) {
			std::cout<< "       " << std::fixed << std::setprecision(4) << volume() << ",";
		}

		
		else if (_isopen(key_values[i])) {
			std::cout  << "   " << std::fixed << std::setprecision(4) << open() << ",";
		}
		
		else if (_isdividends(key_values[i])) {
			std::cout<<"    " << std::setprecision(13) << dividends() << ",";
		}

		
		else if (_ishigh(key_values[i])) {
			std::cout << "       " << std::fixed << std::setprecision(4) << high() << ",";
		}
		

		else if (_isLow(key_values[i])) {
			std::cout << "       " <<std::fixed << std::setprecision(4) << low() << ",";
		}


		else if (_istimestamp(key_values[i])) {
			std::cout << "      " << timestamp() << ",";
		}

		else if (_isstocksplit(key_values[i])){
			std::cout << "            " << std::fixed << std::setprecision(4) << stocksplit() << ",";
		}

		else{
			std::cout <<" ";
		}
	
	}
}



EntityInstance::EntityInstance() {
	close_value = 0;
	nums = 0;
}

void EntityInstance::printInJSON() {
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
	std::cout << std::setw(6) << "}";
}

bool EntityInstance::_ishigh(std::string key){
	std::string high = "High";

	if (key == high){
		return true;
	}
	return false;
}

bool EntityInstance::_isdividends(std::string key){
	std::string divid = "Dividends";
	
	if (key == divid){
		return true;
	}

	return false;
}

bool EntityInstance::_isclose(std::string key){
	std::string close = "Close";
	
	if (close == key){
		return true;
	}
	
	return false;
}

bool EntityInstance::_isdate(std::string key){
	std::string date = "Date";

	if (date == key){
		return true;
	}

	return false;
}

bool EntityInstance::_isvolume(std::string key){
	std::string volume = "Volume";

	if (volume == key){
		return true;
	}
	return false;
}

bool EntityInstance::_isopen(std::string key){
	std::string open = "Open";

	if (key == open){
		return true;
	}
	
	return false;
}

bool EntityInstance::_istimestamp(std::string key){
	std::string time = "Timestamp";

	if (key == time){
		return true;
	}

	return false;
}

bool EntityInstance::_isstocksplit(std::string key){
	std::string split = "Stock Splits";

	if (key == split){
		return true;
	}


	return false;
}

double EntityInstance::stocksplit(){
	std::string stock = "\"Stock Splits\" :";

	for (size_t i = 0; i < entityPairs.size(); i++) {
		if (stock == entityPairs[i].attributeName()) {
			return entityPairs[i].numberValue();
		}
	}

	return 0.0;
}

double EntityInstance::low(){
	std::string low = "\"Low\" :";

	for (size_t i = 0; i < entityPairs.size(); i++) {
		if (low == entityPairs[i].attributeName()) {
			return entityPairs[i].numberValue();
		}
	}

	return 0.0;
}

double EntityInstance::high(){
	std::string high = "\"High\" :";

	for (size_t i = 0; i < entityPairs.size(); i++) {
		if (high == entityPairs[i].attributeName()) {
			return entityPairs[i].numberValue();
		}
	}
	return 0.0;
}

double EntityInstance::dividends(){
	std::string dividends = "\"Dividends\" :";
	double dividend = 0;

	for (size_t i = 0; i < entityPairs.size(); i++) {
		if (entityPairs[i].attributeName() == dividends) {
			dividend =  entityPairs[i].numberValue();
		}
	}
	return dividend;
}

double EntityInstance::open(){
	std::string open = "\"Open\" :";

	for (size_t i = 0; i < entityPairs.size(); i++) {
		if (entityPairs[i].attributeName() == open) {
			return entityPairs[i].numberValue();
		}
	}

	return 0.0;
}

double EntityInstance::volume(){
	std::string vol = "\"Volume\" :";

	for (size_t i = 0; i < entityPairs.size(); i++) {
		if (entityPairs[i].attributeName() == vol) {
			return entityPairs[i].numberValue();
		}
	}

	return 0;
}

std::string EntityInstance::date(){
	std::string dat = "\"Date\" :";
	
	for (size_t i = 0; i < entityPairs.size(); i++) {
		if (entityPairs[i].attributeName() == dat) {
			return entityPairs[i].stringValue();
		}
	}

	return std::string();
}

std::string EntityInstance::timestamp(){
	std::string time = "\"Timestamp\" :";

	for (size_t i = 0; i < entityPairs.size(); i++) {
		if (time == entityPairs[i].attributeName()) {
			return entityPairs[i].stringValue();
		}
	}
	return std::string();
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
	std::vector<std::string> names;

	for (size_t i = 0; i < entityPairs.size(); i++) {
		names.push_back(entityPairs[i].attributeName());
	}

	return names;
}


void EntityInstance::addPair(Pair& pair) {
	nums += 1;
	entityPairs.push_back(pair);
}

int EntityInstance::numAttributes() {
	return nums;
}