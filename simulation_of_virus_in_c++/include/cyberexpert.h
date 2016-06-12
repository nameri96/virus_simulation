#ifndef CYBER_EXPERT
#define CYBER_EXPERT
#include <iostream>
#include <string>
#include <vector>
#include "../include/cyberpc.h"
using namespace std;


class CyberExpert
{
private:
	const std::string 	cyber_expert_name_;
    const int cyber_expert_work_time_;
    const int cyber_expert_rest_time_;
    const int cyber_expert_efficiency_;
    int tmp_work_time_;
    int tmp_rest_time_;
    int tmp_efficiency_;
    bool isWork;
    CyberExpert(); // Prevent the use of an empty constructor
	// Add your own variables here
 
public:
    CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_);
 	void Clean(CyberPC & cyber_pc); 
	bool check();
	bool checke();
	~CyberExpert();
};


#endif