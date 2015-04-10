#ifndef __SelectMap_H__
#define __SelectMap_H__

#include "cocos2d.h"
using namespace cocos2d;

class SelectMap : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	Sprite* map;
	

	
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	bool Began(cocos2d::Touch* touch);
	void Moved(cocos2d::Touch* touch);
	void Ended(cocos2d::Touch* touch);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
CREATE_FUNC(SelectMap);
};

#endif // __HELLOWORLD_SCENE_H__
    