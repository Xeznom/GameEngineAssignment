#include "HUD.h"


CHUD::CHUD(const std::string& _message,float value, Vec2 pos, int topbottom, int leftright)
{
	this->create();
	this->setColor(cocos2d::Color3B(0, 0, 0));

	this->setContentSize(cocos2d::Size::Size(1, 1));
	this->setAnchorPoint(cocos2d::Vec2(0, 0));

	this->initOptions(_message,value, pos, topbottom, leftright);


}

CHUD::~CHUD()
{
}
void CHUD::draw(Renderer*, const Mat4&, bool)
{

}

void CHUD::initOptions(const std::string& _message,float value, Vec2 pos, int topbottom, int leftright)
{
	_messageLabel = cocos2d::Label::createWithTTF(_message.c_str(), "fonts/Marker Felt.ttf", 24);
	//_messageLabel->setColor(cocos2d::Color3B(255, 215, 0));
	_valuemessageLabel =  cocos2d::Label::createWithTTF(std::to_string(value), "fonts/Marker Felt.ttf", 24);

	_messageLabel->setPosition(Vec2(pos.x + _messageLabel->getContentSize().width * leftright,
									pos.y - _messageLabel->getContentSize().height * topbottom));

	_valuemessageLabel->setPosition(Vec2(pos.x + _messageLabel->getContentSize().width * leftright * 2.5,
									pos.y - _messageLabel->getContentSize().height * topbottom));
	
	this->addChild(_messageLabel, 1);
	this->addChild(_valuemessageLabel, 1);
}

void CHUD::valueupdate(float value)
{
	//wei qi i need help here, i call this in helloworldscene oncontactbegin
	this->_valuemessageLabel =  cocos2d::Label::createWithTTF(std::to_string(value), "fonts/Marker Felt.ttf", 24);
}