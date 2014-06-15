#ifndef OL_OBJECT_H
#define OL_OBJECT_H

#include <string>

//Any class that is not to be deallocated via Object::Destroy must return a type of __INDESTRUCTIBLE_OBJECT__
//This is maining for classes that are singleton design or managers of some sort.
extern const char * OL_INDESTRUCTIBLE_OBJECT;


namespace OnLooker
{
	/*
	*   Class: Object
	*   Base Class: None
	*   Description: Object is the base class for all OnLooker Objects
	*   Date Modified: 18/3/2014 by Nathan Hanlan
	*/
	class Object
	{
	public:
		/*
		*   Function: Object
		*   Return Type: Constructor
		*   Description: This is the default constructor for class Object
		*   Parameters: None
		*   Date Modified: 18/3/2014 by Nathan Hanlan
		*/
		Object();
		/*
		*   Function: Object
		*   Return Type: Destructor
		*   Description: This is the destructor for class Object
		*   Parameters: None
		*   Date Modified: 18/3/2014 by Nathan Hanlan
		*/
		virtual ~Object();

		/*
		*   Function: getType
		*   Return Type: const char *
		*   Description: This function is to be overridden by any class that inherits Object
		*	and is to return their class name in const char * format.
		*   Parameters: None
		*   Date Modified: 18/3/2014 by Nathan Hanlan
		*/
		virtual const char * getType() = 0;

        /*
        *   Function: toString
		*   Return Type: std::string
		*   Description: This function is to be overridden by any class that inherits Object
		*	and is to return a properly formatted string of the object's data
		*   Parameters: None
		*   Date Modified: 18/3/2014 by Nathan Hanlan
        */
        virtual std::string toString();

		/*
		*   Function: destroy
		*   Return Type: Object
		*   Description: This function destroys an object at run time by calling the delete operator
		*	on it if the object was not null (0). The function then returns the object handle back which should be 0.
		*   Parameters: Object * aObject - The object that is to be deleted.
		*   Date Modified: 18/3/2014 by Nathan Hanlan
		*/
		static Object * destroy(Object * aObject);

		/*
		*   Function: getName
		*   Return Type: char *
		*   Description: Returns the name of the object
		*   Parameters: none
		*   Date Modified: 1/4/2014 by Nathan Hanlan
		*/
		char * getName();
		/*
		*   Function: setName
		*   Return Type: void
		*   Description: Returns the name of the object
		*   Parameters: @char * aName - The name value to set
		*   Date Modified: 1/4/2014 by Nathan Hanlan
		*/
		void setName(char * aName);
	protected:
		char * m_Name;
		int getReferenceID();
	private:
		static int nextRefrenceID();
		static int s_ReferenceID;
		int m_ReferenceID;
	};
}

#endif