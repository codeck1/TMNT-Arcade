#ifndef __Random_H_
#define  __Random_H_

#include <chrono>
#include <time.h>
#include <random>
#include "SDL/include/SDL.h"


class Random
{
private:
	uint64_t timeSeed2;
	mt19937_64 range2;

public:
	Random()
	{}
	~Random()
	{}

	double GetRandom(int first, int second) 
	{
		seed_seq ss{ uint32_t(timeSeed2 & 0xffffffff), uint32_t(timeSeed2 >> 32) };

		timeSeed2 = chrono::high_resolution_clock::now().time_since_epoch().count();
		range2.seed(ss);
		uniform_real_distribution<double> unif(first, second);
		return unif(range2);
	}

};

#endif