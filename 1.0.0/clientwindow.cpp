#include "clientwindow.h"
#include "game.h"

ClientWindow::ClientWindow()
{
}

ClientWindow::~ClientWindow()
{
}

// Methods
void ClientWindow::runGame(int argc, char** argv)
{
	using namespace GAME;
	run(argc, argv);
	close();
}