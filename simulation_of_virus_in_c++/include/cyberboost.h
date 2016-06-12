#ifndef CYBERBOOST_H
#define CYBERBOOST_H
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>
#include <iostream>
#include <string>

#include "../include/cyberdns.h"
#include "../include/cyberexpert.h"

using namespace std;

class CyberBoost
{
private:
  CyberDNS *server_;
  vector<CyberExpert*> experts;
public:
  CyberBoost(CyberDNS * server);
  void BoostComputers(const string &filename);
  void BoostNetwork(const string &filename);
  void BoostEvents(const string &filename); 
  void update();
  CyberBoost operator=(const CyberBoost&);
  CyberBoost(const CyberBoost&);
  ~CyberBoost();
 
};
#endif