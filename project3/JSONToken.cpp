#include"JSONToken.hpp"
#include"JSONTokenizer.hpp"

void JSONToken::print() {
	if (_isNumber()){
		std::cout << number() << std::endl;
	}

	else if (_isCharcter()){
		std::cout << is_charcter() << std::endl;
	}

	else if(_isString()){
		std::cout << _ISString() << std::endl;
	}

	else if (endOfFile()) {
		std::cout << "EOF" << std::endl;
	}

	else{
		std::cout<<"Unknown token.";
	}
}
