#include "Stage.h"

Stage::Stage()
{
	clearNum_ = 6;
	player = new Player;
	enemy = new Enemy;
}

Stage::~Stage()
{
	delete player;
	delete enemy;
}

void Stage::Initialize()
{
	clearNum_ = 6;
	player->Initialize();
	enemy->Initialize();
}

void Stage::UpData(char* keys)
{
	for (int Enemy = 0; Enemy < ENEMY_NUM; Enemy++) {
		if (sqrtf((player->GetPosX() - enemy->GetPosX(Enemy)) * (player->GetPosX() - enemy->GetPosX(Enemy)) + (player->GetPosY() - enemy->GetPosY(Enemy)) * (player->GetPosY() - enemy->GetPosY(Enemy))) <= 48) {
			player->SetHP(player->GetHP() - 1);
		}
		for (int EnemyBullet = 0; EnemyBullet < ENEMY_BULLET_NUM; EnemyBullet++) {
			if (enemy->eBullet->GetIsShot(Enemy, EnemyBullet)) {
				if (sqrtf((enemy->eBullet->GetPosX(Enemy, EnemyBullet) - player->GetPosX()) * (enemy->eBullet->GetPosX(Enemy, EnemyBullet) - player->GetPosX()) + (enemy->eBullet->GetPosY(Enemy, EnemyBullet) - player->GetPosY()) * (enemy->eBullet->GetPosY(Enemy, EnemyBullet) - player->GetPosY())) <= 32) {
					enemy->eBullet->SetPos({ -64, -64 }, Enemy, EnemyBullet);
					enemy->eBullet->SetIsShot(false, Enemy, EnemyBullet);
					player->SetHP(player->GetHP() - 1);
				}
			}
		}
		for (int PlayerBullet = 0; PlayerBullet < BULLET_NUM; PlayerBullet++) {
			if (enemy->GetAlive(Enemy)) {
				if (sqrtf((player->pBullet->GetPosX(PlayerBullet) - enemy->GetPosX(Enemy)) * (player->pBullet->GetPosX(PlayerBullet) - enemy->GetPosX(Enemy))) + (player->pBullet->GetPosY(PlayerBullet) - enemy->GetPosY(Enemy)) * (player->pBullet->GetPosY(PlayerBullet) - enemy->GetPosY(Enemy)) <= 40) {
					player->pBullet->SetPos({ -64, -64 }, PlayerBullet);
					enemy->SetAlive(false, Enemy);
					player->pBullet->SetIsShot(false, PlayerBullet);
					clearNum_ -= 1;
				}
			}
		}
	}
	player->UpData(keys);
	enemy->UpData();
}

void Stage::Draw()
{
	Novice::DrawBox(20, 20, player->GetHP() * 80, 30, 0.0f, 0xFFFF00FF, kFillModeSolid);
	Novice::DrawBox(240, 670, clearNum_ * 120, 30, 0.0f, 0xFF0000FF, kFillModeSolid);

	enemy->Draw();
	player->Draw();
}
