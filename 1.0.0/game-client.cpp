#include "gamewindow.h"
#include "types.h"

int main(int argc, char** argv)
{
	char t[] = "fps-game-test";
	GameWindow GW(t, 100, 100, 800, 600);
	GW.run(argc, argv);

	return EXIT_SUCCESS;
}