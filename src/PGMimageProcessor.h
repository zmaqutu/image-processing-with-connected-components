#include <vector>
#ifndef PGMimageProcessor_H
#define PGMimageProcessor_H

namespace MQTZON001{
	class PGMimageProcessor {
		private:
                        int pixelCount;
                        int id;
                public:
			PGMimageProcessor(int id);
			~PGMimageProcessor();
			int getId();
			int getPixelCount();
			void setId(int no);
	};
}
#endif
