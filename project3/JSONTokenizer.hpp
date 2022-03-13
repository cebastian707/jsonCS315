/*By:: Cebastian Santiago
* JSONTokenizer Class Header
* Function
*/

#pragma once
#ifndef JSONTokenizer_HPP
#define JSONTokenizer_HPP
#include<fstream>
#include<string>
#include"JSONToken.hpp"


class JSONTokenizer{
public:
	/// <summary>
	/// check of the given file is open
	/// </summary>
	/// <param name="inputFile"></param>
	explicit JSONTokenizer(const std::string& inputFile);
	
	/// <summary>
	/// Checks the charcter read and depending 
	/// on what that value is it either is a char 
	/// charcter a string with " " or a number but we 
	/// read it as a string
	/// </summary>
	/// <returns></returns>
	JSONToken getToken();

private:
	std::string inputFileName;
	std::fstream inputStream;
	bool ischarcter(char c);
};
#endif // !JSONTokenizer_HPP