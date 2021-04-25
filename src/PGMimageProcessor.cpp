#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include "PGMimageProcessor.h"

namespace MQTZON001 {
	//default constructor
	PGMimageProcessor::PGMimageProcessor(void)
		:fileName(""),imageArray(nullptr),rows(0),cols(0),componentCount(0)
	{
	}
	//other constructor
	PGMimageProcessor::PGMimageProcessor(std::string imageFileName) 
		: fileName(imageFileName),imageArray(nullptr),rows(0),cols(0),componentCount(0)
	{
		read_from_file();
	}
	//destructor
	PGMimageProcessor::~PGMimageProcessor(){
		if(imageArray != nullptr){
			for(int i = 0; i < rows;i++){
				delete [] imageArray[i];
			}
		}
		delete [] imageArray;
		std::cout << "Container Destroyed " << std::endl;
	}
	int PGMimageProcessor::getRows(){
		return rows;
	}
	int PGMimageProcessor::getCols(){
		return cols;
	}
	int PGMimageProcessor::getComponentCount(void) const {
		return componentCount;
	}
	/*void PGMimageProcessor::setId(int containerId){
		id = containerId;
	}*/
	void PGMimageProcessor::read_from_file(){
		std::ifstream file(fileName, std::ios::binary);
		std::string line;

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
		imageArray = new unsigned char*[rows];
		for(int i = 0; i < rows;i++){
			imageArray[i] = new unsigned char[cols];
		}
		while(file){
			for(int i = 0; i < rows;i++){
				file.read((char*)imageArray[i],cols);
			}
		}
		for(int x = 0; x < 5;x++){
			for(int y = 0; y < 5; y++){
				std::cout << imageArray[x][y] << std::endl;
			}
		}
		file.close();

		std::ofstream outputFile("dump_files/bab.pgm", std::ios::binary);

		outputFile << "P5" << std::endl;
		outputFile << rows << " " << cols << std::endl;
		outputFile << "255" << std::endl;

		for(int x = 0; x < rows; x++){
			outputFile.write((char*)imageArray[x],cols);
		}
		outputFile.close();


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
