#include "../include/cyberboost.h"
using boost::property_tree::ptree;
CyberBoost::CyberBoost(CyberDNS * server):server_(server),experts(){}
  void CyberBoost::BoostComputers(const string &filename)
  {
	ptree pt;
	read_xml (filename, pt);
	   BOOST_FOREACH(ptree::value_type &v , pt){
		   if(v.first=="computer"){
			   server_->AddPC(*(new CyberPC(v.second.get<string>("os"),v.second.get<string>("name"))));
			   cout << v.second.get<string>("name") << " connected to server" << endl;
		     
		  }
	   }
	  
  }
  void CyberBoost::BoostNetwork(const string &filename)
  {
	ptree pt;
	read_xml (filename, pt);
	   BOOST_FOREACH(ptree::value_type &v , pt){
		   if(v.first=="wire")
		   {
		          cout << "Connecting "<< v.second.get<string >("pointA") << " to " << v.second.get<string >("pointB") << endl;
			  server_->GetCyberPC(v.second.get<string >("pointA")).AddConnection(v.second.get<string >("pointB"));
			  server_->GetCyberPC(v.second.get<string >("pointB")).AddConnection(v.second.get<string >("pointA"));			    
		   }
	   }
  }
  void CyberBoost::BoostEvents(const string &filename)
  {
    ptree pt;
	read_xml (filename, pt);
	int i = 0;
	int time;
	   BOOST_FOREACH(ptree::value_type &v , pt){
		   cout << "Day : " << i << endl;
	           if(v.first=="hack")
		   {
		          cout << "        " << "Hack occured on " << v.second.get<string >("computer") << endl;
		          CyberWorm *w = new CyberWorm(v.second.get<string >("wormOs"),v.second.get<string >("wormName"),v.second.get<int >("wormDormancy"));
			  CyberWorm &worm = *w;
			  server_->GetCyberPC(v.second.get<string >("computer")).Infect(worm);
			  delete w;
		   }else if(v.first=="clock-in")
		   {
		          CyberExpert *admin = new CyberExpert(v.second.get<string >("name"),v.second.get<int >("workTime"),v.second.get<int >("restTime"),v.second.get<int >("efficiency"));
			  experts.push_back(admin);
			  cout << "        " << "Clock-In: " <<v.second.get<string >("name") << " began working" << endl;
			  
		   }else if(v.first=="termination")
		   {
		      time =v.second.get<int >("time");   
		   }
		   this->update();
		   i++;  
	   }
	   while( i < time + 1)
		      {
			cout << "Day : " << i << endl;
			this->update();
			i++;
		      } 
  }
  void CyberBoost::update()
  {
    vector<string> comps = vector<string>(server_->GetCyberPCList());
    vector<string>::iterator ite = comps.begin();
    for(vector<CyberExpert*>::iterator it = experts.begin();ite != comps.end() && it!=experts.end();++it)
	  {   
	    if((*it)->check()){
	      while(ite != comps.end() && (*it)->checke()){
	       CyberPC & pc = server_->GetCyberPC(*ite);
	       (*it)->Clean(pc);
	       ++ite;
	      }
	    }
	  }
	  
    for(vector<string>::iterator i = comps.begin();i!=comps.end();++i)
	  {
	    CyberPC & pc = server_->GetCyberPC(*i);
	    if(pc.check())
	      pc.Run(*server_);
	  }
  }
  
CyberBoost::~CyberBoost()
{
  vector<CyberExpert*>::iterator it = experts.begin();
  while(it != experts.end()){
    delete *it;
    ++it;
  }
}