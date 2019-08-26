#ifndef CPU_H
#define CPU_H

#include <map>
#include <string>

class CPU
{
private:
    int chipManufacturer;
    std::string modelName;
    int releaseYear;
    int threadCount;
    int manufacturingProcess;
    bool x86_64;

protected:
    int socket;
    int coreCount;
    int TDP;
    bool eccMemorySupport;

public:
    CPU(const int manufacturer, const std::string & model, const int socket, const int year, const int cores, const int threads, const int nm, const int w, const bool bits, const bool ecc);
    virtual ~CPU() = default;

    static const std::map<const int, const std::string> manufacturers;
    //static const std::map<const int, const std::string> sockets;

    virtual CPU * clone() const = 0;

    // getters
    const std::string & getChipManufacturer() const;
    int getChipManufacturerId() const;
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
    virtual void setCoreCount(const int) = 0;
    void setThreadCount(const int);
    void setManufacturingProcess(const int);
    virtual void setTdpRating(const int) = 0;
    void setArchitecture(const bool);
    virtual void setEccMemorySupport(const bool) = 0;
};

#endif // CPU_H
