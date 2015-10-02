/*
 * Create a server socket that listens and accepts 
 * connection request from multiple client sockets.
 * 
 * Author: Ruimin Zhang
 * Date: July 15, 2015
 */

import java.net.*;
import java.io.*;
import org.opencv.core.Core;


public class Server{
    private ServerSocket serverSocket;
   
    // Constructor 
    public Server(int port) throws IOException{
        serverSocket = new ServerSocket(port);
    }
 
    // Create a server socket to listen for messages from client 
    public void run(){
       Socket clientSocket;
       try{
           while(true){
              System.out.println("Waiting for client on port " + 
                   serverSocket.getLocalPort() + "...");
              clientSocket = serverSocket.accept();
              System.out.println("Just connected to " + 
                   clientSocket.getRemoteSocketAddress().toString());
              // Create a new thread to handle each socket connection
              new Thread(new ClientInputProcessor(clientSocket)).start();
           }
       }catch(IOException e){
           e.printStackTrace();
           return;
       }
    }

    public static void main(String[] args){
        if (args.length < 1) {
           System.out.format("<Usage>:\njava [options] MusicServer portNumber\n");
           return;
        }
        int port = Integer.parseInt(args[0]);
       
        System.loadLibrary(Core.NATIVE_LIBRARY_NAME); // should be loaded only once
        
        try{
           Server s = new Server(port);
           s.run();
        }catch(IOException e){
           e.printStackTrace();
        }
    }
}
