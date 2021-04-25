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
			ConnectedComponent(int id);
			~ConnectedComponent();
			ConnectedComponent(const ConnectedComponent & rhs);
			ConnectedComponent(ConnectedComponent && rhs);
			ConnectedComponent & operator=(const ConnectedComponent & rhs);
			ConnectedComponent & operator=(ConnectedComponent && rhs);
			int getComponentId();
			int getPixelCount(void) const;
			void setPixelCount(void) const;
			void setComponentId(int no);
	};
}
#endif
