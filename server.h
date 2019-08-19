#ifndef SERVER_H
#define SERVER_H

#include "cpu.h"

class Server : public CPU
{
public:
    Server(const int manufacturer, const std::string & model, const int socket, const int year, const int cores, const int threads, const int nm, const int w, const bool bits, const bool ecc);

    static const std::map<const int, const std::string> sockets;

};

#endif // SERVER_H
