/*By::Cebastian Santiago 
* CS315 Reading JSON Files 
* JSONTokenizer function implentation class
*/
#include<iostream>
#include"JSONTokenizer.hpp"
#include"JSONToken.hpp"
#include<string>



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
		 while (inputStream >> std::noskipws >> c) {
			 if (c == '\n' || c==' ') {
				 continue;
			 }


			 else if (c == '[') {
				 while (inputStream >> c) {
					 if (c == '{') {
						 JSONToken token(c);
						 return token;
					 }
				 }
			 

			 }


			 else  if (c == '"') {
				 std::string input = "";
				 input.push_back('"');

				 while (inputStream >>std::noskipws>> c) {
					 if (c == '"') {
						 input.push_back('"');
						 break;
					 }

					 input.push_back(c);
				 }

				 JSONToken token(input);
				 return token;
			 }

			 else if (inputStream.eof()) {
				 JSONToken token;
				 token.Eof();
				 return token;
			 }


			 else if (isdigit(c)) {
				 inputStream.putback(c);
				 double number = 0;
				 inputStream >> number;
				 JSONToken token;
				 token.make_number(number);
				 return token;
			 }

			 else if (ischarcter(c)) {
				 JSONToken token(c);
				 return token;
			 }

			 else if (!ischarcter(c)) {
				 std::cout << "Unexpected character in input ->" << c << "<-\n";
				 std::cout << "Terminating...\n";
				 exit(5);
			 }


		 }
		


		/*To aviod this complier warning even though the program should'nt reach all the way here
		* JSONTokenizer.cpp: In member function ‘JSONToken JSONTokenizer::getToken()’:
		*JSONTokenizer.cpp:68:1: warning: control reaches end of non-void function [-Wreturn-type] 68 | }
		* | ^
		*/

		JSONToken token;
		return token;
	
}
//exit(4) file could not be open
//exit(5) wrong input in file