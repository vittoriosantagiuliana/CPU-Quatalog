#ifndef DESKTOP_H
#define DESKTOP_H

#include "cpu.h"

class Desktop : public CPU
{
public:
    Desktop(const int manufacturer, const std::string & model, const int socket, const int year, const int cores, const int threads, const int nm, const int w, const bool bits, const bool ecc);

    static const std::map<const int, const std::string> sockets;

};

#endif // DESKTOP_H
