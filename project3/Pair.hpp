/*BY Cebastian Santiago::CS315 Project 3 
* reading JSON files 
*/
#pragma once
#ifndef Pair_HPP
#define Pair_HPP
#include<string>

class Pair { // represents a single attribute and its value:
public:
    // use the first constructor if the value of the pair is a string
    // and use the second one if it is a double value.
    // Note that this class limits the data types of values to string and double.
    void printInJSON(int numSpaces);
    void printInCSV();
    Pair(std::string attributeName, std::string attributeValue);
    Pair(std::string attributeName, double num_value);
    bool isDouble();      // is the datatype of the value of this attribute a double?
    bool isStringvalue();
    bool isattributename();
    double numberValue();
    std::string stringValue();
    std::string attributeName();
private:
    std::string _attributeName, _attributeStringValue;
    double _attributeNumberValue;
    bool _isNumber,string_value, attributename;
};
#endif //Pair_HPP