/*By::Cebastian Santiago
* CS315 Reading JSON Files
* Phase One
*/
#pragma once
#ifndef JSONToken_HPP
#define JSONToken_HPP
#include<iostream>
#include<string>

class JSONToken{
public:
	/// <summary>
	/// constructer For the class
	/// </summary>
	JSONToken();

	/// <summary>
	/// Constructer the param sets the 
	/// token value passed form the the JSONTokenizer 
	/// class equal to our private variable and the boolean variable 
	/// _ischarcter changes to true since we have a char that 
	/// is being tokenized
	/// </summary>
	/// <param name="c"></param>
	JSONToken(const char c);

	/// <summary>
	/// Constructer the param 
	/// is called form the JSONToknizer class pass it 
	/// the string toke and set the string equal to are private varible 
	/// string and the _isstring is changed to true since what we passed
	/// is a string
	/// </summary>
	/// <param name="input"></param>
	JSONToken(const std::string input);
	
	/// <summary>
	/// Returns the _isstring boolean variable
	/// </summary>
	bool _isString();

	/// <summary>
	/// Returns the _isscharcter boolean variable 
	/// </summary>
	bool _isCharcter();

	/// <summary>
	/// returns _eof boolean variable
	/// </summary>
	bool  endOfFile();

	/// <summary>
	/// returns _string variable 
	/// </summary>
	std::string _ISString();
	
	/// <summary>
	/// returns _character
	/// </summary>
	char is_charcter();

	/// <summary>
	/// print the values read form the json file 
	/// but first check if the value is the correct
	/// input 
	/// </summary>
	void print();
	
	/// <summary>
	/// sets end of file equal to true
	/// </summary>
	void Eof();

	/// @brief 
	/// @returns the boolean variable _isnumber
	bool is_number();

	/// @brief prints the 
	/// number from JSON file 
	/// we use double variable and setprecision
	/// to print the decimal numbers
	double nums();
	
	/// @brief sets the token nums equal to number
	/// and boolean variable equal to true
	void make_number(double nums);

	/// @brief checks if charcter is {
	/// @returns true if it is else returns false
	bool isOpenBrace();

	/// @brief checks if charcter a comma
	/// @returns true if comma is true and else false 
	bool isComma();

	/// @brief checks if charcter is {
	/// @returns true if it is else returns false; 
	bool isCloseBrace();
private:
	std::string _string;
	char _character;
	double number;
	bool  _isstring,_isnumber, _ischarcter,_eof;
};
#endif // !JSONToken_HPP