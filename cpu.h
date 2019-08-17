#ifndef CPU_H
#define CPU_H

#include <map>
#include <string>

class CPU
{
private:
    int chipManufacturer;
    std::string modelName;
    int socket;
    int releaseYear;
    int coreCount;
    int threadCount;
    int manufacturingProcess;
    int TDP;
    bool x86_64;
    bool eccMemorySupport; ////////// costruttore!

public:
    CPU(const int manufacturer, const std::string & model, const int socket, const int year, const int cores, const int threads, const int nm, const int w, const int bits);
    virtual ~CPU() = default;

    static const std::map<const int, const std::string> manufacturers;

    // getters
    const std::string & getChipManufacturer() const;
    const std::string & getModelName() const;
    virtual const std::string & getSocket() const = 0;
    int getReleaseYear() const;
    int getCoreCount() const;
    int getThreadCount() const;
    int getManufacturingProcess() const;
    int getTdpRating() const;
    bool is64bit() const;
    bool getEccMemorySupport() const;

    // setters
    void setManufacturer (const int);
    void setModelName (const std::string &);
    virtual void setSocket(const int) = 0;
    void setReleaseYear(const int);
    void setCoreCount(const int);
    void setThreadCount(const int);
    void setManufacturingProcess(const int);
    virtual void setTdpRating(const int) = 0;
    void setArchitecture(const bool);
    virtual void setEccMemorySupport(const bool) = 0;
};

#endif // CPU_H
