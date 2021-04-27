#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
#include <sstream>
#include "ConnectedComponent.h"

namespace MQTZON001 {
	/*ConnectedComponent::ConnectedComponent(){
	}*/
	ConnectedComponent::ConnectedComponent(int id,int startRow,int startCol)
		:componentId(id),pixelCount(0)
	{
		pixelIndexes.insert({startRow,startCol});
		pixelCount++;
	}
	//destructor
	ConnectedComponent::~ConnectedComponent(){
		pixelIndexes.clear();
		//setPixelCount(0);
		//setComponentId(0);
		//std::cout << "Component Destroyed " << std::endl;
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
	void ConnectedComponent::addPixel(int row, int col){
		pixelIndexes.insert({row,col});
		//setPixelCount(pixelIndexes.size());
		pixelCount++;
		std::cout << "added a pixel to component " << componentId << std::endl;
		//MQTZON001::ConnectedComponent::pixelCount++;
	}
	int ConnectedComponent::getComponentId(){
		return componentId;
	}
	int ConnectedComponent::getPixelCount(void){
		return pixelCount;
	}
	void ConnectedComponent::setPixelCount(int count){
		pixelCount = count;
	}
	void ConnectedComponent::incrementPixelCount(void){
		pixelCount++;
	}
	void ConnectedComponent::setComponentId(int containerId){
		componentId = containerId;
	}
}
