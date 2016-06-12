#include "../include/cyberworm.h"



  CyberWorm::CyberWorm():cyber_worm_os_("os"),
    cyber_worm_name_("yo"),
    cyber_worm_dormancy_time_(-1){};

  CyberWorm::CyberWorm(string cyber_worm_os, string cyber_worm_name, int cyber_worm_dormancy_time):cyber_worm_os_(cyber_worm_os),
    cyber_worm_name_(cyber_worm_name),
    cyber_worm_dormancy_time_(cyber_worm_dormancy_time)
  {
  };
  CyberWorm::CyberWorm(const CyberWorm& other):cyber_worm_os_(other.cyber_worm_os_),
    cyber_worm_name_(other.cyber_worm_name_),
    cyber_worm_dormancy_time_(other.cyber_worm_dormancy_time_)
  {
  }
  
  string  CyberWorm::getOS()
  {
    return this->cyber_worm_os_;
  }
  
  int CyberWorm::getTime()
  {
    return cyber_worm_dormancy_time_;
  }
  
  string CyberWorm::getName()
  {
    return this->cyber_worm_name_;
  }

