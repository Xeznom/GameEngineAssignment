#include "HelloWorldScene.h"

USING_NS_CC;

void HelloWorld::update (float dt)
{
	player->update(dt);
	//tempDMGTimer++;
	//Point temp2 = player->m_Sprite->getPosition();
	//this->Traps->m_Sprite->getPosition();
	//Point temp3 = Traps->m_Sprite->getPosition();
	
	for (int i = 0; i < 2; i++)
	{
		if (portals[i] != NULL)
			portals[i]->update(dt);
	}


	//if(player->getHp() == 0)
	//{
	//	Director::getInstance()->end();
	//}

	if (enemies != NULL)
		enemies->update(dt);
	setViewPoint(player->m_Sprite->getPosition());
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

void HelloWorld::teleportaling(int exit)
{
	if (portals[0]->getConnection() && portals[1]->getConnection())
	{
		player->setPos(portals[exit]->getLoc());
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
    Scene* scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    // 'layer' is an autorelease object
    HelloWorld* layer = HelloWorld::create();
	layer->setPhyWorld(scene->getPhysicsWorld());

	layer->scheduleUpdate();

    // add layer as a child to scene
    scene->addChild(layer);
	
	Size visibleSize = Director::getInstance()->getVisibleSize();

	Node* edgeNode = Node::create();
	Point center = Point(visibleSize.width*0.5f, visibleSize.height*0.5f);
	edgeNode->setPosition(center);
	
	/*
	float RoomWidth = GETVALUE("RoomWidth");
	float RoomHeight = GETVALUE("RoomHeight");
	Size RoomSize = Size(RoomWidth,RoomHeight);
	PhysicsBody* body = PhysicsBody::createEdgeBox(RoomSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	edgeNode->setPhysicsBody(body);
	*/

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
    this->addChild(menu, G_LAYERING_TYPES::G_HUD);

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

	int levelCounter = 0;

	tempDMGTimer = 0;

	loadLevel();

	Point location = Point(visibleSize.width*0.5f, visibleSize.height*0.5f);

	player = new CPlayer(this,location);

	//Traps = new CTraps(this,100,100);
	//CResourceTable::getInstance()->label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    CResourceTable::getInstance()->label->setPosition(Vec2(origin.x + visibleSize.width*0.5f,
                    origin.y + visibleSize.height - 50 - CResourceTable::getInstance()->label->getContentSize().height));

    this->addChild(CResourceTable::getInstance()->label, G_LAYERING_TYPES::G_GAME);

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

	//MapLoad.join();

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
					//CField* m_arrayMap;
					istringstream iss(aLineOfText);

					while (getline(iss, token, ','))
					{
						if (atoi(token.c_str()) == 4)
						{
							m_arrayMap[theLineCounter - 1][theColumnCounter] = new CField(0, theColumnCounter, theLineCounter);
							enemies = new CEnemy(this, Point(theColumnCounter, theLineCounter));
						}
						if (atoi(token.c_str()) == 2)
						{
							m_arrayMap[theLineCounter - 1][theColumnCounter] = new CField(0, theColumnCounter, theLineCounter);
							theDoors[0] = new Door(this, theColumnCounter, theLineCounter );
						}
						if (atoi(token.c_str()) == 5)
						{
							m_arrayMap[theLineCounter - 1][theColumnCounter] = new CField(0, theColumnCounter, theLineCounter);
							theButtons[0] = new Button(this, theColumnCounter, theLineCounter );
						}
						else
							m_arrayMap[theLineCounter - 1][theColumnCounter] = new CField(atoi(token.c_str()), theColumnCounter, theLineCounter);

						addChild(m_arrayMap[theLineCounter - 1][theColumnCounter]->m_Sprite, G_LAYERING_TYPES::G_GAME);
						theColumnCounter++;
					}
				}
			}

			theLineCounter++;
		}
	}
}

