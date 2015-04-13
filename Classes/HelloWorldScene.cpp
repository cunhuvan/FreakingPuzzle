#define COCOS2D_DEBUG 1
#include "HelloWorldScene.h"
#include "Setting.h"
#include "SimpleAudioEngine.h"
#include "SelectMap.h"

USING_NS_CC;
	CCMenuItemSprite *newgame,*SelectArea,*continuegame,*rate,*facebook,*setting;

	float VisibleSize_high,VisibleSize_width,origin_x,origin_y;
Scene* HelloWorld::createScene()
{
	auto spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile("MainMenu.plist");
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
	layer_dim->setTag(2);
	layer_dialog->setTag(3);
	Vector<MenuItem*> MenuItem;
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    VisibleSize_high = visibleSize.height;
    VisibleSize_width = visibleSize.width;
    origin_x = origin.x;
    origin_y = origin.y;

    // add a "close" icon to exit the progress. it's an autorelease object
	newgame = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("new game.png"),
										CCSprite::createWithSpriteFrameName("new game_press.png"),
										CC_CALLBACK_1(HelloWorld::NewGame, this));
	SelectArea = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("select area icon.png"),
										CCSprite::createWithSpriteFrameName("select area icon_press.png"),
										CC_CALLBACK_1(HelloWorld::Setting, this));
    
	continuegame = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("continue.png"),
										CCSprite::createWithSpriteFrameName("continue_press.png"),
										CC_CALLBACK_1(HelloWorld::Setting, this));

	rate = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("rate icon.png"),
									CCSprite::createWithSpriteFrameName("rate icon_press.png"),
									CC_CALLBACK_1(HelloWorld::Setting, this));

	facebook = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("facebook icon.png"),
										CCSprite::createWithSpriteFrameName("facebook icon_press.png"),
										CC_CALLBACK_1(HelloWorld::Setting, this));

	setting = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("setting icon.png"),
										CCSprite::createWithSpriteFrameName("setting icon_press.png"),
										CC_CALLBACK_1(HelloWorld::Setting, this));

	SelectArea->setPosition(Vec2(visibleSize.width / 2 + origin.x + 80, visibleSize.height / 2 + origin.y - 300));
	rate->setPosition(Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y - 300));
	facebook->setPosition(Vec2(visibleSize.width / 2 + origin.x - 80, visibleSize.height / 2 + origin.y - 300));
	setting->setPosition(Vec2(visibleSize.width / 2 + origin.x - 160, visibleSize.height / 2 + origin.y - 300));
	newgame->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	continuegame->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 150));

	MenuItem.pushBack(facebook);
	MenuItem.pushBack(newgame);
	MenuItem.pushBack(setting);
	MenuItem.pushBack(continuegame);
	MenuItem.pushBack(rate);
	MenuItem.pushBack(SelectArea);
    // create menu, it's an autorelease object
	auto menu = Menu::createWithArray(MenuItem);
    menu->setPosition(Vec2::ZERO);
    HelloWorld::layer_bg->addChild(menu, 1);


    // add "main_menu" splash screen"
	auto mysprite = Sprite::createWithSpriteFrameName("mainmenu.png");

    // position the sprite on the center of the screen
	mysprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	mysprite->setScaleY(visibleSize.height / mysprite->getContentSize().height);

    // add the sprite as a child to this layer
	HelloWorld::layer_bg->addChild(mysprite, 0);
	this->addChild(HelloWorld::layer_bg);
	this->setKeypadEnabled(true);

	//set background music
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("GameSound.mp3");

    return true;
}

void HelloWorld::onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{


	if (keyCode == EventKeyboard::KeyCode::KEY_BACK /*KeyboardEvent::KeyCode::Menu(KEY_BACKSPACE)*/)
	{

			layer_dim = LayerColor::create(Color4B(0, 0, 0, 160));
			layer_dim->setContentSize(Size(100, 100));
			layer_dim->setAnchorPoint(Vec2(0,0));
			layer_dim->setPosition(Vec2(0,0));
			layer_dim->setScaleY(VisibleSize_high / 100);
			layer_dim->setScaleX(VisibleSize_width / 100);

			this->addChild(layer_dim,3);
			newgame->setEnabled(false);
			continuegame->setEnabled(false);
			facebook->setEnabled(false);
			rate->setEnabled(false);
			SelectArea->setEnabled(false);
			CreateCanclePopup();
	}
}

void HelloWorld::CreateCanclePopup() //?????????
{
	layer_dialog = Layer::create();
	Vector<MenuItem*> menuItem;
	//create a new sprite for dialog exit
	auto dlog = Sprite::createWithSpriteFrameName("ExitPopup.png");
	dlog->setPosition(Vec2(VisibleSize_width / 2 + origin_x, VisibleSize_high / 2 + origin_y));
	MenuItemSprite *Cancle = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("cancel.png"),
													CCSprite::createWithSpriteFrameName("cancel_press.png"),
													CC_CALLBACK_1(HelloWorld::Cancel_event, this));

	MenuItemSprite *Ok = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("ok.png"),
										CCSprite::createWithSpriteFrameName("ok_press.png"),
										CC_CALLBACK_1(HelloWorld::Ok_event, this));

	Cancle->setPosition(Vec2(VisibleSize_width / 2 + origin_x - 335, VisibleSize_high / 2 + origin_y - 445));
	Cancle->setEnabled(true);
	Ok->setPosition(Vec2(VisibleSize_width / 2 + origin_x - 143, VisibleSize_high / 2 + origin_y - 445));

	menuItem.pushBack(Cancle);
	menuItem.pushBack(Ok);
	auto menu = Menu::createWithArray(menuItem);
	layer_dialog->addChild(dlog);
	layer_dialog->addChild(menu,2);
	this->addChild(layer_dialog,4);
}

//event for cancel button
void HelloWorld::Cancel_event(cocos2d::Ref* pSender)
{
	removeChild(layer_dim);
	removeChild(layer_dialog);
	newgame->setEnabled(true);
	continuegame->setEnabled(true);
	facebook->setEnabled(true);
	rate->setEnabled(true);
	SelectArea->setEnabled(true);
}

//event for ok buttin
void HelloWorld::Ok_event(cocos2d::Ref* pSender)
{
	Director::sharedDirector()->end();
}

void HelloWorld::Setting(cocos2d::Ref* pSender)
{
	Scene *setting = Setting::createScene();
	Director::getInstance()->pushScene(setting);
}

void HelloWorld::NewGame(cocos2d::Ref* pSender){
	Scene *newGameScene = SelectMap::createScene();
	Director::getInstance()->pushScene(newGameScene);
}
