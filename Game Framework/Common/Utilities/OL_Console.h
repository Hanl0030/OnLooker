#ifndef OL_CONSOLE_H
#define OL_CONSOLE_H

/*
*   Filename: OL_Console.h
*   Date Modified: 02/03/2014 by Nathan Hanlan
*   Comments: v1.0.0 Added and Implemented class Console
*/

namespace OnLooker
{
    /*
    *   Class: Console
    *   Base Class: N/A
    *   Description: creates a console if there is no console, allows easy
    *   debugging with output methods.
    *   Follows the singleton design pattern
    *   Date Modified: 02/03/2014 by Nathan Hanlan
    */
    class Console
    {
    public:
        /*
        *   Function: getInstance
        *   Return Type: Console
        *   Description: Singleton design accessor method
        *   Parameters: @parameter
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        static Console * getInstance();
        /*
        *   Function: destroy
        *   Return Type: void
        *   Description: Singleton design cleanup method
        *   Parameters: @parameter
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        static void destroy();

        /*
        *   Function: output
        *   Return Type: void
        *   Description: Takes in parameters in multiple formats and outputs them to console
        *   Parameters: @aMessage - The format to output
        *   @... The arguments to output
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        void output(const char * aMessage, ...);
        /*
        *   Function: output
        *   Return Type: void
        *   Description: Takes in parameters a integer and outputs it to console
        *   Parameters: @aValue - the value to output
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        void output(int aValue);
        /*
        *   Function: output
        *   Return Type: void
        *   Description: Takes in parameters a float and outputs it to console
        *   Parameters: @aValue - the value to output
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        void output(float aValue);
        /*
        *   Function: output
        *   Return Type: void
        *   Description: Takes in parameters a double and outputs it to console
        *   Parameters: @aValue - the value to output
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        void output(double aValue);

    private:
        /*
        *   Function: Console
        *   Return Type: constructor
        *   Description: Sets defaults
        *   Parameters: @parameters
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        Console();
        /*
        *   Function: Console
        *   Return Type: destructor
        *   Description: Destroys the console
        *   Parameters: @parameters
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        ~Console();

        /*
        *   Function: createConsole
        *   Return Type: void
        *   Description: creates a console to output to.
        *   Parameters: @parameters
        *   Date Modified: 02/03/2014 by Nathan Hanlan
        */
        void createConsole();
        static Console * s_Instance;
        bool m_IsConsoleAllocated;

    };

}

#endif