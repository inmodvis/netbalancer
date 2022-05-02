#include <iostream>

#include "networkbalancer.h"

using namespace std;

int main()
{
    NetworkBalancer Balancer;

    // get from config:
    struct sockaddr_in addressIn;
    addressIn.sin_family = AF_INET;
    addressIn.sin_port = htons(20000);
    addressIn.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    struct sockaddr_in addressOut1;
    addressOut1.sin_family = AF_INET;
    addressOut1.sin_port = htons(20001);
    addressOut1.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    struct sockaddr_in addressOut2;
    addressOut2.sin_family = AF_INET;
    addressOut2.sin_port = htons(20002);
    addressOut2.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    vector<sockaddr_in> addressesOut;
    addressesOut.push_back(addressOut1);
    addressesOut.push_back(addressOut2);

    size_t numInSec = 1;
    // end


    Balancer.Initilaize(numInSec, addressIn, addressesOut);
    Balancer.Start();


    return 0;
}
