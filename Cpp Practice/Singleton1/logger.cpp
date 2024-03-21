#include <iostream>
#include "logger.hpp"

using namespace std;
int Logger::cnt = 0;
mutex Logger::mtx;
Logger* Logger::loggerInstance = nullptr;

Logger::Logger(){
    cnt++;
    cout << "Instance created." <<" Instances "<< cnt <<endl;
}

Logger::Logger (const Logger &obj)
{
    
}

Logger Logger::operator = (const Logger &obj)
{

}

Logger* Logger::getLogger()
{
    if(loggerInstance == nullptr)
    {
        mtx.lock();
        if(loggerInstance == nullptr)
        {
            loggerInstance = new Logger();
        }
        mtx.unlock();
    }
    return loggerInstance;
}

void Logger::Log(string msg)
{
    cout << msg << endl;
}