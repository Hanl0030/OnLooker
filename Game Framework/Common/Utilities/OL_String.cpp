#include "OL_String.h"
#include "../OL_Common.h"

namespace OnLooker
{
    String::String(String & aString)
    {
        m_Length = 0;
        m_Characters = 0;
        setString(aString);
    }
    String::String(const char * aString)
    {
        m_Length = 0;
        m_Characters = 0;
        setString(aString);
    }
    String::String(char aCharacters[])
    {
        m_Length = 0;
        m_Characters = 0;
        setString(aCharacters);
    }
    String::String()
    {
        m_Length = 0;
        m_Characters = 0;
    }
    String::~String()
    {
        deallocString(m_Characters);
        m_Length = 0;
    }
    void String::set(const char * aString)
    {
        setString(aString);
    }
    void String::set(String & aString)
    {
        setString(aString);
    }
    void String::operator= (const char * rhs)
    {
        setString(rhs);
    }
    void String::operator= (String & rhs)
    {
        setString(rhs);
    }
    //int String::length()
    //{
    //    return getLength();
    //}
    //int String::calcLength()
    //{
    //    
    //}
    bool String::operator> (const char * rhs)
    {
        return m_Length > stringLength(rhs);
    }
    bool String::operator> (String & rhs)
    {
        return m_Length > stringLength(rhs);
    }
    bool String::operator> (int & rhs)
    {
        return m_Length > rhs;
    }
    bool String::operator< (const char * rhs)
    {
        return m_Length < stringLength(rhs);
    }
    bool String::operator< (String & rhs)
    {
        return m_Length < stringLength(rhs);
    }
    bool String::operator< (int & rhs)
    {
        return m_Length < rhs;
    }
    bool String::operator>= (const char * rhs)
    {
        return m_Length >= stringLength(rhs);
    }
    bool String::operator>= (String & rhs)
    {
        return m_Length >= stringLength(rhs);
    }
    bool String::operator>= (int & rhs)
    {
        return m_Length >= rhs;
    }
    bool String::operator<= (const char * rhs)
    {
        return m_Length <= stringLength(rhs);
    }
    bool String::operator<= (String & rhs)
    {
        return m_Length <= stringLength(rhs);
    }
    bool String::operator<= (int & rhs)
    {
        return m_Length <= rhs;
    }

    void String::append(String & aString)
    {
        appendString(aString.m_Characters);
    }
    void String::append(const char * aString)
    {
        appendString(aString);
    }
    String String::operator+ (String & rhs)
    {
        String result = (*this);
        result += rhs;
        return result;
    }
    void String::operator+= (String & rhs)
    {
        appendString(rhs);
    }
    String String::operator+ (const char * rhs)
    {
        String result = (*this);
        result +=rhs;
        return result;
    }
    void String::operator+= (const char * rhs)
    {
        appendString(rhs);
    }
    //Comparison
    bool String::equals(const char * aString)
    {
        return compareString(aString);
    }
    bool String::equals(String & aString)
    {
        return compareString(aString);
    }
    bool String::operator== (const char * rhs)
    {
        return compareString(rhs);
    }
    bool String::operator== (String & rhs)
    {
        return compareString(rhs);
    }
    bool String::operator!= (const char * rhs)
    {
        return !compareString(rhs);
    }
    bool String::operator!= (String & rhs)
    {
        return !compareString(rhs);
    }

    void String::subString(String & aSubString,int aEnd) //assume start as 0
    {
        return subString(aSubString,0,aEnd);
    }
    void String::subString(String & aSubString, int aBegin, int aEnd)
    {
        aSubString.allocBuffer(aEnd - aBegin + 1);
        int index = 0;
        for(int i = aBegin; i < aEnd; i++)
        {
            aSubString.unsafeInsert(index,(getCharacterAtIndex(i)));
            index ++;
        }
        aSubString.unsafeInsert(index,'\0');
        aSubString.m_Length = aEnd - aBegin;
    }

    //Getters
    //const char * String::c_str()
    //{
    //    
    //}
    char String::at(const int aIndex)
    {
        return getCharacterAtIndex(aIndex);
    }
    char String::operator[] (const int aIndex)
    {
        return getCharacterAtIndex(aIndex);
    }


    //NEW
    int String::getLength()
    {
        return m_Length;
    }
    char * String::getString()
    {
        return m_Characters;
    }
    char String::getCharacterAtIndex(int aIndex)
    {
        if(aIndex >= 0 && aIndex <= m_Length && m_Characters != 0)
        {
            return m_Characters[aIndex];
        }
        return '\0';
    }

