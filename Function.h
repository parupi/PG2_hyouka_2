#pragma once
#define BULLET_NUM (10)
#define ENEMY_NUM (2)
#define ENEMY_BULLET_NUM (3)

struct Vector2 final {
	float x;
	float y;
};

struct Vector2int final {
	int x;
	int y;
};


struct Bullet final {
	Vector2 pos_;
	float vel_;
	float radius_;
	bool isShot_;
	unsigned int color_;
};

struct PlayerStates final {
	Vector2 pos_;
	Vector2 vel_;
	float radius_;
	int interval_;
	bool isAlive_;
	unsigned int color_;
	int hp_;
};

struct EnemyStates final {
	Vector2 pos_;
	Vector2 vel_;
	float radius_;
	int interval_;
	bool isAlive_;
	unsigned int color_;
	int respawn_;
};