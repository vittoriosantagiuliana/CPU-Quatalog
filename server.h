#ifndef SERVER_H
#define SERVER_H

#include "cpu.h"
#include "exceptions.h"

class Server : public CPU
{
private:
    void setEccMemorySupport(const bool) override;

public:
    Server(int manufacturer, const std::string &model, int socket, int year, int cores, int threads, int nm, int w, bool bits);
    virtual Server *clone() const override;

    virtual const std::string &getSocket() const override;
    virtual void setSocket(const int) override;
    virtual void setCoreCount(const int) override;
    virtual void setTdpRating(const int) override;

    static const int maxCores;
    static const int maxTdp;

    static const std::map<const int, const std::string> sockets;
};

#endif // SERVER_H
