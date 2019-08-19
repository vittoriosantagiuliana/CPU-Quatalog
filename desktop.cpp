#include "desktop.h"

Desktop::Desktop(const int manufacturer, const std::string & model, const int socket, const int year, const int cores, const int threads, const int nm, const int w, const bool bits, const bool ecc) : CPU(manufacturer, model, socket, year, cores, threads, nm, w, bits, ecc)
{
    //if (cores > 16)
    //    throw coresException(cores);
}