#ifndef SERIALIZEXML_H
#define SERIALIZEXML_H

#include "deepptr.h"
#include "qontainer.h"
#include "cpu.h"
#include "desktop.h"
#include "mobile.h"
#include "server.h"

#include <QString>
#include <QFile>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

class SerializeXML
{
private:
    QString filePath;
public:
    SerializeXML(const QString &);
    void write(const Qontainer<DeepPtr<CPU>> &) const;
    Qontainer<DeepPtr<CPU>> & read() const;
};

#endif // SERIALIZEXML_H
