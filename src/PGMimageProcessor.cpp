#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include "PGMimageProcessor.h"

namespace MQTZON001 {
	//default constructor
	PGMimageProcessor::PGMimageProcessor(void)
		:fileName(""),imageArray(nullptr),rows(0),cols(0),componentCount(0),distance(nullptr),visited(nullptr)
		 ,dx(new int[4]),dy(new int[4])
	{
		//dx = {-1,0,1,0};
		dx[0] = -1;
		dx[1] = 0;
		dx[2] = 1;
		dx[3] = 0;

		//dy = {0,1,0,-1};
		dx[0] = 0;
		dx[1] = 1;
		dx[2] = 0;
                dx[3] = -1;
	}
	//other constructor
	PGMimageProcessor::PGMimageProcessor(std::string imageFileName) 
		: fileName(imageFileName),imageArray(nullptr),rows(0),cols(0),componentCount(0),distance(nullptr),visited(nullptr)
		  ,dx(new int[4]),dy(new int[4])
	{
		//dx = {-1,0,1,0};
                //dy = {0,1,0,-1};
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

		//std::unique_ptr<std::unique_ptr<int[]> d(new std::unique_ptr<int[]>[rows]);
		//visited(new std::unique_ptr<int[]>[rows]);

		std::cout << rows << "," << cols << std::endl;

		std::getline(file,line);					//read 255
		//TODO change these 2D arrays to use smart pointers
		imageArray = new unsigned char*[rows];				
		distance = new  int*[rows];
		visited = new int*[rows];
		for(int i = 0; i < rows;i++){
			imageArray[i] = new unsigned char[cols];
			distance[i] = new int[cols];
			visited[i] = new int[cols];
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
		for(int y = 0; y < rows; y++){
			for(int x = 0; x < cols; x++){
				std::pair<int,int> position(y,x);
				if(imageArray[x][y] >= threshold && visited[x][y] == 0){
					//bfsAdd(x,y);		//this applies bfs starting from location y,x 
				}
			}
			//TODO free the space the image is occupying
		}
		return -1;
	}
	//this method applies bfs and adds each foreground pixel found to a set
	void PGMimageProcessor::bfsAdd(int xPosition, int yPosition){
		std::queue<std::pair<int,int>> pixelQueue;
		pixelQueue.push({xPosition,yPosition});

		visited[xPosition][yPosition] = 1;
		distance[xPosition][yPosition] = 0;
		//TODO create a connectedComponent
		componentCount++;
		ConnectedComponent component(componentCount,xPosition,yPosition);

		while(!pixelQueue.empty()){
			int currentX = pixelQueue.front().first;		//returns the x value in the pair at the front of queue
			int currentY = pixelQueue.front().second;		//returns the y value in the pair at the front of queue

			pixelQueue.pop();
			for(int i = 0; i < 4;i++){
				if(isValidPixel(currentX + dx[i],currentY + dy[i])){
					int nextX = currentX + dx[i];
					int nextY = currentY + dy[i];

					pixelQueue.push({nextX,nextY});
					visited[nextX][nextY] = 1;
					//TODO add x and y to set then add set will be moved to connectedComponent after loop terminates
					distance[nextX][nextY] = distance[currentX][currentY] + 1;
				}
			}
		}
		//TODO add connectedComponent to container of connectedComponents
		return;
	}
	bool PGMimageProcessor::isValidPixel(int xPosition,int yPosition){
		return true;
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
