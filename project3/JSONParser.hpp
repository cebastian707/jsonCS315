/*By Cebastian Santiago 
* CS315 JSONParser class header
* 
*/
#pragma once
#ifndef JSONParser_HPP
#define JSONParser_HPP
#include<string>
#include"JSONTokenizer.hpp"
#include"EntityInstance.hpp"
#include"JSONToken.hpp"
#include"Pair.hpp"


class JSONParser {
public:
    JSONParser(std::string nameOfInputFile);
    Pair parseAPair();
    EntityInstance parseJSONObject();
    //EntitySet parseJSONEntity();

private:
    JSONTokenizer tokenizer; // the input file name is used to create an instance of JSONTokenizer
                             // please note that there is not an ampersand in front of "tokenizer"
};
#endif // !JSONParser_HPP
