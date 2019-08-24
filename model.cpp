#include "model.h"

unsigned int Model::size() const { return data.size(); }
unsigned int Model::width() const { return 10; }

void Model::pushBack(CPU & c) { data.push_back(DeepPtr<CPU>(&c)); }

void Model::remove(unsigned int i) { data.remove(data[i]); }

CPU * Model::operator[](unsigned int i) const { return data[i].operator->(); }

void Model::serialize(const std::string & path) const { SerializeXML serializer(QString::fromStdString(path)); serializer.write(data); }

void Model::unserialize(const std::string & path) { SerializeXML unserializer(QString::fromStdString(path)); data = unserializer.read(); }
