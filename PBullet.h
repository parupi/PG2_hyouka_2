#pragma once
#include "Novice.h"
#include "Function.h"
class PBullet
{
private:
	Bullet bullet_[BULLET_NUM];
public:
	PBullet();
	~PBullet();
	void Initialize();
	void UpData();
	void Draw();

	bool GetIsShot(int i) { return bullet_[i].isShot_; };
	float GetPosX(int i) { return bullet_[i].pos_.x; };
	float GetPosY(int i) { return bullet_[i].pos_.y; };
	void SetIsShot(bool isShot, int i) { bullet_[i].isShot_ = isShot; };
	void SetPos(Vector2 pos, int i) { bullet_[i].pos_ = pos; };
};

