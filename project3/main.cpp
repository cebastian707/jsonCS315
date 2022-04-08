/*Created by professor Ali A. Kooshesh SSU and modified by Cebastian Santiago
* CS315 DSA Reading Json Files
* Project 3 Phase Two
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"JSONTokenizer.hpp"
#include"JSONToken.hpp"
#include"JSONParser.hpp"
#include"EntityInstance.hpp"
#include"EntitySet.hpp"
#include"Pair.hpp"
#include"EquityStats.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3){
        std::cout << "Programm needs three arguments goodbye" << std::endl;
        exit(2);
    }
    
    std::string one = argv[1];
    std::string arg1 = "";
    std::ifstream inputStream;
    inputStream.open(argv[2], std::ios::in);    // open for reading

    for (size_t i = 1; i < one.size(); i++) {
        arg1.push_back(one[i]);
    }

    if (!inputStream.is_open()) {
        std::cout << "Unable top open " << argv[2] << ". Terminating...";
        exit(2);
    }

    inputStream.close();
    JSONParser par(argv[2]);
    EntitySet set; 
    std::vector<std::string> keyValues = { "Date","Open","High","Low","Close","Volume","EMA-12", "EMA-26", "MACD", "Signal" };
  
    if (arg1 == "csv") {
        set = par.parseJSONEntity();
        EquityStats stats(set);
        stats.calculateExponentialMovingAverage(12);
        stats.calculateExponentialMovingAverage(26);
        stats.calculateMACD();
        stats.calculateSignal(9);
        stats.print(keyValues);
        std::cout << std::endl;
        exit(0);
    }

    else if (arg1 == "json") {
        set = par.parseJSONEntity();
        set.printInJSON();
        exit(0);
    }


    if ( arg1 != "csv" || arg1 != "json") {
        std::cout << "The program only runs json files or csv files " << argv[1] << std::endl;
        std::cout << "The file input extension is incorrect restart the program and run again!" << std::endl;
        exit(2);
    }



    return 0;
}
//exit(2) file could not be open or arguments not met
//exit(0) program runs as excpeted