#include "OL_Main.h"

/*
*   Filename: OL_Main.cpp
*   Date Modified: 25/02/2014 by Nathan Hanlan
*   Comments: v1.0.0 Initial Creation
*             - Implemented Main Class
              - Wrote entry point.
*/

int main()
{
    int mainRunCode = OnLooker::Main::getInstance()->run();
    OnLooker::Main::destroy();

    return mainRunCode;
}

namespace OnLooker
{
        Main * Main::s_Instance = 0;
        Main * Main::getInstance()
        {
            if(s_Instance == 0)
            {
                s_Instance = new Main();
            }

            return s_Instance;
        }

        void Main::destroy()
        {
            if(s_Instance != 0)
            {
                delete s_Instance;
                s_Instance = 0;
            }
        }

        Main::Main()
        {

        }
        Main::~Main()
        {

        }

        int Main::run()
        {
            //TODO: Write window Creation code here and loop
            if(Application::getInstance()->init() != true)
            {
                //Something went wrong
                return -1;
            }


            //Loop this


            Application::getInstance()->onIdle();


            Application::getInstance()->destroy();

            return 0;
        }
        

        

}