#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
#include <sstream>
#include "ConnectedComponent.h"

namespace MQTZON001 {
	/*ConnectedComponent::ConnectedComponent(){
	}*/
	ConnectedComponent::ConnectedComponent(int id,int xStart,int yStart)
		:componentId(id),pixelCount(1)
	{
		pixelIndexes.insert({xStart,yStart});
	}
	//destructor
	ConnectedComponent::~ConnectedComponent(){
		pixelIndexes.clear();
		setPixelCount(0);
		setComponentId(0);
		std::cout << "Component Destroyed " << std::endl;
	}
	//copy constructor
	ConnectedComponent::ConnectedComponent(const ConnectedComponent & rhs)
		:componentId(rhs.componentId),pixelCount(rhs.pixelCount),pixelIndexes(rhs.pixelIndexes)
	{
	}
	//move constructor move(int) just copies anyway so no need to it
	ConnectedComponent::ConnectedComponent(ConnectedComponent && rhs)
		:componentId(rhs.componentId),pixelCount(rhs.pixelCount),pixelIndexes(std::move(rhs.pixelIndexes))
	{
	}
	//copy assignment operator overload
	ConnectedComponent & ConnectedComponent::operator=(const ConnectedComponent & rhs){
		if(this != &rhs){
			componentId = rhs.componentId;
			pixelCount = rhs.pixelCount;
			pixelIndexes = rhs.pixelIndexes;
			//aquire resources
			//release resources by deleting
			//assign resources tho "this" variables
		}
		return *this;
	}
	//move assignment operator overload
	ConnectedComponent & ConnectedComponent::operator=(ConnectedComponent && rhs){
		if(this != &rhs){
			pixelIndexes.clear();				//make sure its not pointing to anything before writing to it
			pixelIndexes = std::move(rhs.pixelIndexes);
			setComponentId(0);				//release the resource set it to point to nothing
			setPixelCount(0);
			//add delete to free up where the current set is pointing to
			componentId = rhs.componentId;
			pixelCount = rhs.pixelCount;
			rhs.pixelIndexes.clear();			//make sure rhs is deleted before exit scope
		}
		return *this;
	}
	int ConnectedComponent::getComponentId(){
		return componentId;
	}
	int ConnectedComponent::getPixelCount(void) const {
		return pixelCount;
	}
	void ConnectedComponent::setPixelCount(int count){
		pixelCount = count;
	}
	void ConnectedComponent::setComponentId(int containerId){
		componentId = containerId;
	}
}
