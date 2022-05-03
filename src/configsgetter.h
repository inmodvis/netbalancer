#ifndef CONFIGSGETTER_H
#define CONFIGSGETTER_H

#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string>
#include <vector>
#include "tinyxml2/tinyxml2.h"

using namespace std;
using namespace tinyxml2;

class ConfigsGetter
{
public:
    explicit ConfigsGetter(std::string &file);
    bool GetConfig(size_t& mSec, sockaddr_in &addressIn, vector<sockaddr_in> &addressesOut);
private:
    std::string m_File;
};

#endif // CONFIGSGETTER_H
