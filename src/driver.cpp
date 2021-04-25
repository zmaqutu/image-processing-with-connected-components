#include <iostream>
#include <string>

#include "PGMimageProcessor.h"
void runThis(){
	MQTZON001::PGMimageProcessor instance = MQTZON001::PGMimageProcessor(10);
	std::cout << instance.getId() << std::endl;
}

int main(int argc, char *argv[]){

	runThis();
	return 0;
}
