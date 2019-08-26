#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

class SocketException : public std::out_of_range
{
public:
    SocketException(const std::string &);
};

class ManufacturerException : public std::out_of_range
{
public:
    ManufacturerException(const std::string &);
};

class CoresException : public std::invalid_argument
{
public:
    CoresException(const std::string &);
};

class TDPException : public std::invalid_argument
{
public:
    TDPException(const std::string &);
};

class FileException : public std::invalid_argument
{
public:
    FileException(const std::string &);
};

#endif // EXCEPTIONS_H
