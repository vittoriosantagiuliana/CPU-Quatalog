#include "cpu.h"

const std::map <const int, const std::string> CPU::manufacturers ( { std::pair <const int, const std::string> (0, "AMD"), std::pair <const int, const std::string> (1, "Intel") } );

CPU::CPU (const int manufacturer, const std::string & model, const int socket, const int year, const int cores, const int threads, const int nm, const int w, const bool bits, const bool ecc) : chipManufacturer(manufacturer), modelName(model), socket(socket), releaseYear(year), coreCount(cores), threadCount(threads), manufacturingProcess(nm), TDP(w), x86_64(bits), eccMemorySupport(ecc) {
    //manufacturer exception
}

// getters

const std::string & CPU::getChipManufacturer() const {  return manufacturers.at(chipManufacturer); }

const std::string & CPU::getModelName() const { return modelName; }

int CPU::getReleaseYear() const { return releaseYear; }

int CPU::getCoreCount() const { return coreCount; }

int CPU::getThreadCount() const { return threadCount; }

int CPU::getManufacturingProcess() const { return manufacturingProcess; }

int CPU::getTdpRating() const { return TDP; }

bool CPU::is64bit() const { return x86_64; }

bool CPU::getEccMemorySupport() const { return eccMemorySupport; }


// setters

void CPU::setManufacturer(const int manufacturer) {
    if (manufacturers.find(manufacturer) != manufacturers.end())
        chipManufacturer = manufacturer;
    //else eccezione
}

void CPU::setModelName(const std::string & model) { modelName = model; }

void CPU::setReleaseYear(const int year) { releaseYear = year; }

void CPU::setCoreCount(const int cores) { coreCount = cores; }

void CPU::setThreadCount(const int threads) { threadCount = threads; }

void CPU::setManufacturingProcess(const int nm) { manufacturingProcess = nm; }

void CPU::setArchitecture(const bool is64bit) { x86_64 = is64bit; }





