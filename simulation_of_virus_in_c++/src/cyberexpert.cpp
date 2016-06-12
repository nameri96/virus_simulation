 #include "../include/cyberexpert.h"



  CyberExpert::CyberExpert():cyber_expert_name_("yo"),
      cyber_expert_work_time_(-1),
      cyber_expert_rest_time_(-1),
      cyber_expert_efficiency_(-1),
      tmp_work_time_(-1),
      tmp_rest_time_(-1),
      tmp_efficiency_(-1),
      isWork(false){};
    CyberExpert::CyberExpert(string cyber_expert_name, int cyber_expert_work_time, int cyber_expert_rest_time, int cyber_expert_efficiency):cyber_expert_name_(cyber_expert_name),
      cyber_expert_work_time_(cyber_expert_work_time),
      cyber_expert_rest_time_(cyber_expert_rest_time),
      cyber_expert_efficiency_(cyber_expert_efficiency),
      tmp_work_time_(cyber_expert_work_time),
      tmp_rest_time_(-1),
      tmp_efficiency_(cyber_expert_efficiency_),
      isWork(cyber_expert_work_time != 0){}
 	
 	void CyberExpert::Clean(CyberPC & cyber_pc)
	{
	  cout << "        " << cyber_expert_name_ << " examining " << cyber_pc.getName() << endl;
	  cyber_pc.Disinfect();
	}
	
	bool CyberExpert::checke()
	{
	  if(tmp_efficiency_ == 0){
	    tmp_efficiency_ = cyber_expert_efficiency_;
	    if(tmp_work_time_ == 0 && cyber_expert_rest_time_ != 0)
	      cout << "        " << cyber_expert_name_ << " is taking a break" << endl;
	    return false;
	  }
	  tmp_efficiency_ -- ;
	  return true;
	}
	
	bool CyberExpert::check()
	{
	  bool ans(isWork);
	  if(isWork)
	  {
	    tmp_work_time_--;
	    if(tmp_work_time_ == 0 && cyber_expert_rest_time_ != 0){
	      isWork = !isWork;
	      tmp_rest_time_ = cyber_expert_rest_time_;
	    }
	  }else
	  {
	    tmp_rest_time_--;
	    if(tmp_rest_time_ == 0 && cyber_expert_work_time_ != 0){
	      isWork = !isWork;
	      tmp_work_time_ = cyber_expert_work_time_;
	      cout << "        " << cyber_expert_name_ << " is back to work" << endl;
	    }
	  }
	  return ans;
	}
	
	CyberExpert::~CyberExpert(){}



