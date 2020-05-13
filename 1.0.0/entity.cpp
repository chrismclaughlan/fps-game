#include "entity.h"

#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

namespace GAME
{
	Entity::Entity()
	{
		this->x_pos = 0;
		this->y_pos = 0;
		this->z_pos = 5;
		this->x_ang = 0;
		this->z_ang = -1;
		this->speed = 0;
	}

	Entity::Entity(float xp, float yp, float zp, float xa, float za, float s)
	{
		this->x_pos = xp;
		this->y_pos = yp;
		this->z_pos = zp;
		this->x_ang = xa;
		this->z_ang = za;
		this->speed = s;
	}

	Entity::~Entity()
	{

	}

	void Entity::setXPos(float pos)
	{
		this->x_pos = pos;
	}

	void Entity::setYPos(float pos)
	{
		this->y_pos = pos;
	}

	void Entity::setZPos(float pos)
	{
		this->z_pos = pos;
	}

	void Entity::setSpeed(float s)
	{
		this->speed = s;
	}


	void Entity::setXAng(float ang)
	{
		this->x_ang = ang;
	}

	void Entity::setZAng(float ang)
	{
		this->z_ang = ang;
	}

	// Method
	void Entity::draw()
	{
		glPushMatrix();
		glTranslatef(this->x_pos, this->y_pos, this->z_pos);
		// TODO x_ang, y_ang, z_ang
		

		glColor3f(1.0f, 1.0f, 1.0f);

		// Draw Body
		glTranslatef(0.0f, 0.75f, 0.0f);
		glutSolidSphere(0.75f, 20, 20);

		// Draw Head
		glTranslatef(0.0f, 1.0f, 0.0f);
		glutSolidSphere(0.25f, 20, 20);

		// Draw Eyes
		glPushMatrix();
		glColor3f(0.0f, 0.0f, 0.0f);
		glTranslatef(0.05f, 0.10f, 0.18f);
		glutSolidSphere(0.05f, 10, 10);
		glTranslatef(-0.1f, 0.0f, 0.0f);
		glutSolidSphere(0.05f, 10, 10);
		glPopMatrix();

		// Draw Nose
		glColor3f(1.0f, 0.5f, 0.5f);
		glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
		glutSolidCone(0.08f, 0.5f, 10, 2);


		glPopMatrix();
	}
}