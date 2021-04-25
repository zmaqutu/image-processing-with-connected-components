#include <string>
#include "ConnectedComponent.h"
#ifndef PGMimageProcessor_H
#define PGMimageProcessor_H

namespace MQTZON001{
	class PGMimageProcessor {
		private:
                        int componentCount;
                        int id;
                public:
			PGMimageProcessor(int id);
			~PGMimageProcessor();
			int getId();
			int getComponentCount(void) const;
			void setId(int no);
			void read_from_file(std::string fileName);
			int extractComponents(unsigned char threshold, int minValidSize);
			int filterComponentsBySize(int minSize, int maxSize);
			bool writeComponents(const std::string & outFileName);
			int getLargestSize(void) const;
			int getSmallestSize(void) const;
			void printComponentData(const ConnectedComponent & theComponent) const;
	};
}
#endif
