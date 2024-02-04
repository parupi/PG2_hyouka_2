#include "Enemy.h"

Enemy::Enemy()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		enemy_[i] = { 600, float(120 + (80 * i)), float(4 - 8 * i), 0, 32, 30, true, 0xFF0000FF, 150 };
	}
	eBullet = new EBullet;
}

Enemy::~Enemy()
{
	delete eBullet;
}

void Enemy::Initialize()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		enemy_[i] = { 600, float(120 + (80 * i)), float(4 - 8 * i), 0, 32, 30, true, 0xFF0000FF, 150 };
	}
	eBullet->Initialize();
}

void Enemy::UpData()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (enemy_[i].isAlive_ == 1) {
			enemy_[i].pos_.x += enemy_[i].vel_.x;
			if (enemy_[i].pos_.x < 32 || enemy_[i].pos_.x > 1248) {
				enemy_[i].vel_.x *= -1;
			}
			enemy_[i].interval_ -= 1;
			for (int j = 0; j < ENEMY_BULLET_NUM; j++) {
				if (enemy_[i].interval_ < 0 && eBullet->GetIsShot(i, j) == false) {
					eBullet->SetIsShot(true, i, j);
					eBullet->SetPos(enemy_[i].pos_, i, j);
					enemy_[i].interval_ = 10;
				}
			}
		}
		else {
			enemy_[i].respawn_ -= 1;
			if (enemy_[i].respawn_ <= 0) {
				enemy_[i].isAlive_ = 1;
				enemy_[i].respawn_ = 150;
			}
		}
	}
	eBullet->UpData();
}

void Enemy::Draw()
{
	eBullet->Draw();
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (enemy_[i].isAlive_ == 1) {
			Novice::DrawEllipse(int(enemy_[i].pos_.x), int(enemy_[i].pos_.y), int(enemy_[i].radius_), int(enemy_[i].radius_), 0.0f, enemy_[i].color_, kFillModeSolid);
		}
	}
}
