#include "server.h"

Server::Server(const int manufacturer, const std::string & model, const int socket, const int year, const int cores, const int threads, const int nm, const int w, const bool bits, const bool ecc) : CPU(manufacturer, model, socket, year, cores, threads, nm, w, bits, ecc)
{
    //if (!ecc)
    //    throw eccException();
}

const std::map<const int, const std::string> Server::sockets ({
    std::pair<const int, const std::string> (0, "Slot 8"),
    std::pair<const int, const std::string> (1, "Slot 2"),
    std::pair<const int, const std::string> (2, "Socket 603"),
    std::pair<const int, const std::string> (3, "Socket 604"),
    std::pair<const int, const std::string> (4, "LGA775 (Socket T)"),
    std::pair<const int, const std::string> (5, "LGA771 (Socket J)"),
    std::pair<const int, const std::string> (6, "mPGA478MT (Socket M)"),
    std::pair<const int, const std::string> (7, "LGA1155 (Socket H2"),
    std::pair<const int, const std::string> (8, "LGA1156 (Socket H1"),
    std::pair<const int, const std::string> (9, "LGA1366 (Socket B)"),
    std::pair<const int, const std::string> (10, "FCLGA1567"),
    std::pair<const int, const std::string> (11, "LGA2011 (Socket R)"),
    std::pair<const int, const std::string> (12, "FCLGA1356"),
    std::pair<const int, const std::string> (13, "PAC418"),
    std::pair<const int, const std::string> (14, "PAC611"),
    std::pair<const int, const std::string> (15, "LGA1248"),
    std::pair<const int, const std::string> (16, "Socket 939"),
    std::pair<const int, const std::string> (17, "Socket 940"),
    std::pair<const int, const std::string> (18, "Socket F"),
    std::pair<const int, const std::string> (19, "Socket C32"),
    std::pair<const int, const std::string> (20, "Socket G34")
});
