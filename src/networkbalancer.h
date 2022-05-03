#ifndef NETWORKBALANCER_H
#define NETWORKBALANCER_H


#include <chrono>
#include <iostream>
#include <netinet/in.h>
#include <queue>
#include <string>
#include <stdexcept>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>


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
    char m_Buff[1000];
    queue <chrono::steady_clock::time_point> queueOfTimes;
    int m_addrNum;

};

#endif // NETWORKBALANCER_H
