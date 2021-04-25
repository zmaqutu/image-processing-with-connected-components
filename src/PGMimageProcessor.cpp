#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include "PGMimageProcessor.h"

namespace MQTZON001 {
	PGMimageProcessor::PGMimageProcessor(int id){
		pixelCount = 0;
		setId(id);
	}
	PGMimageProcessor::~PGMimageProcessor(){
		std::cout << "Container Destroyed " << std::endl;
	}
	int PGMimageProcessor::getId(){
		return id;
	}
	int PGMimageProcessor::getPixelCount(){
		return pixelCount;
	}
	void PGMimageProcessor::setId(int containerId){
		id = containerId;
	}
}
