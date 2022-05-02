#ifndef NETWORKBALANCER_H
#define NETWORKBALANCER_H

#include <vector>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdexcept>
#include <unistd.h>
#include <iostream>



using namespace std;

class NetworkBalancer
{
public:
    NetworkBalancer();
    ~NetworkBalancer();
    void Initilaize(size_t msec, sockaddr_in &addressIn, vector<sockaddr_in> &addressesOut);
    void Start();

private:
    bool m_initialized;
    size_t m_mSec;
    sockaddr_in m_addressIn;
    vector<sockaddr_in>m_addressesOut;
    int m_Socket;
    char m_Buff[100];
};

#endif // NETWORKBALANCER_H
