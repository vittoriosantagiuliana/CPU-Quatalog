#include "exceptions.h"

SocketException::SocketException (const std::string & err) : out_of_range(err) { }

CoresException::CoresException (const std::string & err) : std::invalid_argument(err) { }

TDPException::TDPException (const std::string & err) : std::invalid_argument(err) { }
