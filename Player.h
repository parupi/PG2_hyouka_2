#pragma once
#include "PBullet.h"
class Player
{
private:
	PlayerStates player_;
public:
	Player();
	~Player();
	void UpData(char* keys);
	void Draw();
	void Initialize();

	float GetPosX() { return player_.pos_.x; };
	float GetPosY() { return player_.pos_.y; };
	int GetHP() { return player_.hp_; };
	void SetHP(int hp) { player_.hp_ = hp; };

	PBullet* pBullet;
};

