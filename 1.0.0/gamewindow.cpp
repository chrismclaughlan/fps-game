#include "gamewindow.h"
#include "game.h"

#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

GameWindow::GameWindow()
{
	char t[] = "FPS Game";
	this->title = t;
	this->x_pos = 100;
	this->y_pos = 100;
	this->x_size = 320;
	this->y_size = 320;
}

GameWindow::GameWindow(char* t, int xp, int yp, int xs, int ys)
{
	this->title = t;
	this->x_pos = xp;
	this->y_pos = yp;
	this->x_size = xs;
	this->y_size = ys;
}

GameWindow::~GameWindow()
{

}

// Methods
void GameWindow::run(int argc, char** argv)
{
	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(this->x_pos, this->y_pos);
	glutInitWindowSize(this->x_size, this->y_size);
	glutCreateWindow(this->title);

	using namespace GAME;
	GAME::run(argc, argv);
	GAME::close();
}