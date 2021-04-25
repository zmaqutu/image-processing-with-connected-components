#include <string>
#ifndef ConnectedComponent_H
#define ConnectedComponent_H

namespace MQTZON001{
	class ConnectedComponent {
		private:
                        int pixelCount;
                        int componentId;
			//a way to store pixels in this component
                public:
			ConnectedComponent(int id);
			~ConnectedComponent();
			int getComponentId();
			int getPixelCount(void) const;
			void setComponentId(int no);
	};
}
#endif