    void String::setString(const char * aString)
    {
        int newSize = stringLength(aString);
        deallocString(m_Characters);
        m_Characters = allocString(newSize + 1); //+ 1 for null terminator
        m_Length = newSize;
        for(int i = 0; i < m_Length; i++)
        {
            m_Characters[i] = aString[i];
        }
        m_Characters[m_Length] = '\0';
    }
    void String::setString(String & aString)
    {
        int newSize = stringLength(aString);
        deallocString(m_Characters);
        m_Characters = allocString(newSize + 1);
        m_Length = newSize;
        for(int i = 0; i < m_Length; i++)
        {
            m_Characters[i] = aString[i];
        }
        m_Characters[m_Length] = '\0';
    }
    void String::appendChar(char aChar)
    {
        int bufferSize = 1 + m_Length;
        char * newString = allocString(bufferSize + 1);
        for(int i = 0; i < m_Length; i++)
        {
            newString[i] = m_Characters[i];
        }
        newString[m_Length] = aChar;
        deallocString(m_Characters);
        m_Characters = newString;
        m_Length = bufferSize;
        m_Characters[m_Length] = '\0';
    }
    void String::appendString(const char * aString)
    {
        int stringSize = stringLength(aString);
        int bufferSize = stringSize + m_Length;
        char * newString = allocString(bufferSize + 1);
        for(int i = 0; i < m_Length; i++)
        {
            newString[i] = m_Characters[i];
        }
        for(int i = 0; i < stringSize; i++)
        {
            newString[i + m_Length] = aString[i];
        }
        deallocString(m_Characters);
        m_Characters = newString;
        m_Length = bufferSize;
        m_Characters[m_Length] = '\0';
    }
    void String::appendString(String & aString)
    {
        int stringSize = stringLength(aString);
        int bufferSize = stringSize + m_Length;
        char * newString = allocString(bufferSize + 1);
        for(int i = 0; i < m_Length; i++)
        {
            newString[i] = m_Characters[i];
        }
        for(int i = 0; i < stringSize; i++)
        {
            newString[i + m_Length] = aString[i];
        }
        deallocString(m_Characters);
        m_Characters = newString;
        m_Length = bufferSize;
        m_Characters[m_Length] = '\0';
    }

    bool String::compareString(const char * aString)
    {
        int length = stringLength(aString);
        for(int i = 0; i < m_Length && i < length; i++)
        {
            if(m_Characters[i] != aString[i])
            {
                return false;
            }
        }
        return true;
    }
    bool String::compareString(String & aString)
    {
        return compareString(aString.getString());
    }

    int String::stringLength(const char * aString)
    {
        bool foundNull = false;
        int index = 0;
        //While there hasnt been a null terminator
        while(!foundNull)
        {
            if(aString[index] == '\0')
            {
                break;
            }
            index ++;
        }
        return index;
    }
    int String::stringLength(String & aString)
    {
        char * characters = aString.getString();

        int index = 0;
        //While there hasnt been a null terminator or reach end of string length
        while(index < aString.getLength())
        {
            if(characters[index] == '\0')
            {
                break;
            }
            index ++;
        }
        return index;
    }
    void String::resize(int newSize)
    {
        if(m_Characters != 0)
        {
            delete[] m_Characters;
            m_Characters = 0;
        }
            
        if(m_Characters == 0)
        {
            m_Characters = new char [newSize];
            m_Length = newSize;
        }
    }
    char * String::allocString(int aSize)
    {
        if(aSize == 0)
        {
            return 0;
        }
        //return new char[aSize];
        return Memory::instantiate<char>(aSize);
    }
    void String::deallocString(char * aString)
    {
        if(aString != 0)
        {
            delete[] aString;
            aString = 0;
        }
    }
    void String::allocBuffer(int aSize)
    {
        deallocString(m_Characters);
        m_Characters = allocString(aSize);
    }
    void String::unsafeInsert(int aLocation, char aCharacter)
    {
        if(m_Characters != 0)
        {
            m_Characters[aLocation] = aCharacter;
        }
    }

    PoolAllocator * String::m_Allocator = nullptr;
    void * String::m_Memory = nullptr;

    void String::init()
    {

    }
    void String::cleanUp()
    {

    }
}