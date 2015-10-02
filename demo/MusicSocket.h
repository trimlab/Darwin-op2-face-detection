
#ifndef MUSICSOCKET_H_
#define MUSICSOCKET_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#include "StatusCheck.h"

namespace Robot{

   class MusicSocket{
   
       public:  
         static int mySocket;
         static int faceDetect;
   
       public:
         static void Connect();
         static void Close();
   };
   
}
#endif /* MUSICSOCKET_H_ */

