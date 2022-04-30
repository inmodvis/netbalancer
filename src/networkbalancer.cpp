#include "networkbalancer.h"

NetworkBalancer::NetworkBalancer()
{
    m_initialized= false;
    m_Socket = -1;
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

    }
    else
    {
        throw runtime_error("Not initialized!");
    }
}
