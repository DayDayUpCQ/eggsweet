#ifndef _STARTSCENE_H_
#define _STARTSCENE_H_
#include "cocos2d.h"

class StartScene : public cocos2d::CCScene
{
public:

    CREATE_FUNC(StartScene);

    bool init();

    void startGame(CCNode *sender);
};

#endif