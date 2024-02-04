#include "PBullet.h"

PBullet::PBullet()
{
	for (int i = 0; i < BULLET_NUM; i++) {
		bullet_[i] = { -64, -64, 8, 8,false, 0xFFFFFFFF };
	}
}
	

PBullet::~PBullet()
{
}

void PBullet::Initialize()
{
	for (int i = 0; i < BULLET_NUM; i++) {
		bullet_[i] = { -64, -64, 8, 8,false, 0xFFFFFFFF };
	}
}

void PBullet::UpData()
{
	for (int i = 0; i < BULLET_NUM; i++) {
		if (bullet_[i].isShot_ == true) {
			bullet_[i].pos_.y -= bullet_[i].vel_;
			if (bullet_[i].pos_.y <= -bullet_[i].radius_) {
				bullet_[i].isShot_ = false;
			}
		}
	}
}

void PBullet::Draw()
{
	for (int i = 0; i < BULLET_NUM; i++) {
		if (bullet_[i].isShot_ == true) {
			Novice::DrawEllipse(int(bullet_[i].pos_.x), int(bullet_[i].pos_.y), int(bullet_[i].radius_), int(bullet_[i].radius_), 0.0f, bullet_[i].color_, kFillModeSolid);
		}
	}
}
