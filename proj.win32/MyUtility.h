#ifndef MYUTILITY_H
#define MYUTILITY_H

#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class MyUtility {
public:
	static string getCurrentTime();
	static string gbk_2_utf8(const string text);
	static string getUTF8Char(const string key);
};

#endif
