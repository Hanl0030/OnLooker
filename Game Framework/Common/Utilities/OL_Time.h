#ifndef OL_TIME_H
#define OL_TIME_H
/*
*   Filename: OL_Time.h
*   Date Modified: 02/03/2014 by Nathan Hanlan
*   Comments: v1.0.0 Added and Implemented class Time
*/


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
        //The last time
        static double m_LastTime;


        friend Main;
    };

};

#endif