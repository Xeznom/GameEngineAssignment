#include "Player.h"
#include <cmath>

const int CPlayer::STATIC_SPRITE_TAG = 0;

void CPlayer::update (float delta)
{
	cocos2d::Vec2 loc = m_Sprite->getPosition();
	
	if (Jump)
		loc.y += speed * delta * 5;

	if (Left)
		loc.x -= speed * delta;
	if (Right)
		loc.x += speed * delta;

	m_Sprite->setPosition(loc);
	PortalGun->m_Sprite->setPosition(Point(loc.x+PortalGun->Offset,loc.y));
	PortalGun->update(delta);
}

void CPlayer::MouseMove (cocos2d::Event* event)
{
	cocos2d::EventMouse* e = (cocos2d::EventMouse*) event;
	float ax = e->getCursorX() - m_Sprite->getPositionX();

	if (ax > 0) //If to face right.
	{
		if (!m_Sprite->isFlippedX()) //If facing left.
		{
			m_Sprite->setFlippedX(false); //Flip to face right.
		}
	}
	else //If to face left.
	{
		if (m_Sprite->isFlippedX()) //If facing right.
		{
			m_Sprite->setFlippedX(true); //Flip to face left.
		}
	}

	PortalGun->MouseMove(event);
}

void CPlayer::KeyPress (cocos2d::EventKeyboard::KeyCode keycode,cocos2d::Event* event)
{
	switch (keycode)
	{
		case cocos2d::EventKeyboard::KeyCode::KEY_W:
			Jump = true;
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_A:
			Left = true;
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_D:
			Right = true;
			break;
		default:
			break;
	}
}

void CPlayer::KeyRelease(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	switch (keycode)
	{
		case cocos2d::EventKeyboard::KeyCode::KEY_W:
			Jump = false;
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_A:
			Left = false;
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_D:
			Right = false;
			break;
		default:
			break;
	}
}

CPlayer::CPlayer(cocos2d::Layer* layer, const cocos2d::Point loc)
{
	HP = 3;
	//Up = Left = Down = Right = false;
	//speed = 50.0f;
	//std::string filename = CResouceTable::getInstance()->GetFileName("Player");
	//if (m_Sprite ==nullptr) m_Sprite = cocos2d::Sprite::create(filename);

	Jump = Left = Right = false;
	speed = GETVALUE("WalkSpeed");
	std::string filename = GETFILE("Player");
	m_Sprite = cocos2d::Sprite::create(filename);

	//player physics
	auto body = PhysicsBody::createCircle(m_Sprite->getContentSize().width);
	body->setMass( GETVALUE("PlayerMass") );
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(true);
	m_Sprite->setPhysicsBody(body);

	m_Sprite->setScale(0.15f);
	m_Sprite->setPosition(loc);

	PortalGun = new CGun(layer, loc, m_Sprite);

	layer->addChild(m_Sprite,0);
}

CPlayer::~CPlayer(void)
{
	delete PortalGun;
	PortalGun = nullptr;
}

bool CPlayer::onContactBegin(PhysicsContact& contact)
{
	cocos2d::Node* nodeA = contact.getShapeA()->getBody()->getNode();
	cocos2d::Node* nodeB = contact.getShapeB()->getBody()->getNode();

	if (nodeA && nodeB)
	{
		if (nodeA->getTag() == STATIC_SPRITE_TAG)
		{
			nodeB->removeFromParentAndCleanup(true);
		}
		else if (nodeB->getTag() == STATIC_SPRITE_TAG)
		{
			nodeA->removeFromParentAndCleanup(true);
		}
	}

	//bodies can collide
	return true;
}

void CPlayer :: setHP(int Set)
{
	HP = Set;
}

int CPlayer :: getHp()
{
	return HP;
} 
