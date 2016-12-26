#include "Time.h"
#include "SDL/include/SDL.h"

Time::Time(const int time, Module* callback) : timeTarget(time)
{
}

Time::~Time()
{

}

update_status Time::Update()
{
	if (timeTarget != NULL)
	{

		currentTime = SDL_GetTicks();
		if (currentTime > lastTime + timeTarget)
		{
			lastTime = currentTime;
		}
		else
		{
			timeTarget == NULL;
			callback->onTimePassed(currentTime);
		}
			
	}
	return update_status();

}

void Time::changeTime(const int time)
{
	lastTime = 0;
	timeTarget = time;
}




