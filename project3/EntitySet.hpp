/*BY::Cebastian Santiago 
* EntitySet Header File
*/
#pragma once
#ifndef EntitySet_HPP
#define EntitySet_HPP
#include<fstream>
#include<string>
#include<vector>
#include"EntityInstance.hpp"

class EntitySet {
public:
    /// <summary>
    /// class contructor
    /// </summary>
    EntitySet();

    /// <summary>
    /// adds an instance of EntityInstance
    /// </summary>
    /// <param name="sets"></param>
    void addEntity(EntityInstance&sets);
    
    /// <summary>
    /// prints out put as a json file
    /// </summary>
    void printInJSON();    // prints all instances of this Entity.
    
    /// <summary>
    /// prints output as a csv file
    /// </summary>
    /// <param name="key_values"></param>
    void printInCSV(std::vector<std::string> key_values);
    
    std::vector<EntityInstance> getEntityInstances(); // returns "instances"
     // more member functions here.
private:
    std::vector<EntityInstance> instances;
};


#endif // EntitySet_HPP
