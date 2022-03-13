/*By::Cebastian Santiago 
* CS315 Reading JSON Files 
* JSONTokenizer function implentation class
*/
#include<iostream>
#include"JSONTokenizer.hpp"
#include"JSONToken.hpp"
#include<string>
#include<iostream>

JSONTokenizer::JSONTokenizer(const std::string& inputFile):inputFileName{inputFile}{
	inputStream.open(inputFile, std::ios::in);
}

bool JSONTokenizer::ischarcter(char c) {
	if (c == '[' || c ==']' || c== '{' || c == '}' || c == '"' || c == ':' || c == ',') {
		return true;
	}

	return false;
}

JSONToken JSONTokenizer::getToken() {
	if (!inputStream.is_open()) {
		std::cout << "Input stream in Tokenizer::getToken is not open. Terminating...\n";
		exit(4);
	}

	char c;
	inputStream >> c;


	if ( c == '"') {
		std::string input;
		std::getline(inputStream, input,'"');
		JSONToken token(input);
		return token;
	}
	
	else if (inputStream.eof()) {
		JSONToken token;
		token.Eof();
		return token;
	}


	else if (isdigit(c)){
		inputStream.putback(c);
		std::string nums;

		while (inputStream >> c) {
			if (c == ',' || c == '}') {
				inputStream.putback(c);
				break;
			}
			nums.push_back(c);
		}
		JSONToken token(nums);
		return token;
		
	}

	else if (ischarcter(c)) {
		JSONToken token(c);
		return token;
	}

	else if(!ischarcter(c)) {
		std::cout << "Unexpected character in input ->" << c << "<-\n";
		std::cout << "Terminating...\n";
		exit(5);
	}

}
//exit(4) file could not be open
//exit(5) wrong input in file