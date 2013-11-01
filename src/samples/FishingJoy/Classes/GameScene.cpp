#include "GameScene.h"

using namespace cocos2d;

bool GameScene::init()
{
    bool status = false;

    do 
    {
        CC_BREAK_IF(! CCScene::init());

        CCSize size = CCDirector::sharedDirector()->getWinSize();
        CCLabelTTF* pLabel = CCLabelTTF::create("GameScene", "Arial", 24);
        CC_BREAK_IF(! pLabel);
        pLabel->setPosition(ccp(size.width / 2, size.height - 50));
        this->addChild(pLabel, 1);
        status = true;
    } while (0);

    return status;
}