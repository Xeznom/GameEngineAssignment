#include "Gun.h"

void CGun::update (float delta){}

void CGun::MouseMove (Event* event)
{
	EventMouse* e = (EventMouse*) event;

	float ax = e->getCursorX() - PlayerSprite->getPositionX();
	
	if (ax > 0) //If to face right.
	{
		if (Left) //If facing left
		{
			Offset = abs(Offset);
			const Point gunloc = Point(m_Sprite->getPositionX()+Offset,m_Sprite->getPositionY());
			m_Sprite->setPosition(gunloc);
			Left = false;
		}
	}
	else //If to face left.
	{
		if (!Left) //If facing right
		{
			Offset = -abs(Offset);
			const Point gunloc = Point(m_Sprite->getPositionX()+Offset,m_Sprite->getPositionY());
			m_Sprite->setPosition(gunloc);
			Left = true;
		}
	}

	const Size visibleSize = Director::getInstance()->getVisibleSize();
	const float ay = (visibleSize.height + e->getCursorY()) - PlayerSprite->getPositionY();
	const float degrees = CC_RADIANS_TO_DEGREES(atan2(-ay,ax));
	m_Sprite->setRotation(90 + degrees);
}

void CGun::MouseDown(Event* event)
{
	if (!Fired)
	{
		EventMouse* e = (EventMouse*) event;
		Current = e->getMouseButton();
		CocosDenshion::SimpleAudioEngine* audio = CocosDenshion::SimpleAudioEngine::getInstance();
		audio->playEffect("shoot.mp3");
		const Size visibleSize = Director::getInstance()->getVisibleSize();
		const Vec2 cursor = Vec2(e->getCursorX(), visibleSize.height + e->getCursorY());
		Vec2 aim = cursor - PlayerSprite->getPosition();
		aim.normalize();

		switch (Current)
		{
			case 0: case 1:
				projectile[Current] = new CProjectile(thelayer,Current);
				projectile[Current]->Init(m_Sprite->getPosition(),aim);
				Fired = true;
				break;
			default: return;
		}
	}
}

CGun::CGun(Layer* layer, const Point loc,const Sprite* playersprite)
{
	projectile[0] = projectile[1] = nullptr;
	Fired = false;
	Current = 0;
	PlayerSprite = playersprite;
	Offset = GETVALUE("GunOffset");
	Left = false;

	const std::string filename = GETFILE("PortalGun");
	m_Sprite = Sprite::create(filename);
	m_Sprite->setScale(0.3f);

	const Point gunloc = Point(loc.x+Offset,loc.y);
	m_Sprite->setPosition(gunloc);
	m_Sprite->setAnchorPoint(Vec2(0.5f,0));

	thelayer = layer;
	layer->addChild(m_Sprite,0);
}

CGun::~CGun (void)
{
	delete projectile[1];
	delete projectile[0];
}