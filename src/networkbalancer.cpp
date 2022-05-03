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
    m_addrNum = 0;
}

void NetworkBalancer::Start()
{

    if(m_initialized)
    {
        m_Socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if(m_Socket == -1)
            throw runtime_error("Error in socket");

        int optval = 1;
        if (setsockopt (m_Socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1)
            throw runtime_error("Setsockopt failed. The errno value is: " + to_string(errno));

        if(bind(m_Socket, (struct sockaddr *)&m_addressIn, sizeof(m_addressIn)) == -1)
            throw runtime_error("Error in binding");

        while(1)
        {
            int res = recvfrom(m_Socket, m_Buff, sizeof(m_Buff), 0, 0, 0);
            auto timeNow = chrono::steady_clock::now();
            auto diff = timeNow - queueOfTimes.front();
            while (!queueOfTimes.empty() && chrono::duration_cast<chrono::microseconds>(diff).count() > 1000000)
            {
                queueOfTimes.pop();
                diff = timeNow  - queueOfTimes.front();
            }
            if (queueOfTimes.size() < m_mSec)
            {
                sockaddr_in sentToAddress = m_addressesOut[m_addrNum];
                auto sendRes = sendto(m_Socket, m_Buff, res, 0, (struct sockaddr*)(&sentToAddress), sizeof(sentToAddress));
                auto sendTime = chrono::steady_clock::now();
                if(sendRes != -1)
                    queueOfTimes.push(sendTime);
                ++m_addrNum;
                m_addrNum %= m_addressesOut.size();
            }
        }
    }

    else
    {
        throw runtime_error("Not initialized!");
    }
}




