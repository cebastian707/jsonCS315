/*Created by professor Ali A. Kooshesh SSU
* CS315 DSA Reading Json Files
* Project 3 Phase one
*/
#include<iostream>
#include<fstream>
#include"JSONTokenizer.hpp"
#include"JSONToken.hpp"
#include"JSONParser.hpp"
#include"EntityInstance.hpp"


int main(int argc, char* argv[]) {
    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);    // open for reading
    if (!inputStream.is_open()) {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        exit(2);
    }
    inputStream.close();
    

    JSONTokenizer jsonTokenizer(argv[1]); // The Tokenizer opens and reads from the input file.
    JSONToken token = jsonTokenizer.getToken();
    JSONParser par(argv[1]);
    EntityInstance intance;

    intance = par.parseJSONObject();
    intance.close();
    intance.print();


    /*
    while (!token.endOfFile()) {
        token.print();
        token = jsonTokenizer.getToken();
    }
    */
    return 0;
}
//exit(2) file could not be open 