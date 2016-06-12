#include "../include/cyberdns.h"
#include <vector>
using namespace std;

CyberDNS:: CyberDNS():cyber_DNS_()
    {}
	void CyberDNS::AddPC(CyberPC & cyber_pc_)
	{
	  cout << "Adding to server: " <<  cyber_pc_.getName() << endl;
	  cyber_DNS_.insert(std::pair<string,CyberPC&>(cyber_pc_.getName(), cyber_pc_));
	}
	CyberPC & CyberDNS::GetCyberPC(const string & cyber_pc_name)const
	{
	  return (cyber_DNS_.find(cyber_pc_name))->second;
	}
	vector<string> CyberDNS::GetCyberPCList()
	{
	  map<const string, CyberPC &>::iterator it = cyber_DNS_.begin();
	  vector<string> ret;
	  while(it!=cyber_DNS_.end())
	  {
	    ret.insert(ret.begin(),it->first);
	    it++;
	  }
	  return ret;
	}
	CyberDNS::~CyberDNS()
	{
	  map<const string, CyberPC &>::iterator it = cyber_DNS_.begin();
	  while(it!=cyber_DNS_.end())
	  {
	    delete &it->second; 
	    it++;
	  }
	}



