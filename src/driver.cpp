#include <iostream>
#include <string>

#include "frameSequence.h"

int main(int argc, char *argv[]){
	
	int length;
	int width;
	int height;
	
	std::cout << "Please enter the length of the image: " << std::endl;
	std::cin >> length;
	
	std::cout << "Please enter the width of the image: " << std::endl;
	std::cin >> width;
	
	std::cout << "Please enter the height of the image: " << std::endl;
	std::cin >> height;

	MQTZON001::frameSequence image = MQTZON001::frameSequence(length, width, height);

	std::cout << "The image height is: " << image.height << std::endl;
	std::cout << "The image length is: " << image.length << std::endl;
	std::cout << "The image width is: " << image.width << std::endl;




	return 0;
}
