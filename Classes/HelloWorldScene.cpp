#include "HelloWorldScene.h"

USING_NS_CC;

void HelloWorld::update (float dt)
{
	player->update(dt);
	//Point temp2 = player->m_Sprite->getPosition();
	//this->Traps->m_Sprite->getPosition();
	//Point temp3 = Traps->m_Sprite->getPosition();
	//if (portals[0]->getExist())
	//{

	//}
}

void HelloWorld::onMouseDown(cocos2d::Event* eevent)
{
}

void HelloWorld::onMouseMove(cocos2d::Event* eevent)
{
}

void HelloWorld::onMouseUp(cocos2d::Event* eevent)
{
}

void HelloWorld::onMouseScroll(cocos2d::Event* eevent)
{
}

void HelloWorld::teleportaling(int por, int enter)
{
	if (portals[0]->getConnection() && portals[1]->getConnection())
	{
		//player pos = portals[por]->getLoc();
		
		//  U D L R
		//U R X < >
		//D X R < >
		//L ^ v R X
		//R ^ v X R
		
		switch (portals[por]->getDirection()) {
		case 1: //up
			//if (portals[enter]->getDirection() == portals[por]->getDirection())
			//	dir.y = -dir.y;
			//if (portals[enter]->getDirection() == 3)
			//	dir.x = dir.y;
			//if (portals[enter]->getDirection() == 4)
			//	dir.x = -dir.y;
			break;
		case 2: //down
			//if (portals[enter]->getDirection() == portals[por]->getDirection())
			//	dir.y = -dir.y;
			//if (portals[enter]->getDirection() == 3)
			//	dir.x = -dir.y;
			//if (portals[enter]->getDirection() == 4)
			//	dir.x = dir.y;
			break;
		case 3: //left
			//if (portals[enter]->getDirection() == portals[por]->getDirection())
			//	dir.x = -dir.x;
			//if (portals[enter]->getDirection() == 1)
			//	dir.y = dir.x;
			//if (portals[enter]->getDirection() == 2)
			//	dir.y = -dir.x;
			break;
		case 4: // right
			//if (portals[enter]->getDirection() == portals[por]->getDirection())
			//	dir.x = -dir.x;
			//if (portals[enter]->getDirection() == 1)
			//	dir.y = -dir.x;
			//if (portals[enter]->getDirection() == 2)
			//	dir.y = dir.x;
			break;
		}
	
	}
}

void HelloWorld::cleanup()
{
	delete player;
	player = nullptr;

	for (int i = 0; i < 2; i++)
	{
		delete portals[i];
		portals[i] = nullptr;
	}

	for (int i = 0; i < MAX_HORIZONTAL; ++i)
	{
		for (int j = 0; j < MAX_VERTICAL; ++j)
		{
			delete m_arrayMap[i][j];
			m_arrayMap[i][j] = nullptr;
		}
	}
}

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
	layer->setPhyWorld(scene->getPhysicsWorld());

	layer->scheduleUpdate();

    // add layer as a child to scene
    scene->addChild(layer);
	
	Size visibleSize = Director::getInstance()->getVisibleSize();

	Node* edgeNode = Node::create();
	Point center = Point(visibleSize.width*0.5f, visibleSize.height*0.5f);
	edgeNode->setPosition(center);
	
	Size RoomSize = Size(600,600);
	PhysicsBody* body = PhysicsBody::createEdgeBox(RoomSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	edgeNode->setPhysicsBody(body);

	scene->addChild(edgeNode);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init()) return false;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
					CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width -
						closeItem->getContentSize().width*0.5f,
						origin.y + closeItem->getContentSize().height*0.5f));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...
	/*
    Label* label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width*0.5f,
                    origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width*0.5f + origin.x, visibleSize.height*0.5f + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    */

	LoadFile("MapDesign.csv");

	Point location = Point(visibleSize.width*0.5f, visibleSize.height*0.5f);

	player = new CPlayer(this,location);

	Traps = new CTraps(this,100,100);
	//CResouceTable::getInstance()->label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    CResouceTable::getInstance()->label->setPosition(Vec2(origin.x + visibleSize.width*0.5f,
                    origin.y + visibleSize.height - 50 - CResouceTable::getInstance()->label->getContentSize().height));

    this->addChild(CResouceTable::getInstance()->label, 1);

	std::string Data = CResouceTable::getInstance()->GetFileName("PortalGun");
	CResouceTable::getInstance()->label->setString(Data);

	for (int i = 0; i < 2; i++)
		portals[i] = new CPortals(i, location);

	for (int i = 0; i < MAX_HORIZONTAL; ++i)
	{
		for (int j = 0; j < MAX_VERTICAL; ++j)
			m_arrayMap[i][j] = nullptr;
	}

	auto KeyboardListener = EventListenerKeyboard::create();
	KeyboardListener->onKeyPressed = CC_CALLBACK_2(CPlayer::KeyPress,player);
	KeyboardListener->onKeyReleased = CC_CALLBACK_2(CPlayer::KeyRelease,player);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(KeyboardListener,player->m_Sprite);

	auto MouseListener = EventListenerMouse::create();
	MouseListener->onMouseMove = CC_CALLBACK_1(CPlayer::MouseMove,player);
	MouseListener->onMouseDown = CC_CALLBACK_1(CGun::MouseDown, player->PortalGun);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(MouseListener,player->m_Sprite);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener,this);

	return true;
}

