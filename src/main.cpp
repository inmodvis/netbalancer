#include "networkbalancer.h"
#include "configsgetter.h"

using namespace std;

int main()
{
    NetworkBalancer Balancer;


    struct sockaddr_in addressIn;
    vector <sockaddr_in> addressesOut;
    size_t numInSec = 0;
    std::string config = "../Config.xml";
    ConfigsGetter ConfGet(config);
    bool resultCfg = ConfGet.GetConfig(numInSec,addressIn,addressesOut);
    if(resultCfg)
    {
        Balancer.Initilaize(numInSec, addressIn, addressesOut);
        Balancer.Start();
    } else
        return -1;

    return 0;
}
