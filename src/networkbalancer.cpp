#include "networkbalancer.h"

NetworkBalancer::NetworkBalancer()
{
    m_initialized= false;
    m_Socket = -1;
}

NetworkBalancer::~NetworkBalancer()
{
    if(m_initialized && m_Socket != -1)
    {
        close(m_Socket);
    }
}

void NetworkBalancer::Initilaize(size_t mSec, sockaddr_in &addressIn, vector<sockaddr_in> &addressesOut)
{
    m_mSec = mSec;
    m_addressIn = addressIn;
    m_addressesOut = addressesOut;
    m_initialized = true;
}

void NetworkBalancer::Start()
{

    if(m_initialized)
    {
        m_Socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if(m_Socket == -1)
            throw runtime_error("Error in socket");

        if(bind(m_Socket, (struct sockaddr *)&m_addressIn, sizeof(m_addressIn)) == -1)
            throw runtime_error("Error in binding");

        while(1)
        {
            int res = recvfrom(m_Socket, m_Buff, sizeof(m_Buff), 0, 0, 0);
            std::cout << m_Buff << " was recived\n";
        }

    }
    else
    {
        throw runtime_error("Not initialized!");
    }
}
