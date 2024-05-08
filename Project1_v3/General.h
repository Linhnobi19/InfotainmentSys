#ifndef GENERAL_H_
#define GENERAL_H_

#include "Setting.h"
#include "CommonInfo.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


//void downloadTimeZone();
//void downloadLanguage();
bool compareNum(CommonInfo& a, CommonInfo& b);
bool compareName(CommonInfo& a, CommonInfo& b);

class General : public Setting {
public:
	General(string = "(GMT+07:00)", string = "Vietnamese");
	~General();
	virtual void nhapThongTin();
	virtual void xuatThongTin();
	string get_language() const;
	string get_timeZone() const;
	void set_timeZone(const string data);
	void set_language(const string data);
private:
	string timeZone;
	string language;
};

#endif 