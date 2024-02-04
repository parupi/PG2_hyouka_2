#pragma once
#include "Stage.h"
class Game
{
private:
	enum SCENE {
		Title,
		GameScene,
		Clear,
		GameOver,
	};
	int nowScene_;

	int graphTitle = Novice::LoadTexture("./Resources/Title.png");
	int graphClear = Novice::LoadTexture("./Resources/Clear.png");
	int graphGameOver = Novice::LoadTexture("./Resources/GameOver.png");
	int graphGameScene = Novice::LoadTexture("./Resources/GameScene.png");
public:
	void UpData(char* keys, char* preKeys);
	void Draw();
	Game();
	~Game();

	Stage* stage;
};

