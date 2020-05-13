#pragma once
#include "player.h"

namespace GAME
{
	// Input variables
	extern float deltaAngle;
	extern float deltaMove;
	extern float angle;
	extern int xOrigin;
	
	extern class Player* player;

	// Methods
	void run(int, char**);
	void changeSize(int, int);
	void drawEntities();
	void renderScene(void);
	void processNormalKeys(unsigned char, int, int);
	void pressKey(int, int, int);
	void releaseKey(int, int, int);
	void mouseMove(int, int);
	void mouseButton(int, int, int, int);

	void close();
}