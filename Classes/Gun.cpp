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
			Point gunloc = Point(m_Sprite->getPositionX()+Offset,m_Sprite->getPositionY());
			m_Sprite->setPosition(gunloc);
			Left = false;
		}
	}
	else //If to face left.
	{
		if (!Left) //If facing right
		{
			Offset = -abs(Offset);
			Point gunloc = Point(m_Sprite->getPositionX()+Offset,m_Sprite->getPositionY());
			m_Sprite->setPosition(gunloc);
			Left = true;
		}
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	float ay = (visibleSize.height + e->getCursorY()) - PlayerSprite->getPositionY();
	float degrees = CC_RADIANS_TO_DEGREES(atan2(-ay,ax));
	m_Sprite->setRotation(90 + degrees);
}

void CGun::MouseDown(Event* event)
{
	EventMouse* e = (EventMouse*) event;
	const int mouseButton = e->getMouseButton();

	switch (mouseButton)
	{
		case 0:
			if (!Fired)
			{
				Vec2 aim = e->getLocation() - m_Sprite->getPosition();
				aim.normalize();
				projectile[Alternate] = new CProjectile(thelayer,Alternate);
				projectile[Alternate]->Init(m_Sprite->getPosition(),aim);
				Fired = true;
			}
			break;
		default:
			break;
	}
}

CGun::CGun(Layer* layer, const Point loc,const Sprite* playersprite)
{
	projectile[0] =  projectile[1] = nullptr;
	Fired = false;
	Alternate = 0;
	PlayerSprite = playersprite;
	Offset = GETVALUE("GunOffset");
	Left = false;

	std::string filename = GETFILE("PortalGun");
	m_Sprite = Sprite::create(filename);
	m_Sprite->setScale(0.3f);

	Point gunloc = Point(loc.x+Offset,loc.y);
	m_Sprite->setPosition(gunloc);
	m_Sprite->setAnchorPoint(Vec2(0.5f,0));

	thelayer = layer;
	layer->addChild(m_Sprite,0);
}

CGun::~CGun (void)
{
	delete projectile[1];
	projectile[1] = nullptr;
	delete projectile[0];
	projectile[0] = nullptr;
}