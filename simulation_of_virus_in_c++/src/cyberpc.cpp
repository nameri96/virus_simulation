#include "../include/cyberpc.h"
using namespace std;


    CyberPC::CyberPC():cyber_pc_os_("os"),cyber_pc_name_("yo"),cyber_pc_connections_(),cyber_pc_time_to_infect_(-1),
    reacantly_infected_(false)
      {};   
    CyberPC::CyberPC(string cyber_pc_os, string cyber_pc_name):cyber_pc_os_(cyber_pc_os),
    cyber_pc_name_(cyber_pc_name),
    cyber_pc_connections_(),
    cyber_pc_time_to_infect_(-1),
    reacantly_infected_(false)
    {};
    const string CyberPC::getName()
    {
      return cyber_pc_name_;
    }
	void CyberPC::AddConnection(string  second_pc)
	{
	  cyber_pc_connections_.push_back(second_pc);
	  cout << "        " << cyber_pc_name_ << " now connected to " <<  second_pc << endl;
	}
	void CyberPC::Infect(CyberWorm & worm)
	{
	  if((worm.getOS()).compare(cyber_pc_os_) == 0)
	  {
	    if(cyber_worm_ != NULL)
	      delete cyber_worm_;
	    cyber_worm_ = new CyberWorm(worm);
	    cyber_pc_time_to_infect_ = worm.getTime();
	    cout << "        " << "        " << cyber_pc_name_ << " infected by " <<  cyber_worm_->getName() << endl;
	    reacantly_infected_ = true;
	    
	  }else
	    cout << "        " << "        " << "Worm " << worm.getName() << " is incompatible with " <<  cyber_pc_name_ << endl;
	  
	}
	void CyberPC::Run(const CyberDNS & server)
	{
	  if(cyber_worm_ != NULL){
	   cout << "        " << cyber_pc_name_ << " infecting... " << endl;
	   for(vector<string>::iterator it = cyber_pc_connections_.begin();it!=cyber_pc_connections_.end();++it)
	   {
	     CyberPC & pc = server.GetCyberPC(*it);
	     pc.Infect(*cyber_worm_);
	   }
	  }
	}
	void CyberPC::Disinfect()
	{
	  if(cyber_worm_ != NULL){
	    cout << "        " << "        " << "Worm " << cyber_worm_->getName() << " successfully removed from " << cyber_pc_name_ << endl;
	   delete cyber_worm_;
	   cyber_worm_= NULL;
	   cyber_pc_time_to_infect_ = -1;
	   reacantly_infected_ = false;
	  }
	}
	bool CyberPC::check()
	{ 
	  if(reacantly_infected_){
	    cout << "        " << cyber_pc_name_ << ": " << " Worm " << cyber_worm_->getName() << " is dormant" << endl;
	    reacantly_infected_ = false;
	    
	  }
	  if(cyber_pc_time_to_infect_ == 0){
	    return true;
	  }else
	  {
	    cyber_pc_time_to_infect_--;
	    return false;
	  }  
	  
	}
	CyberPC::~CyberPC()
	{
	  if(cyber_worm_ != NULL)
	    delete cyber_worm_;
	}
	//Add additional functions here if necessary



