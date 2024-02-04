#include "Player.h"

Player::Player()
{
	player_ = { 640, 360, 5, 5, 16, 0, true, 0xFFFFFFFF, 3 };
	pBullet = new PBullet;
}

Player::~Player()
{
	delete pBullet;
}

void Player::UpData(char* keys)
{
	if (keys[DIK_W]) {
		player_.pos_.y -= player_.vel_.y;
	}
	if (keys[DIK_A]) {
		player_.pos_.x -= player_.vel_.x;
	}
	if (keys[DIK_S]) {
		player_.pos_.y += player_.vel_.y;
	}
	if (keys[DIK_D]) {
		player_.pos_.x += player_.vel_.x;
	}

	for (int i = 0; i < BULLET_NUM; i++) {
		if (keys[DIK_SPACE] && player_.interval_ < 0 && pBullet->GetIsShot(i) == false) {
			pBullet->SetIsShot(true, i);
			pBullet->SetPos(player_.pos_, i);
			player_.interval_ = 10;
		}
		
	}
	pBullet->UpData();
	player_.interval_ -= 1;
}

void Player::Draw()
{
	pBullet->Draw();
	Novice::DrawEllipse(int(player_.pos_.x), int(player_.pos_.y), int(player_.radius_), int(player_.radius_), 0.0f, player_.color_, kFillModeSolid);
}

void Player::Initialize()
{
	player_ = { 640, 360, 5, 5, 16, 0, true, 0xFFFFFFFF, 3 };
	pBullet->Initialize();
}
