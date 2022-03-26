/*BY Cebastian Santiago 
* EntitySet Functions
*/
#include"EntityInstance.hpp"
#include"EntitySet.hpp"

EntitySet::EntitySet() {

}

std::vector<EntityInstance> EntitySet::getEntityInstances() {
	return instances;
}

void EntitySet::addEntity(EntityInstance&sets) {
	instances.push_back(sets);
}
