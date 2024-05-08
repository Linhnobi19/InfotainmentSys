#include "Sound.h"




Sound::Sound(int media, int call, int navi, int notification) : Setting()
{
	set_media_level(media);
	set_call_level(call);
	set_navi_level(navi);
	set_notification_level(notification);
}

Sound::~Sound() {}

void Sound::nhapThongTin() {
	int kiemTra = 0;
	string media_levelString; // các biến kiểm tra xem có nhập kí tự hay không
	string call_levelString;
	string navi_levelString;
	string notification_levelString;
	cout << "Media Level: ";
	do {
		kiemTra = 0;
		cin >> media_levelString;
		if (media_levelString >= "a" && media_levelString <= "z" || media_levelString >= "A" && media_levelString <= "Z") {
			cout << "CANT INPUTING CHARACTER" << endl;
			cout << "YOUR VALUE: ";
			kiemTra = 1;
		}
		else {
			media_level = atoi(media_levelString.c_str());
		}
	} while (kiemTra == 1);
	cout << endl;
	cout << "Call Level: ";
	do {
		kiemTra = 0;
		cin >> call_levelString;
		if (call_levelString >= "a" && call_levelString <= "z" || call_levelString >= "A" && call_levelString <= "Z") {
			cout << "CANT INPUTING CHARACTER" << endl;
			cout << "YOUR VALUE: ";
			kiemTra = 1;
		}
		else {
			call_level = atoi(call_levelString.c_str());
		}
	} while (kiemTra == 1);
	cout << endl;
	cout << "Navi Level: ";
	do {
		kiemTra = 0;
		cin >> navi_levelString;
		if (navi_levelString >= "a" && navi_levelString <= "z" || navi_levelString >= "A" && navi_levelString <= "Z") {
			cout << "CANT INPUTING CHARACTER" << endl;
			cout << "YOUR VALUE: ";
			kiemTra = 1;
		}
		else {
			navi_level = atoi(navi_levelString.c_str());
		}
	} while (kiemTra == 1);
	cout << endl;
	cout << "Notification Level: ";
	do {
		kiemTra = 0;
		cin >> notification_levelString;
		if (notification_levelString >= "a" && notification_levelString <= "z" || notification_levelString >= "A" && notification_levelString <= "Z") {
			cout << "CANT INPUTING CHARACTER" << endl;
			cout << "YOUR VALUE: ";
			kiemTra = 1;
		}
		else {
			notification_level = atoi(notification_levelString.c_str());
		}
	} while (kiemTra == 1);
	cout << endl;
}

void Sound::xuatThongTin() {
	cout << "Email: " << this->getEmail() << endl;
	cout << "Car Name: " << this->getCarName() << endl;
	cout << "Key Number: " << this->getPersonalKey() << endl;
	cout << "ODO Number: " << this->getODO() << endl;
	cout << "Remind service: " << this->getServiceRemind() << endl;
	cout << "Media Level:" << media_level << endl;
	cout << "Call Level: " << call_level;
	cout << "Navi Level: " << navi_level;
	cout << "Notification Level: " << notification_level;
}

int Sound::get_media_level() const {
	return media_level;

}

int Sound::get_call_level() const {
	return call_level;
}

int Sound::get_navi_level() const {
	return navi_level;
}

int Sound::get_notification_level() const {
	return notification_level;
}

void Sound::set_media_level(const int data) {
	if (data < 0)
	{
		media_level = 0;
	}
	else
	{
		media_level = data;
	}
}

void Sound::set_call_level(const int data) {
	if (data < 0)
	{
		call_level = 0;
	}
	else
	{
		call_level = data;
	}
}

void Sound::set_navi_level(const int data) {
	if (data < 0)
	{
		navi_level = 0;
	}
	else
	{
		navi_level = data;
	}

}

void Sound::set_notification_level(const int data) {
	if (data < 0)
	{
		notification_level = 0;
	}
	else
	{
		notification_level = data;
	}

}