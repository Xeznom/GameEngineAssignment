#include "Player.h"
#include <cmath>

const int CPlayer::STATIC_SPRITE_TAG = 0;

void CPlayer::update (float delta)
{
	const Vec2 loc = m_Sprite->getPosition();
	
	frames += 1;
	if (frames > 5) frames = 0;
	m_Sprite->setTexture(playerFrames[frames]);


	if (Jump)
		body->applyImpulse(Vect(0,speed * delta * 125.0f));
	//if (Jump) loc.y += speed * delta * 2.5f;

	//body->applyImpulse(Vect(1,0));
	if (Left) //loc.x -= speed * delta;
	{
		if(!inAir)
			body->applyImpulse(Vect(-speed * delta * 25.0f,0));
		else if(inAir)
			body->applyImpulse(Vect(-speed * delta * 5.0f,0));
	}
	if (Right) //loc.x += speed * delta;
	{
		if(!inAir)
			body->applyImpulse(Vect(speed * delta * 25.0f,0));
		else if(inAir)
			body->applyImpulse(Vect(speed * delta * 5.0f,0));
	}
	
	m_Sprite->setPhysicsBody(body);
	m_Sprite->setPosition(loc);
	PortalGun->m_Sprite->setPosition(Point(loc.x+PortalGun->Offset,loc.y));
	PortalGun->update(delta);
}

void CPlayer::MouseMove (Event* event)
{
	EventMouse* e = (EventMouse*) event;
	float ax = e->getCursorX() - m_Sprite->getPositionX();

	if (ax > 0) //If to face right.
	{
		if (!m_Sprite->isFlippedX()) //If facing left.
			m_Sprite->setFlippedX(false); //Flip to face right.
	}
	else //If to face left.
	{
		if (m_Sprite->isFlippedX()) //If facing right.
			m_Sprite->setFlippedX(true); //Flip to face left.
	}

	PortalGun->MouseMove(event);
}

void CPlayer::KeyPress (EventKeyboard::KeyCode keycode,Event* event)
{
	switch (keycode)
	{
		case EventKeyboard::KeyCode::KEY_W:
			if(inAir != true)
			{
				inAir = Jump = true;
				audioJump->playEffect("jump.mp3");
			}
			break;
		case EventKeyboard::KeyCode::KEY_A:
			Left = true;
			break;
		case EventKeyboard::KeyCode::KEY_D:
			Right = true;
			break;
		default:
			break;
	}
}

void CPlayer::KeyRelease(EventKeyboard::KeyCode keycode, Event* event)
{
	switch (keycode)
	{
		case EventKeyboard::KeyCode::KEY_W:
			Jump = false;
			break;
		case EventKeyboard::KeyCode::KEY_A:
			Left = false;
			break;
		case EventKeyboard::KeyCode::KEY_D:
			Right = false;
			break;
		default:
			break;
	}
}

bool CPlayer::TouchDown (Touch* touch, Event* event)
{
	const Vec2 loc = touch->getLocationInView();

	Jump = Left = Right = false;

	if (SLeft->getBoundingBox().containsPoint(loc)) Left = true;
	else if (SRight->getBoundingBox().containsPoint(loc)) Right = true;
	else if (SUp->getBoundingBox().containsPoint(loc)) Jump = true;

	PortalGun->TouchDown(touch,event);

	return true;
}

CPlayer::CPlayer(Layer* layer, const Point loc)
{
	HP = 3;
	frames = 0;
	//Up = Left = Down = Right = false;
	//speed = 50.0f;
	//std::string filename = CResouceTable::getInstance()->GetFileName("Player");
	//if (m_Sprite ==nullptr) m_Sprite = cocos2d::Sprite::create(filename);

	audioJump = CocosDenshion::SimpleAudioEngine::getInstance();
	audioJump->preloadEffect("jump.mp3");

	Jump = Left = Right = false;
	speed = GETVALUE("WalkSpeed");
	std::string filename = GETFILE("Player");
	m_Sprite = Sprite::create(filename);
	m_Sprite->setName("player");

	SLeft = Sprite::create ("LeftButton.png");
	SLeft->setPosition (100,100);
	layer->addChild(SLeft,2);

	SRight = Sprite::create ("RightButton.png");
	SRight->setPosition(300,100);
	layer->addChild(SRight,2);

	SUp = Sprite::create ("UpButton.png");
	SUp->setPosition(200,200);
	layer->addChild(SUp,2);

	//player physics
	const Size size = Size(m_Sprite->getContentSize().width, m_Sprite->getContentSize().height);
	body = PhysicsBody::createBox(size);
	body->setMass( GETVALUE("PlayerMass") );
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(true);
	body->setRotationEnable(false);
	m_Sprite->setPhysicsBody(body);
	//m_Sprite->setScale(10.0f);
	m_Sprite->setPosition(loc);

	PortalGun = new CGun(layer, loc, m_Sprite);

	layer->addChild(m_Sprite,0);
	thelayer = layer;
}

CPlayer::~CPlayer(void)
{
	thelayer->removeChild(SLeft);
	thelayer->removeChild(SRight);
	thelayer->removeChild(SUp);
	delete PortalGun;
}

bool CPlayer::onContactBegin(PhysicsContact& contact)
{
	Node* nodeA = contact.getShapeA()->getBody()->getNode();
	Node* nodeB = contact.getShapeB()->getBody()->getNode();

	if (nodeA && nodeB)
	{
		if (nodeA->getTag() == STATIC_SPRITE_TAG)
			nodeB->removeFromParentAndCleanup(true);
		else if (nodeB->getTag() == STATIC_SPRITE_TAG)
			nodeA->removeFromParentAndCleanup(true);
	}

	//bodies can collide
	return true;
}

void CPlayer::setPos(const Vec2 Set)
{
	//m_Sprite->removeFromPhysicsWorld();
	const Size size = Size(m_Sprite->getContentSize().width, m_Sprite->getContentSize().height);
	PhysicsBody* newbody = PhysicsBody::createBox(size);
	newbody->setMass( GETVALUE("PlayerMass") );
	newbody->setCollisionBitmask(1);
	newbody->setContactTestBitmask(true);
	newbody->setRotationEnable(false);
	body = newbody;

	m_Sprite->setPhysicsBody(body);

	m_Sprite->setPosition(Set);
	const Point point = Point(Set.x + PortalGun->Offset, Set.y);
	PortalGun->m_Sprite->setPosition(point);
}