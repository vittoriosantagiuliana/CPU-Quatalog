#ifndef MOBILE_H
#define MOBILE_H

#include "cpu.h"

class Mobile : public CPU
{
public:
    Mobile(int manufacturer, const std::string & model, int socket, int year, int cores, int threads, int nm, int w, bool bits);

    static const std::map<const int, const std::string> sockets;

};

#endif // MOBILE_H
