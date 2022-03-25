/*By::Cebastian Santiago 
* CS315 Project 3
* EntityInstance Class 
*/
#pragma once
#ifndef EntityInstance_HPP
#define EntityInstance_HPP
#include<string>
#include"Pair.hpp"
#include<vector>

class EntityInstance {
public:
    void addPair(Pair& pair); // Add a new pair to this entity.
    int numAttributes();  // how many pairs are in this instance?
    std::vector<std::string> attributeNames();
    void print();   // prints this object. 
    // more member functions here when necessary.

    double close();   // an accessor function that return the
                      // value associated with an attribute. In this case, the value.
                      // of attribute, Close. You will need to add more such functions
                      // to this class.
private:
    double close_value = 0;
    std::vector<std::string> key;
    std::vector<Pair> entityPairs;
    int nums = 0;
    // more variables here as necessary.
};
#endif // !EntityInstance_HPP

