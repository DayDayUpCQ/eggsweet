#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_
#include "cocos2d.h"

class GameScene : public cocos2d::CCScene
{
public:

    CREATE_FUNC(GameScene);

    bool init();
};

#endif