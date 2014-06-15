#include "OL_Object.h"

const char * OL_INDESTRUCTIBLE_OBJECT = "__INDESTRUCTIBLE_OBJECT__";

namespace OnLooker
{

	int Object::s_ReferenceID = 0;

	Object::Object()
	{
		m_ReferenceID = nextRefrenceID();
	}

	Object::~Object()
	{
        
	}


	Object * Object::destroy(Object * aObject)
	{ 
		if(aObject != 0)
		{
			if(aObject->getType() != OL_INDESTRUCTIBLE_OBJECT)
			{
				delete aObject;
				aObject = 0;
			}
		}
		return aObject;
	}

    std::string Object::toString()
    {
        return "";
    }

	char * Object::getName()
	{
		return m_Name;
	}
	void Object::setName(char * aName)
	{
		m_Name = aName;
	}
	int Object::getReferenceID()
	{
		return m_ReferenceID;
	}
	
	int Object::nextRefrenceID()
	{
		s_ReferenceID ++;
		return s_ReferenceID - 1;
	}
}