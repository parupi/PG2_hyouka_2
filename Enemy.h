#pragma once
#include "EBullet.h"
class Enemy
{
private:
	EnemyStates enemy_[ENEMY_NUM];
public:
	Enemy();
	~Enemy();
	void Initialize();
	void UpData();
	void Draw();
	float GetPosX(int i) { return enemy_[i].pos_.x; };
	float GetPosY(int i) { return enemy_[i].pos_.y; };
	bool GetAlive(int i) { return enemy_[i].isAlive_; };
	void SetAlive(bool alive, int i) { enemy_[i].isAlive_ = alive; };

	EBullet* eBullet;
};

