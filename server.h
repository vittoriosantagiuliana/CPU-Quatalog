#ifndef SERVER_H
#define SERVER_H

#include "cpu.h"

class Server : public CPU
{
public:
    Server(int manufacturer, const std::string & model, int socket, int year, int cores, int threads, int nm, int w, bool bits);

    static const std::map<const int, const std::string> sockets;

};

#endif // SERVER_H
