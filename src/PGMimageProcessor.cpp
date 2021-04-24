#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include "frameSequence.h"

namespace MQTZON001 {

		int length;
                int width;
                int height;
		frameSequence::frameSequence(int len, int wid,  int hei){				//constructor
			length = len;
			width = wid;
			height = hei;
		}

}
