/*BY::Cebastian Santiago 
* EntitySet Header File
*/
#pragma once
#ifndef EntitySet_HPP
#define EntitySet_HPP
#include<vector>
#include"EntityInstance.hpp"

class EntitySet {
public:
    EntitySet();
    void addEntity(EntityInstance&sets);
    //void print();    // prints all instances of this Entity.
    std::vector<EntityInstance> getEntityInstances(); // returns "instances"
     // more member functions here.

private:
    std::vector<EntityInstance> instances;
};


#endif // EntitySet_HPP
