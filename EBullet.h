#pragma once
#include "Novice.h"
#include "stdio.h"
#include "Function.h"
class EBullet
{
private:
	Bullet bullet_[ENEMY_NUM][ENEMY_BULLET_NUM];
public:
	EBullet();
	~EBullet();
	void Initialize();
	void UpData();
	void Draw();

	float GetPosX(int i, int j) { return bullet_[i][j].pos_.x; };
	float GetPosY(int i, int j) { return bullet_[i][j].pos_.y; };
	bool GetIsShot(int i, int j) { return bullet_[i][j].isShot_; };
	void SetIsShot(bool isShot, int i, int j) { bullet_[i][j].isShot_ = isShot; };
	void SetPos(Vector2 pos, int i, int j) { bullet_[i][j].pos_ = pos; };
};

