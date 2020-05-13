#pragma once
#include "clientwindow.h"

class GameWindow : public ClientWindow
{
private:

public:
	GameWindow();
	GameWindow(char*, int, int, int, int);
	~GameWindow();

	// Setters

	// Getters

	// Methods
	void run(int, char**);
};