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

int main(int argc, char* argv[]) {
    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);    // open for reading
    if (!inputStream.is_open()) {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        exit(2);
    }
    inputStream.close();
    
    std::ofstream output;
    JSONParser par(argv[1]);
    EntitySet set;
    std::vector<std::string> keyValues = { "Date","Open","High","Low","Close","Volume","EMA-12", "EMA-26", "MACD", "Signal" };
    //std::vector<std::string> keyValues = { "Date" , "Volume", "Close", "EMA-12", "EMA-26", "MACD", "Signal" };

    output.open(argv[2], std::ios::out | std::ios::app);



    set = par.parseJSONEntity();


    set.printInCSV(keyValues);
    set.printIncsv(output, keyValues);
    


    return 0;
}
//exit(2) file could not be open 