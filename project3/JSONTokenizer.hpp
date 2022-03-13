#pragma once
#ifndef JSONTokenizer_HPP
#define JSONTokenizer_HPP
#include<fstream>
#include<string>
#include"JSONToken.hpp"


class JSONTokenizer{
public:
	explicit JSONTokenizer(const std::string& inputFile);
	JSONToken getToken();

private:
	std::string inputFileName;
	std::fstream inputStream;
	char ischarcter(char c);
};
#endif // !JSONTokenizer_hpp