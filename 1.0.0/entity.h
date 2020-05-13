#pragma once

namespace GAME
{
	class Entity
	{
	protected:
		float x_pos;  //
		float y_pos;
		float z_pos;  //
		float x_ang;  //
		float z_ang;  //
		float speed;


	public:
		Entity();
		Entity(float, float, float, float, float, float);
		~Entity();

		// Setters
		void setXPos(float);
		void setYPos(float);
		void setZPos(float);
		void setXAng(float);
		void setZAng(float);
		void setSpeed(float);

		// Getters
		float getXPos() { return this->x_pos; };
		float getYPos() { return this->y_pos; };
		float getZPos() { return this->z_pos; };
		float getXAng() { return this->x_ang; };
		float getZAng() { return this->z_ang; };
		float getSpeed() { return this->speed; };

		// Methods
		void draw();
	};
}