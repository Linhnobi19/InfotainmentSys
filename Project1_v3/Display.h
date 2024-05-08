#pragma once
#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "Setting.h"
#include <iostream>
#include <string>

using namespace std;

class Display : public Setting {

public:
	Display(int = 2, int = 3, int = 1);
	~Display();
	virtual void nhapThongTin();
	virtual void xuatThongTin();
	int get_light_level() const;
	int get_screen_light_level() const;
	int get_taplo_light_level() const;
	void set_light_level(const int data);
	void set_screen_light_level(const int data);
	void set_taplo_light_level(const int data);
private:
	int light_level;
	int screen_light_level;
	int taplo_light_level;
};

#endif /* DISPLAY_H_ */
