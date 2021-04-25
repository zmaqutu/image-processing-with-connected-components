#include <string>
#include "ConnectedComponent.h"
#ifndef PGMimageProcessor_H
#define PGMimageProcessor_H

namespace MQTZON001{
	class PGMimageProcessor {
		private:
			std::string fileName;
			unsigned char ** imageArray;
			int rows, cols;
			int componentCount;
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
			int filterComponentsBySize(int minSize, int maxSize);
			bool writeComponents(const std::string & outFileName);
			int getLargestSize(void) const;
			int getSmallestSize(void) const;
			void printComponentData(const ConnectedComponent & theComponent) const;
	};
}
#endif
