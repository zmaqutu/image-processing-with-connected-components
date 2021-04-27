#include <iostream>
#include <string>

#include "PGMimageProcessor.h"
void runThis(){
	MQTZON001::PGMimageProcessor instance("data/coins.pgm");
	//MQTZON001::PGMimageProcessor instance = MQTZON001::PGMimageProcessor("data/baboon.pgm");
	//std::cout << instance.getId() << std::endl;
	//instance.read_from_file("sloan_image.pgm");
}

int main(int argc, char *argv[]){

	runThis();
	return 0;
}
