#define COCOS2D_DEBUG 1
#include "Setting.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
CCMenuItemSprite *soundItem;
int check, uncheck;
Scene* Setting::createScene()
{
	auto spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile("MainMenu.plist");
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Setting::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Setting::init()
{
	//////////////////////////////
	// 1. super init first
	Vector<MenuItem*> MenuItem;
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// load the Sprite Sheet
	auto spritecache = SpriteFrameCache::getInstance();

	// the .plist file can be generated with any of the tools mentioned below
	spritecache->addSpriteFramesWithFile("MainMenu.plist");
	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	CCMenuItemSprite *facebook = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("facebook icon.png"),
		CCSprite::createWithSpriteFrameName("facebook icon_press.png"),
		CC_CALLBACK_1(Setting::SoundSetting, this));
	auto myLabel = Label::createWithSystemFont("Sound", "Arial", 35);
	auto myLabel2 = Label::createWithSystemFont("Music", "Arial", 35);

	soundItem = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("check_button_active.png"),
										CCSprite::createWithSpriteFrameName("check_button.png "),
										CC_CALLBACK_1(Setting::SoundSetting, this));
	check = 1;
	uncheck = 0;

	myLabel->setPosition(Vec2(visibleSize.width / 2 + origin.x - 150, visibleSize.height / 2 + origin.y - 200));
	myLabel2->setPosition(Vec2(visibleSize.width / 2 + origin.x - 150, visibleSize.height / 2 + origin.y - 100));
	facebook->setPosition(Vec2(visibleSize.width / 2 + origin.x - 80, visibleSize.height / 2 + origin.y - 300));
	soundItem->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 200));
	MenuItem.pushBack(facebook);
	MenuItem.pushBack(soundItem);
	// create menu, it's an autorelease object
	auto menu = Menu::createWithArray(MenuItem);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	this->addChild(myLabel, 1);
	this->addChild(myLabel2, 1);
	// add "HelloWorld" splash screen"
	return true;
}

void Setting::SoundSetting(cocos2d::Ref* pSender)
{
	//uncheck
	if (check == 0 && uncheck == 1)
	{
		soundItem->setNormalImage(CCSprite::createWithSpriteFrameName("check_button_active.png"));
		soundItem->setSelectedImage(CCSprite::createWithSpriteFrameName("check_button.png"));
		auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
		audio->playBackgroundMusic("GameSound.mp3");
		check = 1;
		uncheck = 0;
	}
	//check
	else if (check == 1 && uncheck == 0)
	{
		soundItem->setNormalImage(CCSprite::createWithSpriteFrameName("check_button.png"));
		soundItem->setSelectedImage(CCSprite::createWithSpriteFrameName("check_button_active.png"));
		CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		check = 0;
		uncheck = 1;
	}
	
}

