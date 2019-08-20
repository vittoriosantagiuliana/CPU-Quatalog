#ifndef SERIALIZEXML_H
#define SERIALIZEXML_H

#include "qontainer.h"
#include "cpu.h"
#include "mobile.h"
#include "server.h"
#include "desktop.h"

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
    Qontainer<DeepPtr<CPU>> read() const;
};

#endif // SERIALIZEXML_H
