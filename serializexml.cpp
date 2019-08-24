#include "serializexml.h"

SerializeXML::SerializeXML(const  QString & path) : filePath(path)
{

}

void SerializeXML::write(const Qontainer<DeepPtr<CPU>> & v) const
{
    QSaveFile file(filePath);

    if(!file.open(QIODevice::WriteOnly)) {
        //throw Exception("Errore nell'aprire il file in scrittura");
    }

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);

    writer.writeStartDocument();
    writer.writeStartElement("root"); //apre un tag Root

    if(!v.empty())
    {
        for(auto cit = v.cbegin(); cit != v.cend(); ++cit)
        {
            if(dynamic_cast<const Mobile*>(&(**cit)))
            {
                const Mobile & mobile = static_cast<const Mobile &>(**cit);
                writer.writeStartElement("Mobile");

                writer.writeStartElement("chipManufacturer");
                writer.writeCharacters(QString::fromStdString(mobile.getChipManufacturer()));
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
                    writer.writeCharacters(mobile.is64bit()? "true": "false");
                writer.writeEndElement();

                writer.writeStartElement("eccMemorySupport");
                    writer.writeCharacters(mobile.getEccMemorySupport()? "true": "false");
                writer.writeEndElement();

                writer.writeEndElement();
            }
            else if(dynamic_cast<const Server*>(&(**cit))){
                const Server & server = static_cast<const Server &>(**cit);
                writer.writeStartElement("Server");

                writer.writeStartElement("chipManufacturer");
                writer.writeCharacters(QString::fromStdString(server.getChipManufacturer()));
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
                writer.writeCharacters(server.is64bit()? "true": "false");
                writer.writeEndElement();

                writer.writeStartElement("eccMemorySupport");
                writer.writeCharacters(server.getEccMemorySupport()? "true": "false");
                writer.writeEndElement();

                writer.writeEndElement();
            }
            else if(dynamic_cast<const Desktop*>(&(**cit))) {
                const Desktop & desktop = static_cast<const Desktop &>(**cit);
                writer.writeStartElement("Desktop");

                writer.writeStartElement("chipManufacturer");
                writer.writeCharacters(QString::fromStdString(desktop.getChipManufacturer()));
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
                writer.writeCharacters(desktop.is64bit()? "true": "false");
                writer.writeEndElement();

                writer.writeStartElement("eccMemorySupport");
                writer.writeCharacters(desktop.getEccMemorySupport()? "true": "false");
                writer.writeEndElement();

                writer.writeEndElement();
            }
        }
        writer.writeEndElement(); //chiude root
        writer.writeEndDocument();

        //if(!file.commit())
            //throw Exception("Failed write on XML file");
    }

}

Qontainer<DeepPtr<CPU>> SerializeXML::read() const
{
    Qontainer<DeepPtr<CPU>> vector;
    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly))
    {
        //throw ecx ("Non è stato possibile aprire il file"); non so come si chiami la tua classe di eccezioni, lo lascio a te
        return  vector;
    }

    QXmlStreamReader reader(&file);
    if(reader.readNextStartElement())
    {
        if(reader.name() == "root")
        {
            while(reader.readNextStartElement())
            {
                if(reader.name() == "Mobile")
                {
                    reader.readNextStartElement();
                    int chipManufacturer = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    std::string modelName = (reader.readElementText()).toStdString();
                    reader.readNextStartElement();
                    int socket = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    int releaseYear = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    int coreCount = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    int threadCount = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    int manufacturingProcess = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    int TDP = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    bool x86_64 = (reader.readElementText()) == "true"? true:false;
                    reader.readNextStartElement();
                    bool eccMemorySupport = (reader.readElementText()) == "true"? true:false;
                    reader.readNextStartElement();

                    //vector.push_back(DeepPtr<Mobile>(new Mobile(chipManufacturer, modelName, socket, releaseYear, coreCount, threadCount, manufacturingProcess, TDP, x86_64, eccMemorySupport)));
                }
                else if (reader.name() == "Server")
                {
                    reader.readNextStartElement();
                    int chipManufacturer = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    std::string modelName = (reader.readElementText()).toStdString();
                    reader.readNextStartElement();
                    int socket = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    int releaseYear = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    int coreCount = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    int threadCount = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    int manufacturingProcess = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    int TDP = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    bool x86_64 = (reader.readElementText()) == "true"? true:false;
                    reader.readNextStartElement();
                    bool eccMemorySupport = (reader.readElementText()) == "true"? true:false;

                    //vector.push_back(DeepPtr<Mobile>(new Server(chipManufacturer, modelName, socket, releaseYear, coreCount, threadCount, manufacturingProcess, TDP, x86_64, eccMemorySupport)));
                }
                else if (reader.name() == "Desktop")
                {
                    reader.readNextStartElement();
                    int chipManufacturer = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    std::string modelName = (reader.readElementText()).toStdString();
                    reader.readNextStartElement();
                    int socket = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    int releaseYear = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    int coreCount = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    int threadCount = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    int manufacturingProcess = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    int TDP = (reader.readElementText()).toInt();
                    reader.readNextStartElement();
                    bool x86_64 = (reader.readElementText()) == "true"? true:false;
                    reader.readNextStartElement();
                    bool eccMemorySupport = (reader.readElementText()) == "true"? true:false;

                    //vector.push_back(DeepPtr<Mobile>(new Desktop(chipManufacturer, modelName, socket, releaseYear, coreCount, threadCount, manufacturingProcess, TDP, x86_64, eccMemorySupport)));
                }
            }
        }
    }
    return vector;
}
