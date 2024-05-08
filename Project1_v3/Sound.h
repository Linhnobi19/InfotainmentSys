#pragma once
#ifndef SOUND_H_
#define SOUND_H_

#include "Setting.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Sound : public Setting {

private:
	int media_level;
	int call_level;
	int navi_level;
	int notification_level;
public:
	Sound(int = 0, int = 0, int = 0, int = 0);
	~Sound();
	virtual void nhapThongTin();
	virtual void xuatThongTin();
	int get_media_level() const;
	int get_call_level() const;
	int get_navi_level() const;
	int get_notification_level() const;
	void set_media_level(const int data);
	void set_call_level(const int data);
	void set_navi_level(const int data);
	void set_notification_level(const int data);
};
#endif // SOUND_H_

