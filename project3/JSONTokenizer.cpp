#include<iostream>
#include"JSONTokenizer.hpp"
#include"JSONToken.hpp"
#include<string>
#include<iostream>

JSONTokenizer::JSONTokenizer(const std::string& inputFile):inputFileName{inputFile}{
	inputStream.open(inputFile, std::ios::in);
}

char JSONTokenizer::ischarcter(char c) {
	return c == '[' || c == '{' || c == '"' || c == ':'  || c == ',' || c == '}' || c == ']';
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
	
	if (inputStream.eof()) {
		JSONToken token;
		token.Eof();
		return token;
	}


	if (isdigit(c)){
		inputStream.putback(c);
		std::string nums;

		while (inputStream >> c) {
			if (c == ',' || c == '}') {
				inputStream.putback(c);
				break;
			}

			nums += c;
		}
		JSONToken token(nums);
		return token;
	}
	


	if (ischarcter(c)) {
		JSONToken token(c);
		return token;
	}

}
