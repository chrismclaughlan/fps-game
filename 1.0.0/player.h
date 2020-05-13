#pragma once
#include "entity.h"

namespace GAME
{
	class Player : public Entity
	{
	private:

	public:
		Player();
		Player(float, float, float, float, float, float);
		~Player();

		// Setters

		// Getters

		// Methods
		void look();
		void draw();

		void computePos(float);
		void updateCamera(float, float);
	};
}