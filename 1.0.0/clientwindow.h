#pragma once

class ClientWindow
{
protected:
	char* title;
	int x_pos;
	int y_pos;
	int x_size;
	int y_size;

public:
	ClientWindow();
	ClientWindow(char*, int, int, int, int);
	~ClientWindow();

	// Setters
	void setTitle(char*);
	void setXPos(int pos);
	void setYPos(int pos);
	void setXSize(int size);
	void setYSize(int size);

	// Getters
	char* getTitle();
	int getXPos();
	int getYPos();
	int getXSize();
	int getYSize();

	// Methods
};