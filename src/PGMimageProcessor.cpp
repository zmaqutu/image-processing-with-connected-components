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
		dy[0] = 0;
		dy[1] = 1;
		dy[2] = 0;
		dy[3] = -1;
	}
	//other constructor
	PGMimageProcessor::PGMimageProcessor(std::string imageFileName) 
		: fileName(imageFileName),imageArray(nullptr),rows(0),cols(0),componentCount(0),distance(nullptr),visited(nullptr)
		,dx(new int[4]),dy(new int[4])
	{
		//dx = {-1,0,1,0};
                //dy = {0,1,0,-1};
		//dx = {-1,0,1,0};
		dx[0] = -1;
		dx[1] = 0;
		dx[2] = 1;
		dx[3] = 0;

		//dy = {0,1,0,-1};
		dy[0] = 0;
		dy[1] = 1;
		dy[2] = 0;
		dy[3] = -1;
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
	/**
	 * this method will return true if lhs is smaller (however we choose to define smaller) than rhs
	 * the method will return false if lhs is not smaller than rhs
	 * in this method lhs is smaller than rhs if it has less pixels than rhs
	 * @param lhs
	 * @param rhs
	 * @return
	 */
	struct compareComponents {
		bool operator()(ConnectedComponent & lhs,ConnectedComponent & rhs) const {
			return lhs.getPixelCount() < rhs.getPixelCount();
		}
	};
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
			imageArray[i] = new unsigned char[cols];		//for each of the rows add cols
			distance[i] = new int[cols];
			visited[i] = new int[cols];
		}
		while(file){
			for(int i = 0; i < rows;i++){				//fils each row with cols read from file
				file.read((char*)imageArray[i],cols);
			}
		}
		/*for(int x = 0; x < 5;x++){
			for(int y = 0; y < 5; y++){
				//std::cout << imageArray[y][x] << std::endl;
				std::cout << distance[x][y] << std::endl;


			}
		}*/
		file.close();

		std::ofstream outputFile("dump_files/bab.pgm", std::ios::binary);

		outputFile << "P5" << std::endl;
		outputFile << rows << " " << cols << std::endl;
		outputFile << "255" << std::endl;

		for(int row = 0; row < rows; row++){
			/*for(int col = 0; col < cols;col++){
				if(imageArray[row][col] >= threshold){
					outputFile << 255;
				}
				else{
					outputFile << 0;
				}
			}*/
			outputFile.write((char*)imageArray[row],cols);
		}
		outputFile.close();

		extractComponents(120,30);
		std::cout << "There are " << components.size() << " components"<< std::endl;


	}
	/**
	 * this method processes the input image to extract all the connected components,
	 * based on the supplied threshold (0...255) and excluding any components
	 * of less than the minValidSize. The final number of components that
	 * you store in your container (after discarding undersized one)
must be returned.
	 * @param threshold - a user supplied value to compare pixels against
	 * @param minValidSize -
	 * @return - the number of components larger than minValidSize pixels
	 */
	int PGMimageProcessor::extractComponents(unsigned char threshold, int minValidSize){
		std::vector<ConnectedComponent> extractedComponents;
		for(int row = 0; row < rows; row++){
			for(int col = 0; col < cols; col++){
				if(isValidPixel(row,col,threshold)){
					bfsAdd(row,col,threshold);		//this applies bfs starting from location y,x
				}
			}
			//TODO free the space the image is occupying
		}
		for (unsigned int i = 0; i < components.size(); ++i) {
			if(components[i].getPixelCount() > minValidSize){
				extractedComponents.push_back(components[i]);
			}
		}
		std::ofstream outputFile("dump_files/output.pgm", std::ios::binary);

		outputFile << "P5" << std::endl;
		outputFile << rows << " " << cols << std::endl;
		outputFile << "255" << std::endl;
		for(int row = 0; row < rows; row++){
			for(int col = 0; col < cols;col++){
				if(imageArray[row][col] >= threshold){
					outputFile << (unsigned char)255;
				}
				else{
					outputFile << (unsigned char)0;
				}
			}
			//outputFile.write((char*)imageArray[row],cols);
		}
		outputFile.close();
		std::cout << extractedComponents.size() << " components are larger than "  << minValidSize << " pixels"<< std::endl;
		writeComponents("RandomText");
		return extractedComponents.size();
	}
	//this method applies bfs and adds each foreground pixel found to a set
	void PGMimageProcessor::bfsAdd(int row, int col, unsigned char threshold){
		std::queue<std::pair<int,int>> pixelQueue;
		pixelQueue.push({row,col});					//points are row,col not x,y

		visited[row][col] = 1;
		distance[row][col] = 0;
		//TODO create a connectedComponent
		componentCount++;
		//ConnectedComponent component(componentCount,row,col);
		ConnectedComponent component = ConnectedComponent(componentCount,row,col);

		while(!pixelQueue.empty()){
			int currentRow = pixelQueue.front().first;		//returns the x value in the pair at the front of queue
			int currentCol = pixelQueue.front().second;		//returns the y value in the pair at the front of queue

			pixelQueue.pop();
			for(int i = 0; i < 4;i++){
				//dx = {-1,0,1,0};
				//dy = {0,1,0,-1};
				if(isValidPixel(currentRow + dy[i],currentCol + dx[i],threshold)){
					int nextRow = currentRow + dy[i];
					int nextCol = currentCol + dx[i];

					pixelQueue.push({nextRow,nextCol});
					//visited[currentRow][currentCol] = 1;
					visited[nextRow][nextCol] = 1;
					//TODO add x and y to set then add set will be moved to connectedComponent after loop terminates
					distance[nextRow][nextCol] = distance[currentRow][currentCol] + 1;
					component.addPixel(currentRow,currentCol);
				}
			}
		}
		//add connectedComponent to container of connectedComponents only if pixelCount > minimum valid size
		components.push_back(component);
		std::sort(components.begin(),components.end(), compareComponents());
		return;
	}
	bool PGMimageProcessor::isValidPixel(int row,int col, unsigned char threshold){
		if(row < 0 || row > rows-1 || col < 0 || col > cols-1 || imageArray[row][col] < threshold) return false;
		
		if(visited[row][col] == 1) return false;
		
		return true;
	}
	/**
	 * this method iterates though the container of connected
	 * components and filters out (removes) all the components which do not
	 * obey the size criteria pass as arguments. The number remaining
	 * after this operation is returned.
	 * @param minSize
	 * @param maxSize
	 * @return
	 */
	int PGMimageProcessor::filterComponentsBySize(int minSize, int maxSize){
		int filteredComponentSize = 0;
		for (std::vector<ConnectedComponent>::iterator it = components.begin();
		  it != components.end(); ++it) {
			//int componentSize = components[*it].getPixelCount();
			int componentSize = (*it).getPixelCount();
			if(componentSize > minSize && componentSize < minSize){
				filteredComponentSize++;
			}
		}
		return filteredComponentSize;
	}
	bool PGMimageProcessor::writeComponents(const std::string outFileName){
		std::ofstream outputFile("dump_files/connectedComponents.pgm", std::ios::binary);
		//std::ofstream & outputFile;
		outputFile << "P5" << std::endl;
		outputFile << rows << " " << cols << std::endl;
		outputFile << "255" << std::endl;
		//std::ofstream & outputLocation = &outputFile;
		unsigned char ** componentsArray = new unsigned char*[rows];
		for(int row = 0; row < rows;++row){
			componentsArray[row] = new unsigned char[cols];		//for each of the rows add cols
			for (int col = 0; col < cols; ++col) {
				componentsArray[row][col] = (unsigned char)0;
			}
		}
		for(int  i = 0; i < componentCount; ++i){
			//outputFile.write(char line[cols],cols);
			// outputFile << (unsigned char)0;
			// components[i].writeToFile(outputFile);
			for(std::pair<int,int> currentPair : components[i].getPixelIndexes()){
				componentsArray[currentPair.first][currentPair.second] = (unsigned char)255;
			}
		}
		for (int row = 0; row < rows; ++row) {
			//outputFile.write((char*)componentsArray[row],cols);
			for (int col = 0; col < cols; ++col) {
				outputFile << (unsigned char)componentsArray[row][col];
			}
		}
		//std::cout<< components[0].pixelIndexes.size() << "picacellsz" << std::endl;
		outputFile.close();
		for (int i = 1573; i < 1583; ++i) {
			std::cout << components[i].getPixelCount() << std::endl;
		}
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
