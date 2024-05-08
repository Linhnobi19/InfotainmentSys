#pragma once
#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class CommonInfo
{
public:
	void setName(string n) {
		name = n;
	}
	void setNum(string n) {
		number = n;
	}
	string getName() {
		return name;
	}
	string getNumber() {
		return number;
	}
	// Do file language có định dạng số / loại ngôn ngữ nên không cần dùng thêm biến
	void printInfo() {
		cout << number << ": " << name << endl;
	}

private:
	string name;
	string number;
};

#endif