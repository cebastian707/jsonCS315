/*Created by professor Ali A. Kooshesh SSU and modified by Cebastian Santiago
* CS315 DSA Reading Json Files
* Project 3 Phase Two
*/
#include<iostream>
#include<fstream>
#include"JSONTokenizer.hpp"
#include"JSONToken.hpp"
#include"JSONParser.hpp"
#include"EntityInstance.hpp"
#include"EntitySet.hpp"
#include"Pair.hpp"

int main(int argc, char* argv[]) {
    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);    // open for reading
    if (!inputStream.is_open()) {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        exit(2);
    }
    inputStream.close();
    
    JSONParser par(argv[1]);
    EntitySet set;
    EntityInstance instance;
    //set = par.parseJSONEntity();
    //set.printInJSON();
    par.parseJSONEntity();
    instance.attributeNames();
    
    return 0;
}
//exit(2) file could not be open 