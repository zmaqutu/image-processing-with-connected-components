#include <vector>
#ifndef frameSequence_H
#define frameSequence_H

namespace MQTZON001{

	//frameSequence(int l,int h,int w);

	class frameSequence {
		private:
                public:
                        int length;
                        int width;
                        int height;
			frameSequence(int length, int width, int height);
	};
}
#endif
