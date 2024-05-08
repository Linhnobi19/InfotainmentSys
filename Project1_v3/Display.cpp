#include "Display.h"
#include <iomanip>

using namespace std;

Display::Display(int light, int screen, int taplo) : Setting()
{
	set_light_level(light);
	set_screen_light_level(screen);
	set_taplo_light_level(taplo);
}

Display::~Display()
{
}

void Display::nhapThongTin()
{
	int kiemTra = 0;
	string light_levelString; // các biến kiểm tra xem có nhập kí tự hay không
	string screen_levelString;
	string taplo_levelString;
	cout << "Light Level: ";
	do {
		kiemTra = 0;
		cin >> light_levelString;
		if (light_levelString >= "a" && light_levelString <= "z" || light_levelString >= "A" && light_levelString <= "Z") {
			cout << "CANT INPUTING CHARACTER" << endl;
			cout << "YOUR VALUE: ";
			kiemTra = 1;
		}
		else {
			light_level = atoi(light_levelString.c_str());
		}
	} while (kiemTra == 1);
	cout << endl;
	cout << "Screen Level: ";
	do {
		kiemTra = 0;
		cin >> screen_levelString;
		if (screen_levelString >= "a" && screen_levelString <= "z" || screen_levelString >= "A" && screen_levelString <= "Z") {
			cout << "CANT INPUTING CHARACTER" << endl;
			cout << "YOUR VALUE: ";
			kiemTra = 1;
		}
		else {
			screen_light_level= atoi(screen_levelString.c_str());
		}
	} while (kiemTra == 1);
	cout << endl;
	cout << "Taplo Level: ";
	do {
		kiemTra = 0;
		cin >> taplo_levelString;
		if (taplo_levelString >= "a" && taplo_levelString <= "z" || taplo_levelString >= "A" && taplo_levelString <= "Z") {
			cout << "CANT INPUTING CHARACTER" << endl;
			cout << "YOUR VALUE: ";
			kiemTra = 1;
		}
		else {
			taplo_light_level = atoi(taplo_levelString.c_str());
		}
	} while (kiemTra == 1);
	cout << endl;
}

void Display::xuatThongTin()
{
	cout << "Car Name: " << this->getCarName() << endl;
	cout << "Email: " << this->getEmail() << endl;
	cout << "Key Number: " << this->getPersonalKey() << endl;
	cout << "ODO Number: " << this->getODO() << endl;
	cout << "Remind service: " << this->getServiceRemind() << endl;
	cout << "Light Level:" << light_level << endl;
	cout << "Screen light Level: " << screen_light_level << endl;
	cout << "Taplo light Level: " << taplo_light_level << endl;
}

int Display::get_light_level() const
{
	return light_level;
}

int Display::get_screen_light_level() const 
{
	return screen_light_level;
}

int Display::get_taplo_light_level() const
{
	return taplo_light_level;
}

void Display::set_light_level(const int data)
{
	if (data > 0)
	{
		light_level = data;
	}
	else
		light_level = 0;
}

void Display::set_screen_light_level(const int data)
{
	if (data > 0)
	{
		screen_light_level = data;
	}
	else
		screen_light_level = 0;
}

void Display::set_taplo_light_level(const int data)
{
	if (data > 0)
	{
		taplo_light_level = data;
	}
	else
		taplo_light_level = 0;
}
