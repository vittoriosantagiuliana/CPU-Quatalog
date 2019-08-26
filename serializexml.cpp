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
        for (auto cit = model.cbegin(); cit != model.cend(); ++cit)
        {
            if (dynamic_cast<const Mobile *>(&(**cit)))
            {
                const Mobile &mobile = static_cast<const Mobile &>(**cit);
                writer.writeStartElement("Mobile");

                writer.writeStartElement("chipManufacturer");
                writer.writeCharacters(QString::number(mobile.getChipManufacturerId()));
                writer.writeEndElement();

                writer.writeStartElement("modelName");
                writer.writeCharacters(QString::fromStdString(mobile.getModelName()));
                writer.writeEndElement();

                writer.writeStartElement("socket");
                writer.writeCharacters(QString::fromStdString(mobile.getSocket()));
                writer.writeEndElement();

                writer.writeStartElement("releaseYear");
                writer.writeCharacters(QString::number(mobile.getReleaseYear()));
                writer.writeEndElement();

                writer.writeStartElement("coreCount");
                writer.writeCharacters(QString::number(mobile.getCoreCount()));
                writer.writeEndElement();

                writer.writeStartElement("threadCount");
                writer.writeCharacters(QString::number(mobile.getThreadCount()));
                writer.writeEndElement();

                writer.writeStartElement("manufacturingProcess");
                writer.writeCharacters(QString::number(mobile.getManufacturingProcess()));
                writer.writeEndElement();

                writer.writeStartElement("TDP");
                writer.writeCharacters(QString::number(mobile.getTdpRating()));
                writer.writeEndElement();

                writer.writeStartElement("x86_64");
                writer.writeCharacters(mobile.is64bit() ? "true" : "false");
                writer.writeEndElement();

                writer.writeEndElement();
            }
            else if (dynamic_cast<const Server *>(&(**cit)))
            {
                const Server &server = static_cast<const Server &>(**cit);
                writer.writeStartElement("Server");

                writer.writeStartElement("chipManufacturer");
                writer.writeCharacters(QString::number(server.getChipManufacturerId()));
                writer.writeEndElement();

                writer.writeStartElement("modelName");
                writer.writeCharacters(QString::fromStdString(server.getModelName()));
                writer.writeEndElement();

                writer.writeStartElement("socket");
                writer.writeCharacters(QString::fromStdString(server.getSocket()));
                writer.writeEndElement();

                writer.writeStartElement("releaseYear");
                writer.writeCharacters(QString::number(server.getReleaseYear()));
                writer.writeEndElement();

                writer.writeStartElement("coreCount");
                writer.writeCharacters(QString::number(server.getCoreCount()));
                writer.writeEndElement();

                writer.writeStartElement("threadCount");
                writer.writeCharacters(QString::number(server.getThreadCount()));
                writer.writeEndElement();

                writer.writeStartElement("manufacturingProcess");
                writer.writeCharacters(QString::number(server.getManufacturingProcess()));
                writer.writeEndElement();

                writer.writeStartElement("TDP");
                writer.writeCharacters(QString::number(server.getTdpRating()));
                writer.writeEndElement();

                writer.writeStartElement("x86_64");
                writer.writeCharacters(server.is64bit() ? "true" : "false");
                writer.writeEndElement();

                writer.writeEndElement();
            }
            else if (dynamic_cast<const Desktop *>(&(**cit)))
            {
                const Desktop &desktop = static_cast<const Desktop &>(**cit);
                writer.writeStartElement("Desktop");

                writer.writeStartElement("chipManufacturer");
                writer.writeCharacters(QString::number(desktop.getChipManufacturerId()));
                writer.writeEndElement();

                writer.writeStartElement("modelName");
                writer.writeCharacters(QString::fromStdString(desktop.getModelName()));
                writer.writeEndElement();

                writer.writeStartElement("socket");
                writer.writeCharacters(QString::fromStdString(desktop.getSocket()));
                writer.writeEndElement();

                writer.writeStartElement("releaseYear");
                writer.writeCharacters(QString::number(desktop.getReleaseYear()));
                writer.writeEndElement();

                writer.writeStartElement("coreCount");
                writer.writeCharacters(QString::number(desktop.getCoreCount()));
                writer.writeEndElement();

                writer.writeStartElement("threadCount");
                writer.writeCharacters(QString::number(desktop.getThreadCount()));
                writer.writeEndElement();

                writer.writeStartElement("manufacturingProcess");
                writer.writeCharacters(QString::number(desktop.getManufacturingProcess()));
                writer.writeEndElement();

                writer.writeStartElement("TDP");
                writer.writeCharacters(QString::number(desktop.getTdpRating()));
                writer.writeEndElement();

                writer.writeStartElement("x86_64");
                writer.writeCharacters(desktop.is64bit() ? "true" : "false");
                writer.writeEndElement();

                writer.writeStartElement("eccMemorySupport");
                writer.writeCharacters(desktop.getEccMemorySupport() ? "true" : "false");
                writer.writeEndElement();

                writer.writeEndElement();
            }
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
                {
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

                    model->push_back(new Mobile(chipManufacturer, modelName, socket, releaseYear, coreCount, threadCount, manufacturingProcess, TDP, x86_64));
                }
                else if (reader.name() == "Server")
                {
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

                    model->push_back(new Server(chipManufacturer, modelName, socket, releaseYear, coreCount, threadCount, manufacturingProcess, TDP, x86_64));
                }
                else if (reader.name() == "Desktop")
                {
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
                    eccMemorySupport = reader.readElementText() == "true";
                    reader.readNextStartElement();

                    model->push_back(new Desktop(chipManufacturer, modelName, socket, releaseYear, coreCount, threadCount, manufacturingProcess, TDP, x86_64, eccMemorySupport));
                }
            }
        }
    }
    return *model;
}
