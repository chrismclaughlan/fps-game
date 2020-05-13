#include "clientwindow.h"

ClientWindow::ClientWindow()
{
	char t[] = "Client Window";
	this->title = t;
	this->x_pos = 100;
	this->y_pos = 100;
	this->x_size = 320;
	this->y_size = 320;
}

ClientWindow::ClientWindow(char* t, int xp, int yp, int xs, int ys)
{
	this->title = t;
	this->x_pos = xp;
	this->y_pos = yp;
	this->x_size = xs;
	this->y_size = ys;
}

ClientWindow::~ClientWindow()
{
}

// Setters
void ClientWindow::setTitle(char* t)
{
	this->title = t;
}

void ClientWindow::setXPos(int pos)
{
	this->x_pos = pos;
}

void ClientWindow::setYPos(int pos)
{
	this->y_pos = pos;
}

void ClientWindow::setXSize(int size)
{
	this->x_size = size;
}

void ClientWindow::setYSize(int size)
{
	this->y_size = size;
}

// Getters
char* ClientWindow::getTitle()
{
	return this->title;
}

int ClientWindow::getXPos()
{
	return this->x_pos;
}

int ClientWindow::getYPos()
{
	return this->y_pos;
}

int ClientWindow::getXSize()
{
	return this->x_size;
}

int ClientWindow::getYSize()
{
	return this->y_size;
}