void HelloWorld::LoadFile(const string mapName)
{
	int theLineCounter = 0;
	int theMaxNumOfColumns = 0;

	ifstream file(mapName.c_str());
	if (file.is_open())
	{
		int i = 0, k = 0;
		while (file.good())
		{
			string aLineOfText = "";
			getline(file, aLineOfText);

			// If this line is not a comment line, then process it
			if (!(aLineOfText.find("//") == NULL) && aLineOfText != "")
			{
				string token;
				if (theLineCounter == 0)
				{
					// This is the first line of the map data file
					istringstream iss(aLineOfText);
					while (getline(iss, token, ','))
					{
						// Count the number of columns
						theMaxNumOfColumns = atoi(token.c_str());
					}
				}
				else
				{
					int theColumnCounter = 0;

					istringstream iss(aLineOfText);
					while (getline(iss, token, ','))
					{
						if (atoi(token.c_str()) == 4)
						{
							m_arrayMap[theLineCounter - 1][theColumnCounter] = new CField(0, theColumnCounter, theLineCounter);
							CEnemy *spawn = new CEnemy(this, Point(theColumnCounter * 30, theLineCounter * 30) );
						}
						else
							m_arrayMap[theLineCounter - 1][theColumnCounter] = new CField(atoi(token.c_str()), theColumnCounter, theLineCounter );

						addChild(m_arrayMap[theLineCounter-1][theColumnCounter]->m_Sprite, 0);
						theColumnCounter++;
					}
				}
			}

			theLineCounter++;
		}
	}
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


bool HelloWorld :: onContactBegin(cocos2d::PhysicsContact &contact)
{
	//code reminders for setting the object catergories for collision
	//sprite->setCollisionBitMask(1);
	//sprite->setContactTestBitMask(true);

	PhysicsBody * First = contact.getShapeA()->getBody(); 
	PhysicsBody * Second = contact.getShapeB()->getBody(); 

	//for possible future use
	//check if collided is different
	//if( ( First->getCollisionBitmask() == 1  && Second->getCollisionBitmask() == 2 ) || ( First->getCollisionBitmask() == 2 && Second->getCollisionBitmask() == 1 ) )
	//{
		//if collided

	//}

	//bitmask 1 = player
	//bitmask 2 = traps
	//bitmaks 3 = portal

	if((First->getCollisionBitmask() == 1 && Second->getCollisionBitmask() == 3) || (First->getCollisionBitmask() == 3 && Second->getCollisionBitmask() == 1))
	{
		return false;
	}

	if((First->getCollisionBitmask() == 1 && Second->getCollisionBitmask() == 2) || (First->getCollisionBitmask() == 2 && Second->getCollisionBitmask() == 1))
	{
		player->setHP(player->getHp() - 1);
	}

	return true;
}