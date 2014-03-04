#include "OL_Game.h"
#include "../Utilities/OL_Utilities.h"
#include "../Core/OL_Core.h"

namespace OnLooker
{
    Game::Game()
    {
		m_Color = new Color(Colors::indigo());

        m_Texture = Renderer::getInstance()->loadTexture("Bush.png");
		m_Shader = new Shader();
		m_Shader->loadShaderProgram("BasicShader");
		m_TextureShader = new Shader();
		m_TextureShader->loadShaderProgram("TextureShader");


		m_WaterTexture = new TextureReference();
		m_SandTexture = new TextureReference();

		m_WaterTexture->load("Water.png",1,true);
		m_SandTexture->load("Water.png",0,true);
		
		
		int numberOfAttributes = 4;
		VertexAttribute * attributes = new VertexAttribute[numberOfAttributes];


		//								Position (x,y)			Color(RGBA)			TexCoord(UV)
		attributes[0] = VertexAttribute(-0.9f , -0.9f,     1.0f, 1.0f ,1.0f, 0.5f,   0.0f, 0.0f);
		attributes[1] = VertexAttribute(0.9f , -0.9f,     1.0f, 1.0f ,1.0f, 0.5f,   1.0f, 0.0f);
		attributes[2] = VertexAttribute(0.9f , 0.9f,     1.0f, 1.0f ,1.0f, 0.5f,   1.0f, 1.0f);
		attributes[3] = VertexAttribute(-0.9f , 0.9f,     1.0f, 1.0f ,1.0f, 0.5f,   0.0f, 1.0f);
		
		GLushort indices[] = {0,1,3,1,2,3};


		glGenBuffers(1,&m_VBO);
		glGenBuffers(1,& m_IBO);

		glBindBuffer(GL_ARRAY_BUFFER,m_VBO);
		glBufferData(GL_ARRAY_BUFFER,sizeof(VertexAttribute)*numberOfAttributes,attributes,GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		
    }
    Game::~Game()
    {
        Renderer::getInstance()->unloadTexture("Bush.png");
		if(m_Shader != 0)
		{
			delete m_Shader;
			m_Shader = 0;
		}
    }

    void Game::update()
    {
		
    }
    void Game::render()
    {
		//Renderer::getInstance()->drawTexture(m_Texture,Input::getInstance()->getMouseX(),Input::getInstance()->getMouseY());
		
		
		//m_Shader->useThisShader();

		//Renderer::getInstance()->checkForErrors();
		//
		//glBindBuffer(GL_ARRAY_BUFFER,m_VBO);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_IBO);

		//GLint aPos = glGetAttribLocation(m_Shader->getShaderProgramHandle(),"a_Position");
		//GLint aColor = glGetAttribLocation(m_Shader->getShaderProgramHandle(), "a_Color");
		//GLint aTexCoords = glGetAttribLocation(m_Shader->getShaderProgramHandle(), "a_TexCoords");

		//glVertexAttribPointer(aPos,2,GL_FLOAT,GL_FALSE,sizeof(VertexAttribute),(void*)offsetof(VertexAttribute,position));
		//glEnableVertexAttribArray(aPos);
		//glVertexAttribPointer(aColor,4,GL_FLOAT,GL_FALSE,sizeof(VertexAttribute),(void*)offsetof(VertexAttribute,color));
		//glEnableVertexAttribArray(aColor);
		//
		////Attributes can be optimized out, meaning if they are not used opengl throws them away from the shader code.
		//if(aTexCoords != -1)
		//{
		//	glVertexAttribPointer(aTexCoords,2,GL_FLOAT,GL_FALSE,sizeof(VertexAttribute),(void*)offsetof(VertexAttribute,texCoords));
		//	glEnableVertexAttribArray(aTexCoords);
		//}


		//GLint uColor = glGetUniformLocation(m_Shader->getShaderProgramHandle(), "u_Tint");
		//if(m_Color != 0)
		//{
		//	glUniform3f(uColor,m_Color->red,m_Color->green,m_Color->blue);
		//}
		//	
		////@Parameter 2 - The number of indices
		//glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_SHORT,0);

		//glBindBuffer(GL_ARRAY_BUFFER,0);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
		Renderer::getInstance()->disableBlending();
		Renderer::getInstance()->checkForErrors();

		m_TextureShader->useThisShader();
		glBindBuffer(GL_ARRAY_BUFFER,m_VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_IBO);

		GLint aPos = glGetAttribLocation(m_TextureShader->getShaderProgramHandle(),"a_Position");
		GLint aColor = glGetAttribLocation(m_TextureShader->getShaderProgramHandle(), "a_Color");
		GLint aTexCoords = glGetAttribLocation(m_TextureShader->getShaderProgramHandle(), "a_TexCoords");

		if(aPos != -1)
		{
			glVertexAttribPointer(aPos,2,GL_FLOAT,GL_FALSE,sizeof(VertexAttribute),(void*)offsetof(VertexAttribute,position));
			glEnableVertexAttribArray(aPos);
		}
		if(aColor != -1)
		{
			glVertexAttribPointer(aColor,4,GL_FLOAT,GL_FALSE,sizeof(VertexAttribute),(void*)offsetof(VertexAttribute,color));
			glEnableVertexAttribArray(aColor);
		}
		
		//Attributes can be optimized out, meaning if they are not used opengl throws them away from the shader code.
		if(aTexCoords != -1)
		{
			glVertexAttribPointer(aTexCoords,2,GL_FLOAT,GL_FALSE,sizeof(VertexAttribute),(void*)offsetof(VertexAttribute,texCoords));
			glEnableVertexAttribArray(aTexCoords);
		}

		GLint aTexOne = glGetUniformLocation(m_TextureShader->getShaderProgramHandle(), "u_TexS1");
		//GLint aTexTwo = glGetUniformLocation(m_TextureShader->getShaderProgramHandle(), "u_TexS2");

		glActiveTexture(GL_TEXTURE0 + 0);
		glBindTexture(GL_TEXTURE_2D, m_SandTexture->m_Texture->getID());
		glUniform1f(aTexOne, 0);

		//glActiveTexture(GL_TEXTURE0 + 1);
		//glBindTexture(GL_TEXTURE_2D, m_WaterTexture->m_Texture->getID());
		//glUniform1f(aTexOne, 1);

		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_SHORT,0);
		
		glBindBuffer(GL_ARRAY_BUFFER,0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

    }
}