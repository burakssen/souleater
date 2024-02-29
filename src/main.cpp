#include <iostream>

#include "Game/Game.h"

int main()
{

    try
    {
        Game &game = Game::GetInstance();
        game.Run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}