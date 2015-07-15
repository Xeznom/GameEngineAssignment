#include "HUD.h"


CHUD::CHUD(const std::string& _message, Vec2 pos, int topbottom, int leftright)
{
	this->create();
	this->setColor(cocos2d::Color3B(0, 0, 0));

	this->setContentSize(cocos2d::Size::Size(1, 1));
	this->setAnchorPoint(cocos2d::Vec2(0, 0));

	this->initOptions(_message, pos, topbottom, leftright);
}

CHUD::~CHUD()
{
}

void CHUD::initOptions(const std::string& _message, Vec2 pos, int topbottom, int leftright)
{
	_messageLabel = cocos2d::LabelBMFont::create(_message.c_str(), "Marker Felt Small.fnt");
	_messageLabel->setColor(cocos2d::Color3B(255, 215, 0));

	addChild(_messageLabel, 1);

	_messageLabel->setPosition(Vec2(pos.x + _messageLabel->getContentSize().width * leftright,
									pos.y - _messageLabel->getContentSize().height * topbottom));
}