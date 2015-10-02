/**
 * Added by Judy
 * Aug 12, 2015
 */

#include "MusicSocket.h"
// #include "StatusCheck.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>


using namespace Robot;

int MusicSocket::mySocket = -1;
int MusicSocket::faceDetect = -1;

void MusicSocket::Connect()
{
    int portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    portno = atoi("8080");
    mySocket = socket(AF_INET, SOCK_STREAM, 0);
    if (mySocket < 0) {
       mySocket = -1;
       fprintf(stderr, "ERROR opening socket");
       exit(0);
    }
    server = gethostbyname("192.168.123.102");
    if (server == NULL){
        mySocket = -1;
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(mySocket,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0){
        faceDetect = -1;
        //LinuxActionScript::PlayMP3("../../../Data/mp3/Face detection disableed.mp3");
        fprintf(stderr, "ERROR connecting");
    }else{
        faceDetect = 1; 
    }

}

void MusicSocket::Close(){
   if (mySocket > 0){
       close(mySocket);
   }
}
