#ifndef NETWORKBALANCER_H
#define NETWORKBALANCER_H


#include <vector>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdexcept>


using namespace std;

class NetworkBalancer
{
public:
    NetworkBalancer();
    void Initilaize(size_t msec, sockaddr_in &addressIn, vector<sockaddr_in> &addressesOut);
    void Start();

private:
    bool m_initialized;
    size_t m_mSec;
    sockaddr_in m_addressIn;
    vector<sockaddr_in>m_addressesOut;
    int m_Socket;
};

#endif // NETWORKBALANCER_H