void HelloWorld::HUD()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	CHUD* _hud;
		
	_hud = _hud->createHUD("Lives: " + 6,
							Point ( origin.x,
									origin.y + visibleSize.height - _hud->getContentSize().height) );
	this->addChild(_hud, G_LAYERING_TYPES::G_HUD);
	
	_hud = _hud->createHUD("Timer: 00:00 ",
							Point ( origin.x + visibleSize.width - _hud->getContentSize().width,
									origin.y + visibleSize.height - _hud->getContentSize().height) );
	this->addChild(_hud, G_LAYERING_TYPES::G_HUD);
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
	//bitmask 3 = tiles with portal/pressed button/enemyspawner - cannot be collided with
	//bitmask 4 = portal projectile
	//bitmask 5 = tiles/closedoor
	//bitmask 6 = button
	//bitmask 7 = portal
	//bitmask 8 = enemy
	//bitmask 9 = opendoor

	//player with opendoor
	if((First->getCollisionBitmask() == 1 && Second->getCollisionBitmask() == 3) || (First->getCollisionBitmask() == 3 && Second->getCollisionBitmask() == 1))
	{
		return false;
	}
	//portal projectile with tiles
	if((First->getCollisionBitmask() == 4 && Second->getCollisionBitmask() == 5) || (First->getCollisionBitmask() == 5 && Second->getCollisionBitmask() == 4))
	{
		if(First->getCollisionBitmask() == 4)//if portal projectile is First
		{
			//remove projectile
			//spawn portal sprite
		}
		else if (Second->getCollisionBitmask() == 4)//if portal projectile is Second instead
		{
			//remove projectile
			//spawn portal sprite
		}
		if(First->getCollisionBitmask() == 5)//if tile is First
		{
			First->setCollisionBitmask(3);//tile is now a "tile with portal"
		}
		else if(Second->getCollisionBitmask() == 5)//if tile is Second instead
		{
			First->setContactTestBitmask(3);//tile is now a "tile with portal"
		}
	}
	//player with traps
	if((First->getCollisionBitmask() == 1 && Second->getCollisionBitmask() == 2) || (First->getCollisionBitmask() == 2 && Second->getCollisionBitmask() == 1))
	{
		//player->setHP(player->getHp() - 1);
		Director::getInstance()->end();
	}
	//player with button
	if((First->getCollisionBitmask() == 1 && Second->getCollisionBitmask() == 6) || (First->getCollisionBitmask() == 6 && Second->getCollisionBitmask() == 1))
	{
		if(First->getCollisionBitmask() == 6)//if first is button
		{
			First->setCollisionBitmask(3);//button is now a "pressed button"
			for(int i = 0;i<buttonDoorTotal;i++)
			{
				theButtons[0]->pressed();
			}
			for(int i = 0;i<buttonDoorTotal;i++)
			{
				theDoors[0]->openDoor();
			}
			//corressponding door opens code
		}
		else if(Second->getCollisionBitmask() == 6)//if second is button instead
		{
			Second->setCollisionBitmask(3);//button is now a "pressed button"
			for(int i = 0;i<buttonDoorTotal;i++)
			{
				theButtons[0]->pressed();
			}
			for(int i = 0;i<buttonDoorTotal;i++)
			{
				theDoors[0]->openDoor();
			}
			//corressponding door opens code
		}
		return false;
	}
	//player with portal
	if((First->getCollisionBitmask() == 1 && Second->getCollisionBitmask() == 7) || (First->getCollisionBitmask() == 7 && Second->getCollisionBitmask() == 1))
	{
		//portal teleport code
	}
	//enemy with everything
	if((First->getCollisionBitmask() == 8 && Second->getCollisionBitmask() != 5) || (First->getCollisionBitmask() != 5 && Second->getCollisionBitmask() == 8))
	{
		return false;
	}
	//player with opendoor
	if((First->getCollisionBitmask() == 1 && Second->getCollisionBitmask() != 9) || (First->getCollisionBitmask() != 9 && Second->getCollisionBitmask() == 1))
	{
		levelCounter++;
		loadLevel();
		return false;
	}

	return true;
}

void HelloWorld::setViewPoint(CCPoint position)
{
	 CCSize winSize = CCDirector::sharedDirector()->getWinSize();
 
    int x = MAX(position.x, winSize.width/2);
    int y = MAX(position.y, winSize.height/2);
	x = MIN(x, ((MAX_HORIZONTAL * m_arrayMap[0][0]->m_Sprite->getContentSize().width) * m_arrayMap[0][0]->m_Sprite->getContentSize().width) - winSize.width / 2);
	y = MIN(y, ((MAX_VERTICAL * m_arrayMap[0][0]->m_Sprite->getContentSize().height) * m_arrayMap[0][0]->m_Sprite->getContentSize().height) - winSize.height/2);
    CCPoint actualPosition = ccp(x, y);
 
    CCPoint centerOfView = ccp(winSize.width/2, winSize.height/2);
    CCPoint viewPoint = ccpSub(centerOfView, actualPosition);
    this->setPosition(viewPoint);
}

void HelloWorld::loadLevel(void)
{
	if(levelCounter == 0)
	{
		LoadFile("Map.csv");
	}
	else if(levelCounter == 1)
	{
		LoadFile("Level1.csv");
	}
	else if(levelCounter == 2)
	{
		LoadFile("Level2.csv");
	}
	else if(levelCounter == 3)
	{
		LoadFile("Level3.csv");
	}
	else
	{
		Director::getInstance()->end();
	}
}