#include <string>
#include <queue>
#include <memory>
#include "ConnectedComponent.h"
#ifndef PGMimageProcessor_H
#define PGMimageProcessor_H

namespace MQTZON001{
	class PGMimageProcessor{
		private:
			std::string fileName;
			unsigned char ** imageArray;
			int rows, cols;
			int componentCount;
			std::unordered_set<std::pair<int,int>,boost::hash<std::pair<int, int>>> allForegroundPixels;
			//std::unique_ptr<std::unique_ptr<int[]>[]> distance;
			//std::unique_ptr<std::unique_ptr<int[]>[]> visited;
			int ** distance;
			int ** visited;
			std::vector<ConnectedComponent> components;

			std::unique_ptr<int[]> dx;
			std::unique_ptr<int[]> dy;
			//std::unique_ptr<std::unique_ptr<int>[]> distance(new std::unique_ptr<int>[rows])
                public:
			PGMimageProcessor(void);
			PGMimageProcessor(std::string imageFileName);
			~PGMimageProcessor();
			int getRows();
			int getCols();
			int getComponentCount(void) const;
			//void setId(int no);
			void read_from_file();
			int extractComponents(unsigned char threshold, int minValidSize);
			void bfsAdd(int xPosition, int yPosition, unsigned char threshold);
			bool isValidPixel(int xPosition, int yPosition, unsigned char theshold);
			int filterComponentsBySize(int minSize, int maxSize);
			bool writeComponents(const std::string outFileName);
			int getLargestSize(void) const;
			int getSmallestSize(void) const;
			void printComponentData(const ConnectedComponent & theComponent) const;
	};
}
#endif
