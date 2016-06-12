#ifndef CYBER_WORM
#define CYBER_WORM
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CyberWorm
{
private:
    const string cyber_worm_os_;
    const string cyber_worm_name_;
    const int cyber_worm_dormancy_time_;
    CyberWorm(); // Prevent the use of an empty constructor
	// Add your variables here
 
public:
    CyberWorm(string cyber_worm_os, string cyber_worm_name, int cyber_worm_dormancy_time);
	CyberWorm(const CyberWorm& other); //copy constructor;
	// Add your own functions here
	string  getOS();
	int getTime();
	string getName();
};


#endif