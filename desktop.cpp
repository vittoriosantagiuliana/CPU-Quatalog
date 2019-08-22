#include "desktop.h"

Desktop::Desktop(const int manufacturer, const std::string & model, const int socket, const int year, const int cores, const int threads, const int nm, const int w, const bool bits, const bool ecc) : CPU(manufacturer, model, socket, year, cores, threads, nm, w, bits, ecc)
{
    //if (cores > 16)
    //    throw CoresException(cores);
}

Desktop * Desktop::clone() const { return new Desktop (*this);}

void Desktop::setEccMemorySupport(const bool i) {
    eccMemorySupport = i;
}

const std::string & Desktop::getSocket() const {
    return sockets.at(socket);
}

void Desktop::setSocket(const int i) {
    if (sockets.find(i) != sockets.end())
        socket = i;
    else
        throw SocketException("desktop");
}

void Desktop::setCoreCount(const int i) {
    if (i < maxCores)
        coreCount = i;
    else
        throw CoresException(std::to_string(i));
}

void Desktop::setTdpRating(const int i) {
    if (i < maxTdp)
        TDP = i;
    else
        throw TDPException(std::to_string(i));
}


const int Desktop::maxCores(16);

const int Desktop::maxTdp(500);

const std::map<const int, const std::string> Desktop::sockets({
    std::pair<const int, const std::string>(0, "Socket 1"),
    std::pair<const int, const std::string>(1, "Socket 2"),
    std::pair<const int, const std::string>(2, "Socket 3"),
    std::pair<const int, const std::string>(3, "Socket 4"),
    std::pair<const int, const std::string>(4, "Socket 5"),
    std::pair<const int, const std::string>(5, "Socket 6"),
    std::pair<const int, const std::string>(6, "Socket 7"),
    std::pair<const int, const std::string>(7, "Socket Super 7"),
    std::pair<const int, const std::string>(8, "Slot 1(SC242"),
    std::pair<const int, const std::string>(9, "Socket 370"),
    std::pair<const int, const std::string>(10, "Socket 423"),
    std::pair<const int, const std::string>(11, "Socket 463"),
    std::pair<const int, const std::string>(12, "Socket 478"),
    std::pair<const int, const std::string>(13, "LGA775 (Socket T)"),
    std::pair<const int, const std::string>(14, "LGA1155 (Socket H2)"),
    std::pair<const int, const std::string>(15, "LGA1156 (Socket H1)"),
    std::pair<const int, const std::string>(16, "LGA1366 (Socket B)"),
    std::pair<const int, const std::string>(17, "LGA2011 (Socket R)"),
    std::pair<const int, const std::string>(18, "Slot A 242"),
    std::pair<const int, const std::string>(19, "Socket 462"),
    std::pair<const int, const std::string>(20, "Socket 754"),
    std::pair<const int, const std::string>(21, "Socket 939"),
    std::pair<const int, const std::string>(22, "Socket 940"),
    std::pair<const int, const std::string>(23, "Socket AM2"),
    std::pair<const int, const std::string>(24, "Socket AM2"),
    std::pair<const int, const std::string>(25, "Socket AM3"),
    std::pair<const int, const std::string>(26, "Socket AM3"),
    std::pair<const int, const std::string>(27, "Socket AM4"),
    std::pair<const int, const std::string>(28, "Socket F"),
    std::pair<const int, const std::string>(29, "Socket FM1"),
    std::pair<const int, const std::string>(30, "Socket FM2"),
    std::pair<const int, const std::string>(31, "Socket TR4")
});
