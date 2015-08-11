#include "HelloWorldScene.h"

USING_NS_CC;

void HelloWorld::update (float dt)
{
	player->update(dt);
	//this->setViewPoint(player->m_Sprite->getPosition());
	for(int i = 0 ; i < mobileSpikeCounter ; i++)
	{
		if(theMobileSpike[i] != NULL)
		theMobileSpike[i]->update(dt);
	}
	//tempDMGTimer++;
	//Point temp2 = player->m_Sprite->getPosition();
	//this->Traps->m_Sprite->getPosition();
	//Point temp3 = Traps->m_Sprite->getPosition();
	for (int i = 0; i < 2; i++)
	{
		if (portals[i] != nullptr) portals[i]->update(dt);
	}

	if (portals[0] != nullptr && portals[1] != nullptr)
	{
		portals[0]->connecting = portals[1]->connecting = true;
	}

	timer += 0.1f;

	_hud[0]->valueupdate(points);
	_hud[1]->valueupdate(timer);

	//if(player->getHp() == 0)
	//{
	//	Director::getInstance()->end();
	//}

	if (enemies != nullptr) enemies->update(dt);

	//Size winSize = CCDirector::getInstance()->getWinSize();
 
	//float centerX,centerY,centerZ;
	//float eyeX,eyeY,eyeZ;

	//centerX = eyeX = (player->m_Sprite->getPosition().x - winSize.width * 0.5f);
	//centerY = eyeY = (player->m_Sprite->getPosition().y - winSize.height * 0.5f);

	//this->getScene()->getDefaultCamera()->createOrthographic(

	//this->getScene()->getDefaultCamera()->lookAt(Vec3(player->m_Sprite->getPosition().x,player->m_Sprite->getPosition().y,0));
	
	//this->getScene()->getDefaultCamera()->setPositionX(player->m_Sprite->getPhysicsBody()->getPosition().x);

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

void HelloWorld::teleportaling(const int exit)
{
	if (portals[0]->connecting && portals[0]->bTimer == false &&
		portals[1]->connecting && portals[1]->bTimer == false)
	{
		audioPortal->playEffect("teleport.mp3");
		player->setPos(portals[exit]->getLoc() );

		portals[0]->bTimer = true;
		portals[1]->bTimer = true;
	}
}

void HelloWorld::cleanup(void)
{
	delete theButtons;
	delete theDoors;
	delete enemies;
	delete [] theMobileSpike;
	delete [] theCoin;
	delete player;

	delete mobileSpikePositionsX;
	delete mobileSpikePositionsY;
	delete coinPositionsX;
	delete coinPositionsY;

	for (int i = 0; i < 2; i++)
	{
		delete portals[i];
		delete _hud[i];
	}

	for (int i = 0; i < MAX_HORIZONTAL; ++i)
	{
		for (int j = 0; j < MAX_VERTICAL; ++j) delete m_arrayMap[i][j];
	}
}

Scene* HelloWorld::createScene(void)
{
    // 'scene' is an autorelease object
    Scene* scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setGravity(Vect(0.0f, -98.0f * 2));
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    // 'layer' is an autorelease object
    HelloWorld* layer = HelloWorld::create();
	layer->setPhyWorld(scene->getPhysicsWorld());

	layer->scheduleUpdate();

    // add layer as a child to scene
    scene->addChild(layer);
	
	const Size visibleSize = Director::getInstance()->getVisibleSize();

	Node* edgeNode = Node::create();
	const Point center = Point(visibleSize.width*0.5f, visibleSize.height*0.5f);
	edgeNode->setPosition(center);
	
	/*
	float RoomWidth = GETVALUE("RoomWidth");
	float RoomHeight = GETVALUE("RoomHeight");
	Size RoomSize = Size(RoomWidth,RoomHeight);
	PhysicsBody* body = PhysicsBody::createEdgeBox(RoomSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	edgeNode->setPhysicsBody(body);
	*/

	scene->addChild(edgeNode);

	scene->getDefaultCamera()->create();

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init(void)
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init()) return false;
    
    const Size visibleSize = Director::getInstance()->getVisibleSize();
    const Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    //auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
	//				CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	//closeItem->setPosition(Vec2(origin.x + visibleSize.width -
	//					closeItem->getContentSize().width*0.5f,
	//					origin.y + closeItem->getContentSize().height*0.5f));

    // create menu, it's an autorelease object
   // auto menu = Menu::create(closeItem, NULL);
   // menu->setPosition(Vec2::ZERO);
   // this->addChild(menu, G_LAYERING_TYPES::G_HUD);

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

	audioLaser = CocosDenshion::SimpleAudioEngine::getInstance();
	audioBackground = CocosDenshion::SimpleAudioEngine::getInstance();
	audioHurt = CocosDenshion::SimpleAudioEngine::getInstance();
	audioDoor = CocosDenshion::SimpleAudioEngine::getInstance();
	audioLoad = CocosDenshion::SimpleAudioEngine::getInstance();
	audioPortal = CocosDenshion::SimpleAudioEngine::getInstance();

	audioBackground->preloadBackgroundMusic("bgm.wav");
	audioBackground->playBackgroundMusic("bgm.wav",true);

	audioLaser->preloadEffect("laser.wav");
	audioHurt->preloadEffect("hurt.mp3");
	audioDoor->preloadEffect("door.wav");
	audioLoad->preloadEffect("load.mp3");
	audioPortal->preloadEffect("teleport.mp3");

	levelCounter = temp = points = 0;
	coinCounter = 0;
	mobileSpikeCounter = 0;
	//buttonCounter = 0;
	//laserCounter = 0;
	//tempDMGTimer = 0;

	location = Point(visibleSize.width*0.5f, visibleSize.height*0.5f);

	//Traps = new CTraps(this,100,100);

	CResourceTable::getInstance()->label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
   	CResourceTable::getInstance()->label->setPosition(Vec2(origin.x + visibleSize.width*0.5f,
        origin.y + visibleSize.height - 50 - CResourceTable::getInstance()->label->getContentSize().height));

    //this->addChild(CResourceTable::getInstance()->label, G_LAYERING_TYPES::G_GAME);

	CResourceTable::getInstance()->label->setString("yes");

	for (int i = 0; i < 2; i++)
	{
		_hud[i] = nullptr;
		portals[i] = nullptr;
	}

	for (int i = 0; i < MAX_HORIZONTAL; ++i)
	{
		for (int j = 0; j < MAX_VERTICAL; ++j)
			m_arrayMap[i][j] = nullptr;
	}
	
	theMobileSpike = nullptr;
	theButtons = nullptr;
	theDoors = nullptr;
	theCoin = nullptr;
	enemies = nullptr;

	player = new CPlayer(this,location);//initialise player

	HUD();

	loadLevel();

	//this->runAction(Follow::create(player->m_Sprite));

	EventListenerKeyboard* KeyboardListener = EventListenerKeyboard::create();
	KeyboardListener->onKeyPressed = CC_CALLBACK_2(CPlayer::KeyPress,player);
	KeyboardListener->onKeyReleased = CC_CALLBACK_2(CPlayer::KeyRelease,player);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(KeyboardListener,player->m_Sprite);

	EventListenerMouse* MouseListener = EventListenerMouse::create();
	MouseListener->onMouseMove = CC_CALLBACK_1(CPlayer::MouseMove,player);
	MouseListener->onMouseDown = CC_CALLBACK_1(CGun::MouseDown, player->PortalGun);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(MouseListener,player->m_Sprite);

	EventListenerPhysicsContact* contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener,this);

	EventListenerTouchOneByOne* touchListener = EventListenerTouchOneByOne ::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(CPlayer::TouchDown,player);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener,this);

	//MapLoad.join();

	firstTimeInit = true;

	return true;
}

