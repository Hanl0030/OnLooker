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

        void update();
        void render();
    private:
        unsigned int m_Texture;

		unsigned int m_VBO;
		unsigned int m_IBO;
		Shader * m_Shader;
		Shader * m_TextureShader;

		Color * m_Color;

		TextureReference * m_WaterTexture;
		TextureReference * m_SandTexture;

		float m_Transparency;

    };


}

#endif