#include "SelectMap.h"
#define COCOS2D_DEBUG 1
USING_NS_CC;

Vec2 l_vOldPos = Vec2(0.0f, 0.0f);
Vec2 l_vNewPos = Vec2(0.0f, 0.0f);
Vec2 p = Vec2(0.0f,0.0f);

Scene* SelectMap::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SelectMap::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
// on "init" you need to initialize your instance
bool SelectMap::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	

	auto spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile("MainMenu.plist");

	//Main menu
//	auto mainmenu = Sprite::createWithSpriteFrameName("mainmenu.png");
//	mainmenu->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//	this->addChild(mainmenu,0);
	

	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_1(SelectMap::Began, this);
	listener->onTouchMoved = CC_CALLBACK_1(SelectMap::Moved, this);
	listener->onTouchEnded = CC_CALLBACK_1(SelectMap::Ended, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);

	p = visibleSize;

	map = Sprite::create("pic/World map-not have flag.png");
	//map->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*3/4 + origin.y -40));
	map->setAnchorPoint(Vec2(0.5,0.5));
	//map->setScale(0.8);
	
	map->setPosition(Vec2(origin.x, visibleSize.height/2 + origin.y));
	
	auto flag1 = Sprite::create("pic/flag.png");
	auto flag_active1 = Sprite::create("pic/flag-active.png");
	auto flag2 = Sprite::create("pic/flag.png");
	auto flag_active2 = Sprite::create("pic/flag-active.png");
	auto flag3 = Sprite::create("pic/flag.png");
	auto flag_active3 = Sprite::create("pic/flag-active.png");
	auto flag4 = Sprite::create("pic/flag.png");
	auto flag_active4 = Sprite::create("pic/flag-active.png");
	auto flag5 = Sprite::create("pic/flag.png");
	auto flag_active5 = Sprite::create("pic/flag-active.png");
	auto flag6 = Sprite::create("pic/flag.png");
	auto flag_active6 = Sprite::create("pic/flag-active.png");
	auto flag7 = Sprite::create("pic/flag.png");
	auto flag_active7 = Sprite::create("pic/flag-active.png");
	
	//auto flag_lock = Sprite::create("pic/flag-lock.png");
	
	

	auto flag_item1 = MenuItemSprite::create(flag1,flag_active1,NULL);
	auto flag_item2 = MenuItemSprite::create(flag2,flag_active2,NULL);
	auto flag_item3 = MenuItemSprite::create(flag3,flag_active3,NULL);
	auto flag_item4 = MenuItemSprite::create(flag4,flag_active4,NULL);
	auto flag_item5 = MenuItemSprite::create(flag5,flag_active5,NULL);
	auto flag_item6 = MenuItemSprite::create(flag6,flag_active6,NULL);
	auto flag_item7 = MenuItemSprite::create(flag7,flag_active7,NULL);

	flag_item1->setPosition(Vec2(map->getContentSize().width/4 -60 , map->getContentSize().height*2/3 +50));
	auto menu_flag_item1 = Menu::create(flag_item1,NULL);
	menu_flag_item1->setPosition(Vec2::ZERO);
	map->addChild(menu_flag_item1,0);

	flag_item2->setPosition(Vec2(map->getContentSize().width/3 -50 , map->getContentSize().height/2 -50));
	auto menu_flag_item2 = Menu::create(flag_item2,NULL);
	menu_flag_item2->setPosition(Vec2::ZERO);
	map->addChild(menu_flag_item2,0);

	flag_item3->setPosition(Vec2(map->getContentSize().width/2  , map->getContentSize().height/2 +20 ));
	auto menu_flag_item3 = Menu::create(flag_item3,NULL);
	menu_flag_item3->setPosition(Vec2::ZERO);
	map->addChild(menu_flag_item3,0);

	flag_item4->setPosition(Vec2(map->getContentSize().width/2 -20 , map->getContentSize().height*2/3 +50 ));
	auto menu_flag_item4 = Menu::create(flag_item4,NULL);
	menu_flag_item4->setPosition(Vec2::ZERO);
	map->addChild(menu_flag_item4,0);

	flag_item5->setPosition(Vec2(map->getContentSize().width*2/3 -30 , map->getContentSize().height*3/4 +20));
	auto menu_flag_item5 = Menu::create(flag_item5,NULL);
	menu_flag_item5->setPosition(Vec2::ZERO);
	map->addChild(menu_flag_item5,0);

	flag_item6->setPosition(Vec2(map->getContentSize().width*2/3 -20, map->getContentSize().height*2/3-20));
	auto menu_flag_item6 = Menu::create(flag_item6,NULL);
	menu_flag_item6->setPosition(Vec2::ZERO);
	map->addChild(menu_flag_item6,0);

	flag_item7->setPosition(Vec2(map->getContentSize().width*3/4 +50 , map->getContentSize().height/3 +50));
	auto menu_flag_item7 = Menu::create(flag_item7,NULL);
	menu_flag_item7->setPosition(Vec2::ZERO);
	map->addChild(menu_flag_item7,0);

	this->addChild(map,1);

	label1 = LabelTTF::create("App", "Helvetica", 15, Size(545, 32), TextHAlignment::CENTER);

	this->addChild(label1,2);
	auto m_emitter = CCParticleFire::create();
//	auto    m_emitter = CCParticleSystemQuad::create("particle_texture.plist");
	this->addChild(m_emitter,3);

    return true;
}

bool SelectMap::Began(Touch* touch){
	l_vOldPos = touch->getLocation();

	if(map->getPosition().x >= map->getContentSize().width/2 )
		map->setPosition(map->getPosition().x - 50,map->getPosition().y);
	else if( map->getPosition().x + map->getContentSize().width/2 <= p.x )
			map->setPosition(map->getPosition().x + 50 , map->getPosition().y );
		else if( map->getPosition().y >= map->getContentSize().height/2 )
				map->setPosition(map->getPosition().x,map->getPosition().y - 50);
			else if((map->getPosition().y +map->getContentSize().height/2) <=p.y )
					map->setPosition(map->getPosition().x,map->getPosition().y + 50);
//
	
	
	return true;
}

void SelectMap::Moved(Touch* touch){

	l_vNewPos = touch->getLocation();
	Vec2 vDeltaPos = l_vNewPos - l_vOldPos;
	CCLOG("%f",(l_vNewPos.getDistance(l_vOldPos)));

	if(l_vNewPos.getDistance(l_vOldPos)>40)
	{


		CCLOG("x = %f, y = %f",l_vNewPos.x,l_vNewPos.y);
		auto move = MoveBy::create(1, Vec2(50,0));

			// create a BounceIn Ease Action
			auto move_ease_in = EaseOut::create(move->clone(),3.0);

			// create a delay that is run in between sequence events
			auto delay = DelayTime::create(0.5f);
			auto back = move->reverse();

			// create the sequence of actions, in the order we want to run them
			auto seq1 = Sequence::create(move_ease_in, nullptr);

			// run the sequence and repeat forever.
			map->runAction(seq1);
	}


	l_vOldPos = l_vNewPos;



	//map->setPosition(Vec2(x ,y)+Vec2(touch->getLocation().x - x1,0));
	
	if(map->getPosition().x <= map->getContentSize().width/2 && map->getPosition().x + map->getContentSize().width/2 >= p.x && map->getPosition().y <= map->getContentSize().height/2 && (map->getPosition().y +map->getContentSize().height/2) >=p.y )
		map->setPosition(map->getPosition() + vDeltaPos);
	
}
	

void SelectMap::Ended(Touch* touch){
	
}

void SelectMap::menuCloseCallback(Ref* pSender)
{

}