void HelloWorld::LoadFile(const string mapName)
{
	unsigned int theLineCounter = 0;
	unsigned int theMaxNumOfColumns = 0;

	mobileSpikePositionsX = new unsigned int[10];
	mobileSpikePositionsY = new unsigned int[10];

	coinPositionsX = new unsigned int[10];
	coinPositionsY = new unsigned int[10];

	coinCounter = 0;
	mobileSpikeCounter = 0;

	ifstream file;
	file.open( CCFileUtils::getInstance( )->fullPathForFilename((mapName).c_str()) );

	if (file.is_open())
	{
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
					unsigned int theColumnCounter = 0;
					//CField* m_arrayMap;
					istringstream iss(aLineOfText);

					while (getline(iss, token, ','))
					{
						int value = atoi(token.c_str());
						switch (value)
						{
							case 2:
								m_arrayMap[theColumnCounter][theLineCounter - 1] = new CField(this,0, theColumnCounter, theLineCounter + 1);
								theDoors = new Door(this, theColumnCounter, theLineCounter + 1);
								break;
							case 4:
								m_arrayMap[theColumnCounter][theLineCounter - 1] = new CField(this,0, theColumnCounter, theLineCounter + 1);
								enemies = new CEnemy(this, Point(theColumnCounter, theLineCounter + 1));
								break;
							case 5:
								m_arrayMap[theColumnCounter][theLineCounter - 1] = new CField(this,0, theColumnCounter, theLineCounter + 1);
								theButtons = new Button(this, theColumnCounter, theLineCounter + 1);
								break;
							case 6:
								m_arrayMap[theColumnCounter][theLineCounter - 1] = new CField(this,0, theColumnCounter, theLineCounter + 1);
								mobileSpikePositionsX[mobileSpikeCounter] = theColumnCounter;
								mobileSpikePositionsY[mobileSpikeCounter] = theLineCounter + 1;
								mobileSpikeCounter++;
								//theMobileSpike = new CMobileSpike(this, theColumnCounter, theLineCounter + 1);
								break;
							case 8:
								m_arrayMap[theColumnCounter][theLineCounter - 1] = new CField(this,0, theColumnCounter, theLineCounter + 1);
								coinPositionsX[coinCounter] = theColumnCounter;
								coinPositionsY[coinCounter] = theLineCounter + 1;
								coinCounter++;
								//theCoin = new CCoin(this, theColumnCounter, theLineCounter + 1);
								break;
							default:
								m_arrayMap[theColumnCounter][theLineCounter - 1] = new CField(this,value, theColumnCounter, theLineCounter + 1);
								break;
						}

						theColumnCounter++;
					}
				}
			}

			theLineCounter++;
	
		}
	}
	theCoin = new CCoin*[coinCounter];
			//coinPositionsX = new float[coinCounter];
			//coinPositionsY = new float[coinCounter];
			for(int i = 0; i < coinCounter ; i++)
			{
				theCoin[i] = new CCoin(this, coinPositionsX[i], coinPositionsY[i]);
			}

			theMobileSpike = new CMobileSpike*[mobileSpikeCounter];
			//mobileSpikePositionsX = new float[mobileSpikeCounter];
			//mobileSpikePositionsY = new float[mobileSpikeCounter];
			for(int i = 0; i < mobileSpikeCounter ; i++)
			{
				theMobileSpike[i] = new CMobileSpike(this, mobileSpikePositionsX[i], mobileSpikePositionsY[i]);
			}
}

