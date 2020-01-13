//
// Created by yuval on 13/01/2020.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H


//interface or abstract class

class ClientHandler
{
public:
    virtual void handleClient() = 0;   //handleClient(InputStream,OutputStream)
};




#endif //EX4_CLIENTHANDLER_H
