#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include "PGMimageProcessor.h"

namespace MQTZON001 {
	int pixelCount;
	int id;

	void PGMimageProcessor(int id){
		pixelCount = 0;
		this.id = setId(id);
	}
	~PGMimageProcessor(){
		std::cout << "Container Destroyed " << std::endl;
	}
		private:
	int PGMimageProcessor::getId(){
		return id;
	}
	int PGMimageProcessor::getPixelCount(){
		return pixelCount;
	}
	void PGMimageProcessor::setId(int containerId){
		this.id = containerId;
	}
}
