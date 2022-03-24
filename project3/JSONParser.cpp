#include<fstream>
#include<iostream>
#include<string>
#include"JSONParser.hpp"
#include"JSONTokenizer.hpp"
#include"JSONToken.hpp"
#include"EntityInstance.hpp"
#include"Pair.hpp"

Pair JSONParser::parseAPair() {
    JSONToken token = tokenizer.getToken();
    
    std::string attribute = "";
    std::string attribute_stringvalue = "";
    attribute_stringvalue.push_back('"');

    attribute.push_back('"');
    attribute = token._ISString();  
    attribute.push_back('"');

    token = tokenizer.getToken();
    char colon = token.is_charcter();
    attribute.push_back(colon);

    token = tokenizer.getToken();

    if (token.is_number()){
        double nums = token.nums();
        Pair pair(attribute, nums);
        return pair;
    }

    attribute_stringvalue = token._ISString();
    attribute_stringvalue.push_back('"');
    Pair pair(attribute, attribute_stringvalue);

    return pair;
}






JSONParser::JSONParser(const std::string& nameOfInputFile):tokenizer{nameOfInputFile} {
       
}


EntityInstance JSONParser::parseJSONObject() {
     // parseJSONObject is responsible for parsing a JSON object. As such,
     // the first token is expected to be an open brace.
     JSONToken token = tokenizer.getToken();
     if( ! token.isOpenBrace() ) {
         std::cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << std::endl;
         token.print();
         std::cout << "Terminating..." << std::endl;
         exit(1);
     }
     EntityInstance instance;
     
     do {
         Pair pair = parseAPair();         					  
         instance.addPair(pair);
         token = tokenizer.getToken();  
     } while(token.isComma() );  
     // after having read a pair, we expect a comma
     // So, the above loop terminates when we did find a comma. 
     // that means we have parsed an entire object. In that case, token must contain
     // the close brace of that object.
    
     
     if( ! token.isCloseBrace() ) {
         std::cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << std::endl;
         token.print();
         std::cout << "Terminating..." << std::endl;
         exit(1);
     }
     return instance;
}