/*BY::Cebastian Santiago 
* EntitySet Header File
*/
#pragma once
#ifndef EntitySet_HPP
#define EntitySet_HPP
#include<string>
#include<vector>
#include"EntityInstance.hpp"

class EntitySet {
public:
    EntitySet();
    void addEntity(EntityInstance&sets);
    void printInJSON();    // prints all instances of this Entity.
    void printInCSV(std::vector<std::string> key_values);
    std::vector<EntityInstance> getEntityInstances(); // returns "instances"
     // more member functions here.

private:
    std::vector<EntityInstance> instances;
};


#endif // EntitySet_HPP
