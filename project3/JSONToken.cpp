/*By::Cebastian Santiago
* CS315 JSONToken implementation
* of the JSONToken class
*/
#include"JSONToken.hpp"
#include"JSONTokenizer.hpp"
#include<iomanip>
#include<iostream>





bool JSONToken::iscloseBracket() {
	if (_character == ']') {
		return true;
	}

	return false;
}

bool JSONToken::isCloseBrace() {
	if (_character == '}' || _character == '{') {
		return true;
	}
	return false;
}

bool JSONToken::isComma() {
	if (_character == ',') {
		return true;
	}
	return false;
}

bool JSONToken::isOpenBrace() {
	if (_character == '{' || _character == '[') {
		return true;
	}

	return false;
}

void JSONToken::make_number(double nums) {
	number = nums;
	_isnumber = true;
}

double JSONToken::nums() {
	//std::cout<<std::setprecision(13)<< number <<  std::endl;
	return number;
}

bool JSONToken::is_number() {
	return _isnumber;
}

void JSONToken::Eof() {
	_eof = true;
}

char JSONToken::is_charcter() {
	return _character;
}

std::string JSONToken::_ISString() {
	return _string;
} 

bool JSONToken::endOfFile() {
	return _eof;
}

bool JSONToken::_isCharcter() {
	return _ischarcter;
}

bool JSONToken::_isString() {
	return _isstring;
}

JSONToken::JSONToken() {
	_isstring = false; 
	_ischarcter = false;
	_eof = false;
	_character = '\n';
	_string = " ";
	_isnumber = false;
}

JSONToken::JSONToken(const char c) {
	_ischarcter = true;
	_eof = false;
	_character = c;
	_isstring = false;
	_isnumber = false;
	number = 0;

}

JSONToken::JSONToken(const std::string input) {
	_string = input;
	_isstring = true;
	_eof = false;
	_ischarcter = false;
	_character = ' ';
	_isnumber = false;
}

void JSONToken::print() {
    if (_isString()) {
		std::cout << _ISString() << std::endl;
	}

	else if (is_number()) {
		std::cout << std::setprecision(13) << nums() << std::endl;
	}

	else if (_isCharcter()){
		std::cout << is_charcter() << std::endl;
	}

	else if (endOfFile()) {
		std::cout << "EOF" << std::endl;
	}

	else{
		std::cout<<"Unknown token.";
	}
}
