#include "player.h"

#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

namespace GAME
{
	Player::Player()
	{
		this->x_pos = 0;
		this->y_pos = 0;
		this->z_pos = 5;
		this->x_ang = 0;
		this->z_ang = -1;
		this->speed = 0;
	}

	Player::Player(float xp, float yp, float zp, float xa, float za, float s)
	{
		this->x_pos = xp;
		this->y_pos = yp;
		this->z_pos = zp;
		this->x_ang = xa;
		this->z_ang = za;
		this->speed = s;
	}

	Player::~Player()
	{

	}

	// Setters

	// Getters

	// Methods
	void Player::look()
	{
		gluLookAt(
			this->x_pos, 1.0f, this->z_pos,
			this->x_pos + this->x_ang, 1.0f, this->z_pos + this->z_ang,
			0.0f, 1.0f, 0.0f
			);
	}

	void Player::draw()
	{
		
	}

	void Player::computePos(float deltaMove)
	{
		this->x_pos += deltaMove * this->x_ang * 0.1f;
		this->z_pos += deltaMove * this->z_ang * 0.1f;
	}

	void Player::updateCamera(float deltaAngle, float angle)
	{
		this->x_ang = sin(angle + deltaAngle);
		this->z_ang = -cos(angle + deltaAngle);
	}
}