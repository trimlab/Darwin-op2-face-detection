/*
 * StatusCheck.h
 *
 *  Created on: 2011. 1. 21.
 *      Author: zerom
 */

#ifndef STATUSCHECK_H_
#define STATUSCHECK_H_

#include <sys/time.h>
#include "CM730.h"



namespace Robot
{
    enum {
        INITIAL,
        READY,
        SOCCER,
        MOTION,
        VISION,
        FACE, // added by Judy
        MAX_MODE
    };

    enum {
    	SOCCER_PLAY,
		SOCCER_REST
    };

    // added by Judy
    enum {
        FACE_DETECT,
        FACE_REST
    };
    /**** end ****/

    enum {
        BTN_MODE = 1,
        BTN_START = 2
    };


    class StatusCheck {
    private:
        static int m_old_btn;
        static int m_chicago_mode_cnt;

    public:
        static int m_cur_mode;
        static int m_is_started;

        static int 	    m_soccer_sub_mode;
        static double   m_soccer_start_time;

        // added by Judy
        static int      m_face_sub_mode;  
        static double   m_face_start_time;
        /***** end *****/

        static void Check(CM730 &cm730);
    };

//    class MusicSocket {
//      public:
//         static int mySocket;
//         static int faceDetect;
//   
//         static void Connect();
//         static void Close();
//    }; 
 
}

#endif /* STATUSCHECK_H_ */
