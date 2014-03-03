#ifndef OL_GAME_H
#define OL_GAME_H

namespace OnLooker
{

    class Game
    {
    public:
        Game();
        ~Game();

        void update();
        void render();
    private:
        unsigned int m_Texture;
    };


}

#endif