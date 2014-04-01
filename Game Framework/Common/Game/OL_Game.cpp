#include "OL_Game.h"
#include "../Utilities/OL_Utilities.h"
#include "../Core/OL_Core.h"
#include <math.h>

namespace OnLooker
{
    Game::Game()
    {
		m_Counter = 0.0;
		onLookerInit();
    }
    Game::~Game()
    {
        Renderer::getInstance()->unloadTexture("Bush.png");
    }

	void Game::load()
	{
		m_TextureHandles[0] =  Renderer::getInstance()->loadTexture("awesome.png");
		m_TextureHandles[1] =  Renderer::getInstance()->loadTexture("testMap.png");
		m_Color = new Color(Colors::indigo());

		m_Shader = new Shader();
		m_Shader->loadShaderProgram("BasicShader");
	
		m_TextureShader = new Shader();
		m_TextureShader->loadShaderProgram("TextureShader");
		m_TextureShader->useThisShader();

		//m_MaskShader = new Shader();
		//m_MaskShader->loadShaderProgram("TextureMask");
		//m_MaskShader->useThisShader();

		m_Texture[0] = new TextureReference();
		m_Texture[1] = new TextureReference();

		m_Texture[0]->load("testMap.png",0,true);
		m_Texture[1]->load("awesome.png",1,true);
		
		
		int numberOfAttributes = 4;
		VertexAttribute * attributes = new VertexAttribute[numberOfAttributes];


		//								Position (x,y)			Color(RGBA)			TexCoord(UV)
		attributes[0] = VertexAttribute(-0.9f , -0.9f,     1.0f, 1.0f ,1.0f, 0.5f,   1.0f, 1.0f); //top left
		attributes[1] = VertexAttribute(0.9f , -0.9f,     1.0f, 1.0f ,1.0f, 0.5f,   0.0f, 1.0f); //top right
		attributes[2] = VertexAttribute(0.9f , 0.9f,     1.0f, 1.0f ,1.0f, 0.5f,   0.0f, 0.0f); //bottom right
		attributes[3] = VertexAttribute(-0.9f , 0.9f,     1.0f, 1.0f ,1.0f, 0.5f,   1.0f, 0.0f); //bottom left
		
		GLushort indices[] = {0,1,3,1,2,3};


		glGenBuffers(1,&m_VBO);
		glGenBuffers(1,& m_IBO);

		glBindBuffer(GL_ARRAY_BUFFER,m_VBO);
		glBufferData(GL_ARRAY_BUFFER,sizeof(VertexAttribute)*numberOfAttributes,attributes,GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


		GLint aTexOne = glGetUniformLocation(m_TextureShader->getShaderProgramHandle(), "u_Texture1");
		glUniform1i(aTexOne, 0);

		GLint aTexTwo = glGetUniformLocation(m_TextureShader->getShaderProgramHandle(), "u_Texture2");
		glUniform1i(aTexTwo, 1);
		

		Renderer::getInstance()->checkForErrors();
	}

    void Game::update()
    {

		//Debug::console->output((double)sin(m_Counter));
		//Debug::console->output((double)m_Counter);
		//m_Counter += genRandomNumber(0,25,6);


		if(Input::getInstance()->getKey(KeyCode::F1))
		{
			m_Transparency += 0.05f;
			if(m_Transparency > 1.0f)
			{
				m_Transparency = 1.0f;
			}
		}
		else if(Input::getInstance()->getKey(KeyCode::F2))
		{
			m_Transparency -= 0.05f;
			if(m_Transparency < 0.0f)
			{
				m_Transparency = 0.0f;
			}
			//Debug::console->output(Time::m_Delta);
			//Debug::console->output(m_Transparency);
		}
		else if(Input::getInstance()->getKey(KeyCode::K))
		{

			//glGetUniformLocation(2,"someName");
			//glUniform1f(2,30);

			//unsigned int handleToMeshLocation = Renderer::getInstance()->getMesh("somemesh.obj");
			//Renderer::getInstance()->setMeshValue(handleToMeshLocation,30);
			//Renderer::getInstance()->setMeshValue(1,2);
		}

    }
    void Game::render()
    {
		//Renderer::getInstance()->drawTexture(m_TextureHandles[1],100.0f,200.0f,100.0f,100.0f);
		//Renderer::getInstance()->drawTexture(m_TextureHandles[0],100.0f,200.0f,100.0f,100.0f);
		
		
		/*m_Shader->useThisShader();

		Renderer::getInstance()->checkForErrors();
		
		glBindBuffer(GL_ARRAY_BUFFER,m_VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_IBO);

		GLint aPos = glGetAttribLocation(m_Shader->getShaderProgramHandle(),"a_Position");
		GLint aColor = glGetAttribLocation(m_Shader->getShaderProgramHandle(), "a_Color");
		GLint aTexCoords = glGetAttribLocation(m_Shader->getShaderProgramHandle(), "a_TexCoords");

		glVertexAttribPointer(aPos,2,GL_FLOAT,GL_FALSE,sizeof(VertexAttribute),(void*)offsetof(VertexAttribute,position));
		glEnableVertexAttribArray(aPos);
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


		GLint uColor = glGetUniformLocation(m_Shader->getShaderProgramHandle(), "u_Tint");
		if(uColor != -1 && m_Color != 0)
		{
			glUniform3f(uColor,m_Color->red,m_Color->green,m_Color->blue);
		}
			
		//@Parameter 2 - The number of indices
		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_SHORT,0);

		glBindBuffer(GL_ARRAY_BUFFER,0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);*/
		//Renderer::getInstance()->enableBlending(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
		Renderer::getInstance()->checkForErrors();

		//m_MaskShader->useThisShader();
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
		Renderer::getInstance()->checkForErrors();


		GLint u_TexOffset = glGetUniformLocation(m_TextureShader->getShaderProgramHandle(),"u_TexOffset");
		glUniform2f(u_TexOffset,0.0f,0.0f);
		

		glActiveTexture(GL_TEXTURE0 + 0);
		glBindTexture(GL_TEXTURE_2D, m_Texture[0]->m_Texture->getID());
									 

		glActiveTexture(GL_TEXTURE0 + 1);
		glBindTexture(GL_TEXTURE_2D, m_Texture[1]->m_Texture->getID());

		
		Renderer::getInstance()->checkForErrors();
		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_SHORT,0);
		Renderer::getInstance()->checkForErrors();
		glBindBuffer(GL_ARRAY_BUFFER,0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

    }
    const char * Game::getType()
    {
        return OL_INDESTRUCTIBLE_OBJECT;
    }

}