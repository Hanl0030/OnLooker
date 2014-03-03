#include "OL_Game.h"
#include "../Utilities/OL_Utilities.h"
#include "../Core/OL_Core.h"

namespace OnLooker
{
    Game::Game()
    {
        m_Texture = Renderer::getInstance()->loadTexture("Bush.png");
    }
    Game::~Game()
    {
        Renderer::getInstance()->unloadTexture("Bush.png");
    }

    void Game::update()
    {
        
    }
    void Game::render()
    {
        Renderer::getInstance()->drawTexture(m_Texture,32.0f,32.0f);
    }
}