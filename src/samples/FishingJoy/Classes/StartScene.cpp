#include "StartScene.h"
#include "GameScene.h"

using namespace cocos2d;

bool StartScene::init()
{
    bool status = false;

    do 
    {
        CC_BREAK_IF(! CCScene::init());
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        
        CCMenuItem *startGameItem = CCMenuItemFont::create("Start", this, menu_selector(StartScene::startGame));
        CC_BREAK_IF(!startGameItem);
        startGameItem->setPosition(ccp(winSize.width/2, winSize.height/2));

        CCMenu *menu = CCMenu::create(startGameItem, NULL);
        CC_BREAK_IF(!menu);

        menu->setPosition(CCPointZero);
        this->addChild(menu);
        status = true;
    } while (0);

    return status;
}

void StartScene::startGame( CCNode *sender )
{
    GameScene *gameScene = GameScene::create();
    CCDirector::sharedDirector()->replaceScene(gameScene);
}
