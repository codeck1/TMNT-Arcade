#ifndef __ModuleFonts_H_
#define __ModuleFonts_H_

#include "Module.h"


class ModuleFonts : public Module
{
public:
	ModuleFonts(bool active = true);
	~ModuleFonts();

	bool Start();
	update_status Update();
	bool CleanUp();
	bool Life();

public:

	SDL_Texture* fonts = nullptr;
	std::list<int> lifeRest;
};

#endif // __ModuleFonts_H_