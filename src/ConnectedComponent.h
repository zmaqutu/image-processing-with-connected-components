#include <string>
#include <unordered_set>
#include <boost/functional/hash.hpp>
#ifndef ConnectedComponent_H
#define ConnectedComponent_H

namespace MQTZON001{
	class ConnectedComponent {
		private: 
                        int componentId;
			int pixelCount;
			//a way to store pixels in this component an unordered set or pairs
			std::unordered_set<std::pair<int,int>,boost::hash<std::pair<int, int>>> pixelIndexes;
                public:
			ConnectedComponent(int id, int startRow, int startCol);
			~ConnectedComponent();
			ConnectedComponent(const ConnectedComponent & rhs);
			ConnectedComponent(ConnectedComponent && rhs);
			ConnectedComponent & operator=(const ConnectedComponent & rhs);
			ConnectedComponent & operator=(ConnectedComponent && rhs);
			void addPixel(int x,int y);
			int getComponentId();
			int getPixelCount(void);
			void setPixelCount(int);
			void incrementPixelCount(void);
			void setComponentId(int no);
	};
}
#endif
