#include "../include/cybernetwork.h"
#include "../include/cyberboost.h"
#include <iostream>
using namespace std;
int main()
{
 CyberDNS *ser = new CyberDNS();
 CyberBoost *boost = new CyberBoost(ser);
 const string computersXML = "computers.xml";
 const string &computers = computersXML;
 const string networksXML = "network.xml";
 const string &networks = networksXML;
 const string eventsXML = "events.xml";
 const string &events = eventsXML;
 boost->BoostComputers(computers);
 boost->BoostNetwork(networks);
 boost->BoostEvents(events);
 delete ser;
 delete boost;
 return 0; 
}

