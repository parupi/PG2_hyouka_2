#pragma once
#include"stdio.h"
#include"math.h"
#include "Player.h"
#include "Enemy.h"
class Stage
{
private:
	int clearNum_;
public:
	void Initialize();
	void UpData(char* keys);
	void Draw();
	Stage();
	~Stage();

	int GetClearNum() { return clearNum_; };

	Player* player;
	Enemy* enemy;
};

