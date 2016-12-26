#ifndef __TIME_H__
#define __TIME_H__

#include "Globals.h"
#include "Module.h"

class Time : public Module
{
public:
	Time(const int time, Module* callback = NULL);
	~Time();

	update_status Update();
	void changeTime(const int time);
public: 
	Module* callback;
	unsigned int lastTime = 0, currentTime;
	int timeTarget;
	bool timePassed = false;
}

#endif // __TIME_H_
