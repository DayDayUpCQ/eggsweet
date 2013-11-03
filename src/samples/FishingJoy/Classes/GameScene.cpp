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
        this->addChild(pLabel, 0);
        status = true;
        CCSprite *sprite = CCSprite::create("Button.png");
        CC_BREAK_IF(! sprite);
        sprite->setPosition(ccp(100, 100));
       
        // 如何实现连续动作
        // CCAction *action1 = CCMoveTo::create(1.0f, ccp(0, 0));
        // CC_BREAK_IF(! action1);
        // CCAction *action2 = CCMoveTo::create(1.0f, ccp(100, 100));
        // CC_BREAK_IF(! action2);
        // CCAction *action = CCSequence::create(action1, action2, NULL);
        
        // CCSequence类的具体作用
        // CCFiniteTimeAction *placeAction1 = CCPlace::create(ccp(100, 100));
        // CCAction *action = CCSequence::create(placeAction1, placeAction2, NULL);
        
        // 跳跃
        // CCAction *action = CCJumpTo::create(2.0f, ccp(400, 1), 100, 5);

        // 贝塞尔曲线
//         ccBezierConfig bezierCfg;
//         bezierCfg.controlPoint_1 = ccp(20, 0);
//         bezierCfg.controlPoint_2 = ccp(200, 30);
//         bezierCfg.endPosition = ccp(160, 30);
//         CCFiniteTimeAction *beizerAction = CCBezierTo::create(2, bezierCfg);
//         CCAction *action = CCSequence::create(beizerAction, NULL);

        CCFiniteTimeAction *scaleAction = CCScaleTo::create(0.5, 1.5);
        CCAction *action = CCSequence::create(scaleAction, NULL);
        sprite->runAction(action);
        this->addChild(sprite, 1);
    } while (0);

    return status;
}