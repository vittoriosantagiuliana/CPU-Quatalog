#include "mobile.h"

Mobile::Mobile(const int manufacturer, const std::string & model, const int socket, const int year, const int cores, const int threads, const int nm, const int w, const int bits)
{
    CPU(manufacturer, model, socket, year, cores, threads, nm, w, bits);
}
