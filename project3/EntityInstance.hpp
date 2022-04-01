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
    EntityInstance();
    void addPair(Pair& pair); // Add a new pair to this entity.
    int numAttributes();  // how many pairs are in this instance?
    std::vector<std::string> attributeNames();
    void printInCSV(std::vector<std::string> key_values);
    void printInJSON();   // prints this object. 
    // more member functions here when necessary.

    bool _ishigh(std::string key);
    bool _isdividends(std::string key);
    bool _isclose(std::string key);
    bool _isdate(std::string key);
    bool _isvolume(std::string key);
    bool _isopen(std::string key);


    double high();
    double dividends();
    double open();
    double volume();
    std::string date();
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

