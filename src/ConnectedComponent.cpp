#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include "ConnectedComponent.h"

namespace MQTZON001 {
	ConnectedComponent::ConnectedComponent(int id)
		:componentId(id),pixelCount(0)
	{
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
	int ConnectedComponent::getId(){
		return componentId;
	}
	int ConnectedComponent::getPixelCount(void) const {
		return pixelCount;
	}
	void ConnectedComponent::setPixelCount(int count) const{
		pixelCount = count;
	}
	void ConnectedComponent::setComponentId(int containerId){
		componentId = containerId;
	}
}
