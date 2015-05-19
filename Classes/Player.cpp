#include "Player.h"
#include <cmath>

const char* CPlayer::filename = "Player.png";

void CPlayer::update (float delta)
{
	cocos2d::Vec2 loc = m_Sprite->getPosition();

	if (Up)
	{
		loc.y += speed * delta;
	}
	if (Left)
	{
		loc.x -= speed * delta;
	}
	if (Down)
	{
		loc.y -= speed * delta;
	}
	if (Right)
	{
		loc.x += speed * delta;
	}

	m_Sprite->setPosition(loc);
}

void CPlayer::MouseMove (cocos2d::Event* event)
{
	cocos2d::EventMouse* e = (cocos2d::EventMouse*) event;
	
	float ay = e->getCursorY() - m_Sprite->getPositionY();
	float ax = e->getCursorX() - m_Sprite->getPositionX();

	float degrees = CC_RADIANS_TO_DEGREES(atan2(ay,ax));
	
	if(degrees < 0) degrees = 360 + degrees;

	//m_Sprite->setRotation( 90 + degrees);
}

void CPlayer::KeyPress (cocos2d::EventKeyboard::KeyCode keycode,cocos2d::Event* event)
{
	switch (keycode)
	{
		case cocos2d::EventKeyboard::KeyCode::KEY_W:
			Up = true;
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_A:
			Left = true;
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_S:
			Down = true;
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_D:
			Right = true;
			break;
		default:
			break;
	}
}

void CPlayer::Render()
{
	//Size visibleSize = Director::getInstance()->getVisibleSize();

	m_Sprite->setPosition( Point(this->x, this->y) );
}
void CPlayer::KeyRelease (cocos2d::EventKeyboard::KeyCode keycode,cocos2d::Event* event)
{
	switch (keycode)
	{
		case cocos2d::EventKeyboard::KeyCode::KEY_W:
			Up = false;
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_A:
			Left = false;
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_S:
			Down = false;
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_D:
			Right = false;
			break;
		default:
			break;
	}
}

CPlayer::CPlayer(const cocos2d::Point loc)
{
	Up = Left = Down = Right = false;
	speed = 50.0f;
	m_Sprite = cocos2d::Sprite::create(filename);
	m_Sprite->setScale(0.5f);
	m_Sprite->setPosition(loc);
}

CPlayer::~CPlayer(void){}
