#include "Game.h"

Game::Game()
{
	stage = new Stage;
	stage->Initialize();
	nowScene_ = Title;
}

Game::~Game()
{
	delete stage;
}

void Game::UpData(char* keys, char* preKeys)
{
	switch (nowScene_) {
	case Title:

		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			stage->Initialize();
			nowScene_ = GameScene;
		}

		break;
	case GameScene:

		stage->UpData(keys);
		if (stage->GetClearNum() <= 0) {
			nowScene_ = Clear;
		}
		else if (stage->player->GetHP() <= 0) {
			nowScene_ = GameOver;
		}

		break;
	case Clear:

		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			nowScene_ = Title;
		}

		break;
	case GameOver:

		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			nowScene_ = Title;
		}

		break;
	}
}

void Game::Draw()
{
	switch (nowScene_) {
	case Title:
		Novice::DrawSprite(0, 0, graphTitle, 1, 1, 0.0f, 0xFFFFFFFF);
		break;
	case GameScene:
		Novice::DrawSprite(0, 0, graphGameScene, 1, 1, 0.0f, 0xFFFFFFFF);
		stage->Draw();
		break;
	case Clear:
		Novice::DrawSprite(0, 0, graphClear, 1, 1, 0.0f, 0xFFFFFFFF);
		break;
	case GameOver:
		Novice::DrawSprite(0, 0, graphGameOver, 1, 1, 0.0f, 0xFFFFFFFF);
		break;
	}
}
