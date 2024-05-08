#include "Setting.h"
#include <iomanip>
#include <iostream>

using namespace std;

// Hàm kiểm tra xem dữ liệu nhập vào có tuân theo tiêu chuẩn của pattern không
bool checkpattern(string p, string inp)
{
	regex regexRule(p);
	bool check = regex_match(inp, regexRule);
	return check;
}


Setting::Setting(string cName, string pk, string _email, int _odo, int sr)
{
	setCarName(cName);
	setPerKey(pk);
	setEmail(_email);
	setODO(_odo);
	setSer(sr);
}

Setting::~Setting()
{
}

void Setting::nhapThongTin()
{
	//fflush(stdin);
	// Nhập tên người sở hữu
	cout << "Owner name: ";
	char ch = cin.peek();
	if (isspace(ch))
	{
		cin.ignore();
	}
	getline(cin, car_name);
	//cout << endl;

	// Nhập địa chỉ email
	bool check;
	do
	{
		check = false;
		cout << "Email: ";
		cin >> email;
		check = checkpattern("\\w.+@\\w+\\.com", email);
		if (!check) {
			cout << "\t---> Your email must to be in \"abc@xyz.com\" form. Please type again." << endl;
		}
	} while (!check);
	cin.ignore();


	// Nhập mã các nhân
	do
	{
		check = false;
		cout << "Key number: ";
		cin >> personal_key;
		check = checkpattern("[0-9]{8}", personal_key);
		if (!check) {
			cout << "\t---> Your key number must include 8 digits. Please type again." << endl;
		}
	} while (!check);



	// Nhập ODO number
	string _odo;
	string _service;
	do
	{
		check = false;
		cout << "ODO number: ";
		cin.ignore();
		cin >> _odo;

		if (_odo >= "a" && _odo <= "z" || _odo>= "A" && _odo<= "Z")
		{
			cout << "\t---> The ODO number can't include character" << endl;
			continue;
		}
		check = stoi(_odo) > 0 ? true : false;
		if (!check)
		{
			cout << "\t---> The ODO number should be greater than 0" << endl;
			continue;
		}
		odo = stoi(_odo);

	} while (!check);

	//cout << endl;

	// cài đặt quãng đường bảo dưỡng
	do
	{
		check = false;
		cout << "Remind sevice: ";
		cin.ignore();
		cin >> _service;

		if (_service >= "a" && _service <= "z" || _service >= "A" && _service <= "Z")
		{
			cout << "\t---> The service reminder number can't include character" << endl;
			continue;
		}
		check = stoi(_service) > 0 ? true : false;
		if (!check)
		{
			cout << "\t---> The service reminder number should be greater than 0" << endl;
			continue;
		}
		service_remind = stoi(_service);

	} while (!check);
	//cout << endl;
}

void Setting::setCarName(const string cname)
{
	car_name = cname;
}

void Setting::setPerKey(const string id)
{
	bool check = checkpattern("[0-9]{8}", id);
	if (check)
	{
		personal_key = id;
	}
	else
		personal_key = "00000000";
}

void Setting::setEmail(const string data)
{
	bool check = checkpattern("\\w.+@\\w+\\.com", data);
	if (check)
	{
		email = data;
	}
	else
	{
		email = "abc@xyz.com";
	}
}

void Setting::setODO(const int num)
{
	if (num < 0)
	{
		odo = 0;
	}
	else
		odo = num;
}

void Setting::setSer(const int num)
{
	if (num < 0)
	{
		service_remind = 0;
	}
	else
	{
		service_remind = num;
	}
}

void Setting::xuatThongTin()
{
	cout << setw(20) << this->getCarName() << setw(25) << this->getEmail()
		<< setw(15) << this->getPersonalKey() << setw(15) << this->getODO()
		<< setw(25) << this->getServiceRemind() << endl;
}

string Setting::getCarName() const
{
	return car_name;
}

string Setting::getPersonalKey() const
{
	return personal_key;
}

string Setting::getEmail() const
{
	return email;
}

int Setting::getODO() const
{
	return odo;
}

int Setting::getServiceRemind() const
{
	return service_remind;
}

