#ifndef MODEL_H
#define MODEL_H

#include "cpu.h"
#include "desktop.h"
#include "mobile.h"
#include "server.h"
#include "deepptr.h"
#include "qontainer.h"
#include "serializexml.h"

class Model
{
private:
    Qontainer<DeepPtr<CPU>> data;
public:
    unsigned int size() const;
    unsigned int width() const;
    CPU * operator[](unsigned int) const;
    void pushBack(CPU &);
    void remove(unsigned int);
    void clear();
    void serialize(const std::string &) const;
    void unserialize(const std::string &);
};

#endif // MODEL_H
