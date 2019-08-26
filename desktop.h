#ifndef DESKTOP_H
#define DESKTOP_H

#include "cpu.h"
#include "exceptions.h"

class Desktop : public CPU
{
public:
    Desktop(const int manufacturer, const std::string &model, const int socket, const int year, const int cores, const int threads, const int nm, const int w, const bool bits, const bool ecc);
    virtual Desktop *clone() const override;

    void setEccMemorySupport(const bool) override;
    virtual const std::string &getSocket() const override;
    virtual void setSocket(const int) override;
    virtual void setCoreCount(const int) override;
    virtual void setTdpRating(const int) override;

    static const int maxCores;
    static const int maxTdp;

    static const std::map<const int, const std::string> sockets;
};

#endif // DESKTOP_H
