#include "game.h"
#include "player.h"

#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

namespace GAME
{
	// Input variables
	float deltaAngle = 0.0;
	float deltaMove = 0.0;
	float angle = 0.0;
	int xOrigin = -1;

	Player* player = new Player();

	void run(int argc, char** argv)
	{
		// register callbacks
		glutDisplayFunc(renderScene);
		glutReshapeFunc(changeSize);
		glutIdleFunc(renderScene);
	
		glutIgnoreKeyRepeat(1);
		glutKeyboardFunc(processNormalKeys);
		glutSpecialFunc(pressKey);
		glutSpecialUpFunc(releaseKey);
	
		// here are the two new functions
		glutMouseFunc(mouseButton);
		glutMotionFunc(mouseMove);
	
		// OpenGL init
		glEnable(GL_DEPTH_TEST);
	
		// enter GLUT event processing cycle
		glutMainLoop();
	}

	void changeSize(int w, int h)
	{
		// Prevent a divide by zero, when window is too short
		// (you cant make a window of zero width).
		if (h == 0)
		{
			h = 1;
		}

		float ratio = w * 1.0 / h;

		// Use the Projection Matrix
		glMatrixMode(GL_PROJECTION);

		// Reset Matrix
		glLoadIdentity();

		// Set the viewport to be the entire window
		glViewport(0, 0, w, h);

		// Set the correct perspective.
		gluPerspective(45.0f, ratio, 0.1f, 100.0f);

		// Get Back to the Modelview
		glMatrixMode(GL_MODELVIEW);
	}

	void drawEntities()
	{
		//player->draw();

		// Draw entities
		for (int i = -3; i < 3; i++)
		{
			for (int j = -3; j < 3; j++)
			{
				Entity e(i* 10.0, 0, j * 10.0, 0, -1, 0);
				e.draw();
			}
		}
	}

	void renderScene(void)
	{
		if (deltaMove)
		{
			player->computePos(deltaMove);
		}

		// Clear Color and Depth Buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Reset transformations
		glLoadIdentity();

		// Set the camera
		player->look();

		// Draw ground
		glColor3f(0.9f, 0.9f, 0.9f);
		glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f, 100.0f);
		glVertex3f(100.0f, 0.0f, 100.0f);
		glVertex3f(100.0f, 0.0f, -100.0f);
		glEnd();

		// Draw entities
		drawEntities();

		glutSwapBuffers();
	}

	void processNormalKeys(unsigned char key, int xx, int yy)
	{
		if (key == 27)
			close();
	}

	void pressKey(int key, int xx, int yy)
	{
		switch (key)
		{
			case GLUT_KEY_UP:
				deltaMove = 0.5f;
				break;
			case GLUT_KEY_DOWN:
				deltaMove = -0.5f;
				break;
		}
	}

	void releaseKey(int key, int x, int y)
	{
		switch (key)
		{
			case GLUT_KEY_UP:

			case GLUT_KEY_DOWN:
				deltaMove = 0;
				break;
		}
	}

	void mouseMove(int x, int y)
	{
		// this will only be true when the left button is down
		if (xOrigin >= 0)
		{
			// update camera's direction
			deltaAngle = (x - xOrigin) * 0.001f;
			player->updateCamera(deltaAngle, angle);
		}
	}

	void mouseButton(int button, int state, int x, int y)
	{
		// only start motion if the left button is pressed
		if (button == GLUT_LEFT_BUTTON)
		{
			// when the button is released
			if (state == GLUT_UP)
			{
				angle += deltaAngle;
				xOrigin = -1;
			}
			else  // state = GLUT_DOWN
			{
				xOrigin = x;
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////

	void close()
	{
		delete player;
		exit(0);
	}

}  // namespace GAME