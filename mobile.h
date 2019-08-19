#ifndef MOBILE_H
#define MOBILE_H

#include "cpu.h"

class Mobile : public CPU
{
public:
    Mobile(const int manufacturer, const std::string & model, const int socket, const int year, const int cores, const int threads, const int nm, const int w, const bool bits, const bool ecc);
};

#endif // MOBILE_H