void HelloWorld::HUD(void)
{
	const Size visibleSize = Director::getInstance()->getVisibleSize();
	const Vec2 origin = Director::getInstance()->getVisibleOrigin();
	const Size v = Director::getInstance()->getWinSize();

	//CHUD* _hud = NULL;

	_hud[0] = new CHUD("Points: ",points,Vec2(origin.x,origin.y + v.height), 1, 1 );
	this->addChild(_hud[0], G_LAYERING_TYPES::G_HUD);
	
	_hud[1] = new CHUD("Timer: ",temp, Vec2(origin.x + v.width,origin.y + v.height), 1, -1 );
	this->addChild(_hud[1], G_LAYERING_TYPES::G_HUD);
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
	//bitmask 2 = spike/mobile spike
	//bitmask 3 = tiles with portal/pressed button/enemyspawner - cannot be collided with
	//bitmask 4 = portal projectile
	//bitmask 5 = tiles/closedoor
	//bitmask 6 = button
	//bitmask 7 = portal
	//bitmask 8 = enemy
	//bitmask 9 = opendoor
	//bitmask 10 = laser
	//bitmask 11 = mobilespike
	//bitmask 12 = coins

	//player with opendoor
	if((First->getCollisionBitmask() == 1 && Second->getCollisionBitmask() == 3) || (First->getCollisionBitmask() == 3 && Second->getCollisionBitmask() == 1))
	{
		return false;
	}
	//player with laser
	if((First->getCollisionBitmask() == 1 && Second->getCollisionBitmask() == 10) || (First->getCollisionBitmask() == 10 && Second->getCollisionBitmask() == 1))
	{
		audioLaser->playEffect("laser.wav");
		player->setPos(location);
		return false;
	}
	//player with coins
	if ((First->getCollisionBitmask() == 12 && Second->getCollisionBitmask() == 1) || (First->getCollisionBitmask() == 1 && Second->getCollisionBitmask() == 12))
	{
			for(int i = 0 ; i < coinCounter ; i++)
			{
				float currentTemp = 1000000;
				int tempI = 0;
				if(sqrtf( fabsf(theCoin[i]->m_Sprite->getPosition().x - player->m_Sprite->getPosition().x) + fabsf(theCoin[i]->m_Sprite->getPosition().y - player->m_Sprite->getPosition().y) ) < currentTemp)
				{
					currentTemp = sqrtf( fabsf(theCoin[i]->m_Sprite->getPosition().x - player->m_Sprite->getPosition().x) + fabsf(theCoin[i]->m_Sprite->getPosition().y - player->m_Sprite->getPosition().y) );
					tempI = i;
				}
				if(i++ == coinCounter)
				theCoin[tempI]->PickedUp();
			}
		points = points + 100;
		_hud[0]->valueupdate(points);
		return false;
	}
	//player with traps
	if((First->getCollisionBitmask() == 1 && Second->getCollisionBitmask() == 2) || (First->getCollisionBitmask() == 2 && Second->getCollisionBitmask() == 1))
	{
		//player->setHP(player->getHp() - 1);
		//this->removeChild(player->m_Sprite);
		//this->removeChild(player->PortalGun->m_Sprite);
		//loadLevel();
		//Director::getInstance()->end();
		audioHurt->playEffect("hurt.mp3");
		player->setPos(location);
		return false;
	}
	//player with button
	if((First->getCollisionBitmask() == 1 && Second->getCollisionBitmask() == 6) || (First->getCollisionBitmask() == 6 && Second->getCollisionBitmask() == 1))
	{
		audioDoor->playEffect("door.wav");
		if(First->getCollisionBitmask() == 6)//if first is button
		{
			First->setCollisionBitmask(3);//button is now a "pressed button"
			theButtons->pressed();
			theDoors->openDoor();
			//corressponding door opens code//scraped
		}
		else if(Second->getCollisionBitmask() == 6)//if second is button instead
		{
			Second->setCollisionBitmask(3);//button is now a "pressed button"
			theButtons->pressed();
			theDoors->openDoor();
			//corressponding door opens code//scraped
		}
		return false;
	}
	//player with portal
	if((First->getCollisionBitmask() == 1 && Second->getCollisionBitmask() == 7) || (First->getCollisionBitmask() == 7 && Second->getCollisionBitmask() == 1))
	{
		//portal teleport code
		if (First->getCollisionBitmask() == 7)//if first is portal
		{
			if (First->getPosition() == portals[0]->getLoc()) teleportaling(1);
			else teleportaling(0);
		}
		else if (Second->getCollisionBitmask() == 7)//if second is portal instead
		{
			if (Second->getPosition() == portals[0]->getLoc()) teleportaling(1);
			else teleportaling(0);
		}
	}
	//player with mobilespike
	if((First->getCollisionBitmask() == 1 && Second->getCollisionBitmask() == 11) || (First->getCollisionBitmask() == 11 && Second->getCollisionBitmask() == 1))
	{
		audioHurt->playEffect("hurt.mp3");
		player->setPos(location);
		return false;
	}
	//player with opendoor
	if((First->getCollisionBitmask() == 1 && Second->getCollisionBitmask() == 9) || (First->getCollisionBitmask() == 9 && Second->getCollisionBitmask() == 1))
	{
		audioLoad->playEffect("load.mp3");
		levelCounter++;
		loadLevel();
		return false;
	}
	//player with tile
	if ((First->getCollisionBitmask() == 1 && Second->getCollisionBitmask() == 5) || (First->getCollisionBitmask() == 5 && Second->getCollisionBitmask() == 1))
	{
		player->inAir = false;
		player->airtime = 0;
	}
	//portal projectile with tiles
	if((First->getCollisionBitmask() == 4 && Second->getCollisionBitmask() == 5) || (First->getCollisionBitmask() == 5 && Second->getCollisionBitmask() == 4))
	{
		if (player->PortalGun->Fired)
		{
			if (First->getCollisionBitmask() == 4)//if portal projectile is First
			{
				//remove projectile, spawn portal sprite
				if (portals[player->PortalGun->Current] == nullptr)
					portals[player->PortalGun->Current] = new CPortals(this, player->PortalGun->Current, First->getPosition());
				else portals[player->PortalGun->Current]->setLoc(First->getPosition());
			}
			else if (Second->getCollisionBitmask() == 4)//if portal projectile is Second instead
			{
				//remove projectile, spawn portal sprite
				if (portals[player->PortalGun->Current] == nullptr)
					portals[player->PortalGun->Current] = new CPortals(this,player->PortalGun->Current, Second->getPosition());
				else portals[player->PortalGun->Current]->setLoc(Second->getPosition());
			}
			delete player->PortalGun->projectile[player->PortalGun->Current];
			player->PortalGun->projectile[player->PortalGun->Current] = nullptr;
			player->PortalGun->Current = (player->PortalGun->Current == 0) ? 1 : 0;
			player->PortalGun->Fired = false;
		}

		//scraped code
		//if(First->getCollisionBitmask() == 5)//if tile is First
		//{
		//	First->setCollisionBitmask(3);//tile is now a "tile with portal"
		//}
		//else if(Second->getCollisionBitmask() == 5)//if tile is Second instead
		//{
		//	First->setContactTestBitmask(3);//tile is now a "tile with portal"
		//}
	}
	//portal with everything but tiles
	if ((First->getCollisionBitmask() == 4 && Second->getCollisionBitmask() != 5) || (First->getCollisionBitmask() != 5 && Second->getCollisionBitmask() == 4))
	{
		return false;
	}
	//enemy with player
	if ((First->getCollisionBitmask() == 8 && Second->getCollisionBitmask() == 1) || (First->getCollisionBitmask() == 1 && Second->getCollisionBitmask() == 8))
	{
		//player->setHP(player->getHp() - 1);
		//this->removeChild(player->m_Sprite);
		//this->removeChild(player->PortalGun->m_Sprite);
		//loadLevel();
		//Director::getInstance()->end();
		audioHurt->playEffect("hurt.mp3");
		player->setPos(location);
		return false;
	}
	//enemy with spike
	//if ( (First->getCollisionBitmask() == 8 && Second->getCollisionBitmask() == 2) || (First->getCollisionBitmask() != 2 && Second->getCollisionBitmask() == 8) )
	//{
	//	return true;
	//}
	//enemy with laser
	if ((First->getCollisionBitmask() == 8 && Second->getCollisionBitmask() == 10) || (First->getCollisionBitmask() != 5 && Second->getCollisionBitmask() == 10))
	{
		//kill enemy
		audioLaser->playEffect("laser.wav");
		this->removeChild(enemies->m_Sprite);
		delete enemies;
		return false;
	}
	//enemy with everything but tiles
	if ( (First->getCollisionBitmask() == 8 && Second->getCollisionBitmask() != 5 ) || (First->getCollisionBitmask() != 5  && Second->getCollisionBitmask() == 8) )
	{
		//no collision
		return false;
	}
	//mobilespike with wall
	if ((First->getCollisionBitmask() == 11 && Second->getCollisionBitmask() == 5) || (First->getCollisionBitmask() == 5 && Second->getCollisionBitmask() == 11))
	{
			theMobileSpike[0]->changedirection();
			for(int i = 0 ; i < mobileSpikeCounter ; i++)
			{
				float currentTemp = 1000000;
				int tempI = 0;
				if(sqrtf( fabsf(theMobileSpike[i]->m_Sprite->getPosition().x - player->m_Sprite->getPosition().x) + fabsf(theMobileSpike[i]->m_Sprite->getPosition().y - player->m_Sprite->getPosition().y) ) < currentTemp)
				{
					currentTemp = sqrtf( fabsf(theMobileSpike[i]->m_Sprite->getPosition().x - player->m_Sprite->getPosition().x) + fabsf(theMobileSpike[i]->m_Sprite->getPosition().y - player->m_Sprite->getPosition().y) );
					tempI = i;
				}
				if(i++ == mobileSpikeCounter)
				theMobileSpike[tempI]->changedirection();
			}
	}
	//mobilespike with anything but wall
	if ((First->getCollisionBitmask() == 11 && Second->getCollisionBitmask() != 5) || (First->getCollisionBitmask() != 5 && Second->getCollisionBitmask() == 11))
	{
		return false;
	}
	return true;
}

