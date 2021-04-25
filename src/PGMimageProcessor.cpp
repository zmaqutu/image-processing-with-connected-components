#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include "PGMimageProcessor.h"

namespace MQTZON001 {
	PGMimageProcessor::PGMimageProcessor(int id){
		componentCount = 0;
		setId(id);
	}
	PGMimageProcessor::~PGMimageProcessor(){
		std::cout << "Container Destroyed " << std::endl;
	}
	int PGMimageProcessor::getId(){
		return id;
	}
	int PGMimageProcessor::getComponentCount(void) const {
		return componentCount;
	}
	void PGMimageProcessor::setId(int containerId){
		id = containerId;
	}
	void PGMimageProcessor::read_from_file(std::string fileName){
		std::ifstream file("data/sloan_image.pgm");
		std::string line;
		int rows, cols;

		std::getline(file,line);					//read P5
		//skip through comments
		while(std::getline(file,line)){
			if(line[0] != '#'){
				break;
			}
		}
		//get rows and cols from next line using split
		std::istringstream iss(line);
		iss >> rows;
		iss >> cols;

		std::cout << rows << "," << cols << std::endl;

		std::getline(file,line);					//read 255

	}
	int PGMimageProcessor::extractComponents(unsigned char threshold, int minValidSize){
		std::cout << threshold << std::endl;
		return -1;
	}
	int PGMimageProcessor::filterComponentsBySize(int minSize, int maxSize){
		std::cout << minSize << std::endl;
		return -1;
	}
	bool PGMimageProcessor::writeComponents(const std::string& outFileName){
		return false;
	}
	int PGMimageProcessor::getLargestSize(void) const {
		return -1;
	}
	int PGMimageProcessor::getSmallestSize(void) const{
		return -1;
	}
	void PGMimageProcessor::printComponentData(const ConnectedComponent & theComponent) const{
	}
}
