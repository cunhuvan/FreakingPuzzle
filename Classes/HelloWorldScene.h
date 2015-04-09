//#ifndef __HELLOWORLD_SCENE_H__
//#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
	int homeScreenBack = 0;
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    Layer *layer_dim = Layer::create();
    Layer *layer_bg = Layer::create();
    Layer *layer_dialog = Layer::create();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void Cancel_event(cocos2d::Ref* pSender);
	void Ok_event(cocos2d::Ref* pSender);

	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void CreateCanclePopup();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

//#endif // __HELLOWORLD_SCENE_H__
