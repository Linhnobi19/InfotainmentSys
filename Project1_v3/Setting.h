#pragma once
#ifndef SETTING_H_
#define SETTING_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <regex>

using namespace std;

bool checkpattern(string p, string inp);

// Đây sẽ là class cơ sở cho những class phía sau đó
class Setting {
public:
	Setting(string="", string ="00000000", string ="abc@xyz.com", int = 0, int = 0);
	~Setting();
	virtual void nhapThongTin();
	virtual void xuatThongTin();
	void setCarName(const string cname);
	void setPerKey(const string id);
	void setEmail(const string data);
	void setODO(const int num);
	void setSer(const int num);
	// không nên để các hàm này là protected vì hàm kế thừa sẽ không dùng được những hàm này
	string getCarName() const;
	string getPersonalKey() const;
	string getEmail() const;
	int getODO() const;
	int getServiceRemind() const;
private:
	string car_name;
	string personal_key; 	// Chuoi 8 ky tu so
	string email;			// email format abc@xyz.com
	int odo;
	int service_remind;
};
#endif /* SETTING_H_ */
