/*By Cebastian Santiago 
* CS315 JSONParser class header File
* 
*/
#pragma once
#ifndef JSONParser_HPP
#define JSONParser_HPP
#include<string>
#include"JSONTokenizer.hpp"
#include"EntityInstance.hpp"
#include"EntitySet.hpp"
#include"JSONToken.hpp"
#include"Pair.hpp"


class JSONParser {
public:
    /// <summary>
    /// constructer of the class 
    /// </summary>
    /// <param name="nameOfInputFile"></param>
    JSONParser(std::string nameOfInputFile);

    /// <summary>
    ///  Uses tokenizer and JSONToken two parse two tokens a string name 
    /// and a number or string value 
    /// </summary>
    /// <returns></returns>
    Pair parseAPair();


    /// <summary>
    /// parses a json instance form { to }
    /// </summary>
    /// <returns></returns>
    EntityInstance parseJSONObject();
    
    /// <summary>
    /// parses an entire json file 
    /// </summary>
    /// <returns></returns>
    EntitySet parseJSONEntity();

private:
    JSONTokenizer tokenizer; // the input file name is used to create an instance of JSONTokenizer
                             // please note that there is not an ampersand in front of "tokenizer"
};
#endif // !JSONParser_HPP
