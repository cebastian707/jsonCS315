#pragma once
#ifndef JSONToken_HPP
#define JSONToken_HPP
#include<iostream>
#include<string>


class JSONToken{
public:
	JSONToken():_isnumber{ false }, _isstring{ false }, _ischarcter{ false }, _eof{ false } {};


private:
	int _number;
	std::string _string;
	char _character;
	bool _isnumber, _isstring, _ischarcter,_eof;
};
#endif // !JSONToken_HPP