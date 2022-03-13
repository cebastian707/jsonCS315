#pragma once
#ifndef JSONToken_HPP
#define JSONToken_HPP
#include<iostream>
#include<string>


class JSONToken{
public:
	JSONToken():_isnumber{ false }, _isstring{ false }, _ischarcter{ false }, _eof{ false } {};
	JSONToken(char c):_isnumber{false},
		_ischarcter{true},
		_eof{false},
		_character{ c },
		_isstring{ false } {}


	JSONToken(std::string input):_isnumber{false},_isstring{true},
		_eof{ false }, _string{ input } {}

	bool _isNumber() { return _isnumber; }
	bool _isString() { return _isstring; }
	bool _isCharcter() { return _ischarcter;}
	bool  endOfFile() { return _eof; }
	float number() { return _number; }
	std::string _ISString() { return _string; }

	void operators(char charct) {
		_character = charct;
		_ischarcter = true;
	}

	char is_charcter() { return _character;}
	
	void print();
	void Eof() { _eof = true; }
private:
	float _number;
	std::string _string;
	char _character;
	bool _isnumber, _isstring, _ischarcter,_eof;
};
#endif // !JSONToken_HPP