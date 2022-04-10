/*By Cebastian Santiago 
* CS315 JSONParser class functions
*/
#include<iostream>
#include<string>
#include"JSONParser.hpp"
#include"JSONTokenizer.hpp"
#include"JSONToken.hpp"
#include"EntityInstance.hpp"
#include"EntitySet.hpp"
#include"Pair.hpp"

Pair JSONParser::parseAPair() {
    //get the current token and check if its a string 
    //if not kick the user out
    JSONToken token = tokenizer.getToken();  
    
    if (token._isString()){
        
        JSONToken token2 = tokenizer.getToken();
        //check if we have a colon and conintue to read either a string 
        //value or a number
        if (token2.iscolon()){
            token2 = tokenizer.getToken();
            
            if (token2.is_number()){
                Pair pair(token._ISString(), token2.nums());
                return pair;
            }

            else if(token2._isString()) {
                Pair pair(token._ISString(), token2._ISString());
                return pair;
            }

            else if (!token2.is_number() && !token2._isString()){
                std::cout << "Error: JSONParser::parseAPair: Expected a number or string value but found" << std::endl;
                token.print();
                std::cout << "Terminating..." << std::endl;
                exit(1);
            }

        }

        else if (!token2.iscolon()){
            std::cout << "Error: JSONParser::parseAPair: Expected a Colon but found" << std::endl;
            token.print();
            std::cout << "Terminating..." << std::endl;
            exit(1);
        }


    }

    else {
        std::cout << "Error: JSONParser::parseAPair: Expected a string but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }


    Pair pair("0", 0);
    return pair;
}

JSONParser::JSONParser(std::string nameOfInputFile):tokenizer{nameOfInputFile} {
       
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

EntitySet JSONParser::parseJSONEntity() {
    EntitySet set;
    EntityInstance instance;
    JSONToken token;
    token = tokenizer.getToken();
    //get the first token and make sure its a [
    //if its a [ call other two functions and add
    //an instance and entityse and return set 
    //if not [ kick the user out
    if (!token.isBracket()){
        std::cout << "Error: JSONParser::parseJSONEntity:: Expected an close brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
 
    do{
      instance = parseJSONObject();
      set.addEntity(instance);
      token = tokenizer.getToken();
    } while (!token.isBracket());

    return set;
}
