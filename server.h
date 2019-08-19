#ifndef SERVER_H
#define SERVER_H

#include "cpu.h"

class Server : public CPU
{
public:
    Server(const int manufacturer, const std::string & model, const int socket, const int year, const int cores, const int threads, const int nm, const int w, const bool bits, const bool ecc);
};

#endif // SERVER_H
