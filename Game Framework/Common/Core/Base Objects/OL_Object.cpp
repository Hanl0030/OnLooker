#include "OL_Object.h"

namespace OnLooker
{
	Object::Object()
	{

	}

	Object::~Object()
	{

	}


	Object * Object::destroy(Object * aObject)
	{ 
		if(aObject != 0)
		{
			delete aObject;
			aObject = 0;
		}
		return aObject;
	}

    std::string Object::toString()
    {
        return "";
    }
}