#include <iostream>
#include <string>

#include "PGMimageProcessor.h"
void runThis(){
	//MQTZON001::PGMimageProcessor instance("data/chess.pgm");
	//MQTZON001::PGMimageProcessor instance = MQTZON001::PGMimageProcessor("data/baboon.pgm");
	//std::cout << instance.getId() << std::endl;
	//instance.read_from_file("sloan_image.pgm");
}

int main(int argc, char * argv[]){
	int minValid, threshold = 0;
	//all flags are present
	if(argc < 8 ){
		std::cout << "The input format provided is incorrect, please provide the correct input arguments" << std::endl;
		return 0;
	}
	std::cout << argc << std::endl;
	if(argc == 10){
		std::string sFlag = argv[1];
		minValid = std::atoi(argv[2]);
		//maxValid = std::atoi(argv[3]);
		std::string tFlag = argv[4];
		threshold = std::atoi(argv[5]);
		std::string pFlag = argv[6];
		std::string wFlag = argv[7];
		std::string outputFileName = argv[8];
		std::string fileName = argv[9];
		MQTZON001::PGMimageProcessor instance(fileName);
		instance.extractComponents((unsigned char)threshold, minValid);
		instance.writeComponents(outputFileName);
		std::cout << "Output file created inside output_files/" << outputFileName << std::endl;
		
	}
	//no p flag but w flag
	if(argc == 9 && std::string(argv[6]) == "-w"){
		std::string sFlag = argv[1];
		minValid = std::atoi(argv[2]);
		//maxValid = std::atoi(argv[3]);
		std::string tFlag = argv[4];
		threshold = std::atoi(argv[5]);
		std::string wFlag = argv[6];	
		std::string outputFileName = argv[7];
		std::string fileName = argv[8];
		MQTZON001::PGMimageProcessor instance(fileName);
		instance.extractComponents((unsigned char)threshold, minValid);
                instance.writeComponents(outputFileName);
		std::cout << "Output file created inside output_files/" << outputFileName << std::endl;
	}
	//no w flag but p flag
	if(argc == 8 && std::string(argv[6]) == "-p"){
		std::string sFlag = argv[1];
		minValid = std::atoi(argv[2]);
		//maxValid = std:atoi(argv[3]);
		std::string tFlag = argv[4];
		threshold = std::atoi(argv[5]);
		std::string wFlag = argv[6];
		std::string fileName = argv[7];
		MQTZON001::PGMimageProcessor instance(fileName);
                instance.extractComponents((unsigned char)threshold, minValid);
                instance.printAllComponentData();
	}
	//runThis();
	return 0;
}
