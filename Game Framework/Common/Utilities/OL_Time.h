#ifndef OL_TIME_H
#define OL_TIME_H

namespace OnLooker
{
    class Main;
    /*
    *   Class: Time
    *   Base Class: N/A
    *   Description: Holds static data for the applications delta time
    *   Date Modified: 02/03/2014 by Nathan Hanlan
    */

    class Time
    {
    public:
        //The time between frames
        static double m_Delta;


    private:
        //The current time
        static double m_CurrentTime;
        static double m_LastTime;


        friend Main;
    };

};

#endif