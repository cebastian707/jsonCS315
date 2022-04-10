/*By::Cebastian Santiago 
* CS315 Project 3
* EntityInstance Class 
*/
#pragma once
#ifndef EntityInstance_HPP
#define EntityInstance_HPP
#include"Pair.hpp"
#include<string>
#include<vector>

class EntityInstance {
public:
    /// <summary>
    /// Construct of the class
    /// </summary>
    EntityInstance();

    /// <summary>
    /// adds a pair form json attribuate name and attribuate string or number
    /// </summary>
    /// <param name="pair"></param>
    void addPair(Pair& pair); // Add a new pair to this entity.
    /// <summary>
    /// counts the number of attribuates
    /// </summary>
    /// <returns></returns>
    int numAttributes();  // how many pairs are in this instance?

    /// <summary>
    /// returns attribuate names of vector
    /// </summary>
    /// <returns></returns>
    std::vector<std::string> attributeNames();

    /// <summary>
    /// precondition::needs a vector of attribautes passed to it
    /// prints a csv file with commas
    /// </summary>
    /// <param name="key_values"></param>
    void printInCSV(std::vector<std::string> key_values);

    /// <summary>
    /// prints the json file passed to it human readable
    /// </summary>
    void printInJSON();   // prints this object. 
    // more member functions here when necessary.
    //all bool functions check if the key value 
    //is the current instance
    bool _isLow(std::string key);
    bool _ishigh(std::string key);
    bool _isdividends(std::string key);
    bool _isclose(std::string key);
    bool _isdate(std::string key);
    bool _isvolume(std::string key);
    bool _isopen(std::string key);
    bool _istimestamp(std::string key);
    bool _isstocksplit(std::string key);
    bool _isEMA12(std::string key);
    bool _isEMA26(std::string key);
    bool _isMACD(std::string key);
    bool _issignal(std::string key);

    //rest of function grab the attribuate value
    //form the key
    double Signal();
    double MACD();
    double EMA26();
    double EMA12();
    double stocksplit();
    double low();
    double high();
    double dividends();
    double open();
    double volume();
    std::string date();
    std::string timestamp();
    double close();   // an accessor function that return the
                      // value associated with an attribute. In this case, the value.
                      // of attribute, Close. You will need to add more such functions
                      // to this class.
private:
    double close_value;
    std::vector<std::string> key;
    std::vector<Pair> entityPairs;
    int nums;
    // more variables here as necessary.
};
#endif // !EntityInstance_HPP

