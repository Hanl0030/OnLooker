#ifndef OL_GAME_H
#define OL_GAME_H

namespace OnLooker
{
	class Shader;
	class Color;
	class TextureReference;

    class Game
    {
    public:
        Game();
        ~Game();
		void load();
        void update();
        void render();
    private:

		unsigned int m_VBO;
		unsigned int m_IBO;
		Shader * m_Shader;
		Shader * m_TextureShader;

		Color * m_Color;

		TextureReference * m_Texture[2];

		float m_Transparency;

		long double m_Counter;

    };


}

#endif