void HelloWorld::setViewPoint(const Vec2 position)
{
	const Size winSize = CCDirector::getInstance()->getWinSize();
 
	int x = MAX(position.x, winSize.width * 0.5f);
	int y = MAX(position.y, winSize.height * 0.5f);
	x = MIN(x, ((MAX_HORIZONTAL * m_arrayMap[0][0]->m_Sprite->getContentSize().width)
		* m_arrayMap[0][0]->m_Sprite->getContentSize().width) - winSize.width * 0.5f);
	y = MIN(y, ((MAX_VERTICAL * m_arrayMap[0][0]->m_Sprite->getContentSize().height)
		* m_arrayMap[0][0]->m_Sprite->getContentSize().height) - winSize.height *0.5f);
	const Vec2 actualPosition = Vec2(x, y);
 
	const Vec2 centerOfView = Vec2(winSize.width * 0.5f, winSize.height * 0.5f);
	const Vec2 viewPoint = centerOfView - actualPosition;
    this->setPosition(viewPoint);
	//this->getScene()->setPosition(viewPoint);
	
	_hud[0]->setPosition(-viewPoint);
	_hud[1]->setPosition(-viewPoint);
}

void HelloWorld::loadLevel(void)
{
	//Size visibleSize = Director::getInstance()->getVisibleSize();
	//Point location = Point(visibleSize.width*0.5f, visibleSize.height*0.5f);
	
	timer = 0;
	if(firstTimeInit)//if all data has been initialised in init
	{
		despawnObjects();//despawn the objects
	}

	switch (levelCounter)
	{
		case 0:
			{
				player->setPos(location);
				//player->m_Sprite->setPosition(location);
				//player->PortalGun->m_Sprite->setPosition(Point(location.x + player->PortalGun->Offset, location.y));
				LoadFile( GETFILE("Map0") );
				break;
			}
		case 1:
			{
				player->setPos(location);
				LoadFile( GETFILE("Map1") );
				break;
			}
		case 2:
			{
				player->setPos(location);
				LoadFile( GETFILE("Map2") );
				break;
			}
		case 3:
			{
				player->setPos(location);
				LoadFile( GETFILE("Map3") );
				break;
			}
		default:
			{
				Director::getInstance()->end();
				break;
			}

	}
}

void HelloWorld :: despawnObjects(void)
{
	delete theDoors;
	theDoors = nullptr;
	delete enemies;
	enemies = nullptr;
	delete theButtons;
	theButtons = nullptr;
	for(int i=0;i<mobileSpikeCounter;i++)
		delete theMobileSpike[i];
	delete [] theMobileSpike;
	theMobileSpike = nullptr;
	for(int i=0;i<coinCounter;i++)
		delete theCoin[i];
	delete [] theCoin;
	theCoin = nullptr;

	for (int i = 0; i < MAX_HORIZONTAL; i++)
	{
		for (int j = 0; j < MAX_VERTICAL; j++)
		{
			delete m_arrayMap[i][j];
			m_arrayMap[i][j] = nullptr;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		delete portals[i];
		portals[i] = nullptr;
		delete player->PortalGun->projectile[i];
		player->PortalGun->projectile[i] = nullptr;
	}

	//firstTimeInit = false;
	//init();
}