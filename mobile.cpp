#include "mobile.h"

Mobile::Mobile(int manufacturer, const std::string & model, int socket, int year, int cores, int threads, int nm, int w, bool bits) : CPU(manufacturer, model, socket, year, cores, threads, nm, w, bits, false)
{
    //if (W > 50)
    //    throw tdpException(50);
}

void Mobile::setEccMemorySupport(const bool) { }

const std::string & Mobile::getSocket() const {
    return sockets.at(socket);
}

void Mobile::setSocket(const int i) {
    if (sockets.find(i) != sockets.end())
        socket = i;
    else
        throw SocketException("mobile");
}

void Mobile::setCoreCount(const int i) {
    if (i < maxCores)
        coreCount = i;
    else
        throw CoresException(std::to_string(i));
}

void Mobile::setTdpRating(const int i) {
    if (i < maxTdp)
        TDP = i;
    else
        throw TDPException(std::to_string(i));
}

const int Mobile::maxCores(8);

const int Mobile::maxTdp(50);

const std::map<const int, const std::string> Mobile::sockets ({
    std::pair<const int, const std::string> (0, "Socket 7"),
    std::pair<const int, const std::string> (1, "TCP320"),
    std::pair<const int, const std::string> (2, "MMC-1"),
    std::pair<const int, const std::string> (3, "MMC-2"),
    std::pair<const int, const std::string> (4, "BGA2"),
    std::pair<const int, const std::string> (5, "Micro-PGA2"),
    std::pair<const int, const std::string> (6, "Socket 495"),
    std::pair<const int, const std::string> (7, "Socket 478"),
    std::pair<const int, const std::string> (8, "Socket 479"),
    std::pair<const int, const std::string> (9, "Micro-FCBGA479"),
    std::pair<const int, const std::string> (10, "mPGA478MT(Socket M)"),
    std::pair<const int, const std::string> (11, "FCBGA6"),
    std::pair<const int, const std::string> (12, "mPGA478MN(Socket P)"),
    std::pair<const int, const std::string> (13, "Micro-FCBGA956"),
    std::pair<const int, const std::string> (14, "Socket G1"),
    std::pair<const int, const std::string> (15, "BGA1288"),
    std::pair<const int, const std::string> (16, "Socket G2"),
    std::pair<const int, const std::string> (17, "BGA1023"),
    std::pair<const int, const std::string> (18, "BGA1224"),
    std::pair<const int, const std::string> (19, "Socket 462(Socket A)"),
    std::pair<const int, const std::string> (20, "Socket 563"),
    std::pair<const int, const std::string> (21, "Socket 754"),
    std::pair<const int, const std::string> (22, "Socket S1g1"),
    std::pair<const int, const std::string> (23, "Socket S1g2"),
    std::pair<const int, const std::string> (24, "Socket S1g3"),
    std::pair<const int, const std::string> (25, "Socket S1g4"),
    std::pair<const int, const std::string> (26, "ASB1"),
    std::pair<const int, const std::string> (27, "ASB2"),
    std::pair<const int, const std::string> (28, "Socket FT1"),
    std::pair<const int, const std::string> (29, "Socket FS1"),
    std::pair<const int, const std::string> (30, "Socket FP2")
});

