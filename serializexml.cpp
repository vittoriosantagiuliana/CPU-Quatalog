#include "serializexml.h"

SerializeXML::SerializeXML(const QString &path) : filePath(path) {}

void SerializeXML::write(const Qontainer<DeepPtr<CPU>> &model) const
{
    QSaveFile file(filePath);

    if (!file.open(QIODevice::WriteOnly))
        throw FileException("Error opening the file");

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);

    writer.writeStartDocument();
    writer.writeStartElement("Qatalog");

    if (!model.empty())
    {
        CPU * c = nullptr;
        for (auto i = model.cbegin(); i != model.cend(); ++i)
        {
            c = &(**i);

            if (dynamic_cast<const Mobile *>(c))
                writer.writeStartElement("Mobile");
            else if (dynamic_cast<const Server *>(c))
                writer.writeStartElement("Server");
            else if (dynamic_cast<const Desktop *>(c))
                writer.writeStartElement("Desktop");

            
            writer.writeStartElement("chipManufacturerId");
            writer.writeCharacters(QString::number(c->getChipManufacturerId()));
            writer.writeEndElement();
            writer.writeStartElement("modelName");
            writer.writeCharacters(QString::fromStdString(c->getModelName()));
            writer.writeEndElement();
            writer.writeStartElement("socketId");
            writer.writeCharacters(QString::number(c->getSocketId()));
            writer.writeEndElement();
            writer.writeStartElement("releaseYear");
            writer.writeCharacters(QString::number(c->getReleaseYear()));
            writer.writeEndElement();
            writer.writeStartElement("coreCount");
            writer.writeCharacters(QString::number(c->getCoreCount()));
            writer.writeEndElement();
            writer.writeStartElement("threadCount");
            writer.writeCharacters(QString::number(c->getThreadCount()));
            writer.writeEndElement();
            writer.writeStartElement("manufacturingProcess");
            writer.writeCharacters(QString::number(c->getManufacturingProcess()));
            writer.writeEndElement();
            writer.writeStartElement("tdpRating");
            writer.writeCharacters(QString::number(c->getTdpRating()));
            writer.writeEndElement();
            writer.writeStartElement("x86_64");
            writer.writeCharacters(c->is64bit() ? "true" : "false");
            writer.writeEndElement();
            if (const Desktop * d = dynamic_cast<const Desktop *>(c))
            {
                writer.writeStartElement("eccMemorySupport");
                writer.writeCharacters(d->getEccMemorySupport() ? "true" : "false");
                writer.writeEndElement();
            }

            writer.writeEndElement();
        }
        writer.writeEndElement();
        writer.writeEndDocument();

        if (!file.commit())
            throw FileException("Failed writing XML file");
    }
}

Qontainer<DeepPtr<CPU>> &SerializeXML::read() const
{
    Qontainer<DeepPtr<CPU>> *model = new Qontainer<DeepPtr<CPU>>();
    QFile file(filePath);
    int type = 0;

    int chipManufacturer;
    std::string modelName;
    int socket;
    int releaseYear;
    int coreCount;
    int threadCount;
    int manufacturingProcess;
    int TDP;
    bool x86_64;
    bool eccMemorySupport;

    if (!file.open(QIODevice::ReadOnly))
        throw FileException("Error opening file");

    QXmlStreamReader reader(&file);
    if (reader.readNextStartElement())
    {
        if (reader.name() == "Qatalog")
        {
            while (reader.readNextStartElement())
            {

                if (reader.name() == "Mobile")
                    type = 0;
                else if (reader.name() == "Server")
                    type = 1;
                else if (reader.name() == "Desktop")
                    type = 2;

                reader.readNextStartElement();
                chipManufacturer = (reader.readElementText()).toInt();
                reader.readNextStartElement();
                modelName = (reader.readElementText()).toStdString();
                reader.readNextStartElement();
                socket = (reader.readElementText()).toInt();
                reader.readNextStartElement();
                releaseYear = (reader.readElementText()).toInt();
                reader.readNextStartElement();
                coreCount = (reader.readElementText()).toInt();
                reader.readNextStartElement();
                threadCount = (reader.readElementText()).toInt();
                reader.readNextStartElement();
                manufacturingProcess = (reader.readElementText()).toInt();
                reader.readNextStartElement();
                TDP = (reader.readElementText()).toInt();
                reader.readNextStartElement();
                x86_64 = reader.readElementText() == "true";
                reader.readNextStartElement();

                switch (type) {
                case 0:
                    model->push_back(new Mobile(chipManufacturer, modelName, socket, releaseYear, coreCount, threadCount, manufacturingProcess, TDP, x86_64));
                    break;
                case 1:
                    model->push_back(new Server(chipManufacturer, modelName, socket, releaseYear, coreCount, threadCount, manufacturingProcess, TDP, x86_64));
                    break;
                case 2:
                    eccMemorySupport = reader.readElementText() == "true";
                    reader.readNextStartElement();
                    model->push_back(new Desktop(chipManufacturer, modelName, socket, releaseYear, coreCount, threadCount, manufacturingProcess, TDP, x86_64, eccMemorySupport));
                    break;
                default:
                    break;
                }
            }
        }
    }
    return *model;
}
