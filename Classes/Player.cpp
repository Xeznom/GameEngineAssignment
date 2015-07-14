#include "Player.h"
#include <cmath>

const int CPlayer::STATIC_SPRITE_TAG = 0;

void CPlayer::update (float delta)
{
	Vec2 loc;
	loc = m_Sprite->getPosition();
	
	if (Jump)
		loc.y += speed * delta * 2.5;

	if (Left)
	{
		//body->applyImpulse(Vect(1,0));
		loc.x -= speed * delta;
	}
	if (Right)
		loc.x += speed * delta;

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

void CPlayer::KeyPress (EventKeyboard::KeyCode keycode,Event* event)
{
	switch (keycode)
	{
		case EventKeyboard::KeyCode::KEY_W:
			Jump = true;
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

CPlayer::CPlayer(Layer* layer, const Point loc)
{
	HP = 3;
	//Up = Left = Down = Right = false;
	//speed = 50.0f;
	//std::string filename = CResouceTable::getInstance()->GetFileName("Player");
	//if (m_Sprite ==nullptr) m_Sprite = cocos2d::Sprite::create(filename);

	Jump = Left = Right = false;
	speed = GETVALUE("WalkSpeed");
	std::string filename = GETFILE("Player");
	m_Sprite = Sprite::create(filename);

	//player physics
	body = PhysicsBody::createBox(Size(m_Sprite->getContentSize().width,m_Sprite->getContentSize().height));
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
	Node* nodeA = contact.getShapeA()->getBody()->getNode();
	Node* nodeB = contact.getShapeB()->getBody()->getNode();

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

void CPlayer::setHP(const int Set)
{
	HP = Set;
}

const int CPlayer::getHp() const
{
	return HP;
} 

void CPlayer::setPos(const Vec2 Set)
{
	m_Sprite->setPosition(Set);
	PortalGun->m_Sprite->setPosition(Point(Set.x + PortalGun->Offset, Set.y));
}