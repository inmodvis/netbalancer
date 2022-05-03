#include "configsgetter.h"

ConfigsGetter::ConfigsGetter(std::string &file)
{
    m_File = file;
}

bool ConfigsGetter::GetConfig(size_t &nDataGrams, sockaddr_in &addressIn, vector<sockaddr_in> &addressesOut)
{
    XMLDocument doc;
    doc.LoadFile(m_File.c_str());
    std::string ipAddrIn;
    XMLElement * pRootElement = doc.RootElement();
    if (NULL != pRootElement)
    {
        XMLElement * pNumberOfPack = pRootElement -> FirstChildElement("numberofdatagrams");
        if(pNumberOfPack != NULL)
        {
            int value = pNumberOfPack->UnsignedText();
            nDataGrams = static_cast<size_t>(value);
        }
        else
            return false;

        XMLElement *pAddressIn = pRootElement->FirstChildElement("addressin");
        if(pAddressIn != NULL)
        {
            XMLElement *pAddressInIp = pAddressIn->FirstChildElement("ip");
            XMLElement *pAddressInPort = pAddressIn->FirstChildElement("port");
            if(pAddressInIp != NULL && pAddressInIp != NULL)
            {
                addressIn.sin_family = AF_INET;
                addressIn.sin_port = htons(static_cast<uint16_t>(pAddressInPort->UnsignedText()));
                addressIn.sin_addr.s_addr = inet_addr(pAddressInIp->GetText());
            }
            else
                return false;
        } else
            return false;

        XMLElement *pAddressesOut = pRootElement->FirstChildElement("addresesout");
        if(NULL != pAddressesOut)
        {
            XMLElement * pAddressOut = pAddressesOut->FirstChildElement("addout");
            while( pAddressOut)
            {

                struct sockaddr_in addressOut;

                XMLElement *pAddressOutIp = pAddressOut->FirstChildElement("ip");
                XMLElement *pAddressOutPort = pAddressOut->FirstChildElement("port");


                if(pAddressOutIp != NULL && pAddressOutPort != NULL)
                {
                    addressOut.sin_family = AF_INET;
                    addressOut.sin_addr.s_addr = inet_addr(pAddressOutIp->GetText());
                    addressOut.sin_port = htons(static_cast<uint16_t>(pAddressOutPort->UnsignedText()));
                    addressesOut.push_back(addressOut);
                }
                else
                    return false;

                pAddressOut = pAddressOut-> NextSiblingElement("addout");
            }
        }
        else
            return false;

        return true;
    }
    else
        return false;
}
