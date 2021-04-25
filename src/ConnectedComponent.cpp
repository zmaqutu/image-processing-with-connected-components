#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include "ConnectedComponent.h"

namespace MQTZON001 {
	ConnectedComponent::ConnectedComponent(int id){
		pixelCount = 0;
		setComponentId(id);
	}
	ConnectedComponent::~ConnectedComponent(){
		std::cout << "Component Destroyed " << std::endl;
	}
	int ConnectedComponent::getId(){
		return componentId;
	}
	int ConnectedComponent::getPixelCount(void) const {
		return pixelCount;
	}
	void ConnectedComponent::setComponentId(int containerId){
		componentId = containerId;
	}
}
