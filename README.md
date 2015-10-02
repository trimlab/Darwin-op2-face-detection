# Darwin-op2-face-detection

Brief introduction to the project
This project aims to create a sonification platform that generates music based on interations of individual robots with people. The project includes two parts of code: 1) demo, which modifies the original built-in demo of Darwin-op2 by adding a new FACE-DETECTION mode and a TCP/IP connection to the music server. We load it as the default program to be executed whenever Darwin-op2 is turned on or restart; 2) the music server, which receives images seen by Darwin-op2 and tries to detect any face or facial expression in the images. The detection results are sent back to Darwin-op2 who decides its interaction movement next.    



How to use code?
1. Connect your computer with Darwin-op2 
2. Use "scp -r demo robotis@192.168.123.1:~/../../robotis/Linux/project/" to replace the original built-in demo program with our demo program
3. Open eclipse in your computer and import musicServer program into your eclipse
4. Run music server first and then restart Darwin-op2
5. Now you should be able to use the left most button at the back of Darwin-op2 to toogle between READY, INTERACTIVE, VISION, SOCCER, FACE modes.
6. Select the FACE mode and press the second button from the left to start face detection 
