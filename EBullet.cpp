#include "EBullet.h"

EBullet::EBullet()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		for (int j = 0; j < ENEMY_BULLET_NUM; j++) {
			bullet_[i][j] = { -64, -64, 6, 16,false, 0xFF0000FF };
		}
	}
}

EBullet::~EBullet()
{
}

void EBullet::Initialize()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		for (int j = 0; j < ENEMY_BULLET_NUM; j++) {
			bullet_[i][j] = { -64, -64, 6, 16,false, 0xFF0000FF };
		}
	}
}

void EBullet::UpData()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		for (int j = 0; j < ENEMY_BULLET_NUM; j++) {
			if (bullet_[i][j].isShot_ == true) {
				bullet_[i][j].pos_.y += bullet_[i][j].vel_;
				if (bullet_[i][j].pos_.y >= 800) {
					bullet_[i][j].isShot_ = false;
				}
			}
		}
	}
}

void EBullet::Draw()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		for (int j = 0; j < ENEMY_BULLET_NUM; j++) {
			if (bullet_[i][j].isShot_ == true) {
				Novice::DrawEllipse(int(bullet_[i][j].pos_.x), int(bullet_[i][j].pos_.y), int(bullet_[i][j].radius_), int(bullet_[i][j].radius_), 0.0f, bullet_[i][j].color_, kFillModeSolid);
			}
		}
	}
}
