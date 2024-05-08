// Project1_v3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "General.h"
#include "Display.h"
#include "Sound.h"
#include "Car.h"
#include <iomanip>
#include "CommonInfo.h"
#include "BST.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <list>

using namespace std;

vector<CommonInfo> languageList;
vector<CommonInfo> timezoneList;
vector<CommonInfo> languageListCopy;

//Car** listCar = new Car * [100];			// mảng lưu trữ xe;
//int carCnt = 0;				// Biến đếm số xe được lưu  trữ

// replacement for advance pointer
list<Car> listCar;

BST* bTree = new BST;

// function for getting from file
void getValueFromFile(string fileName);

void saveFile(list<Car> listC);

bool checkFile(string path);


void NhapThongTinCaiDat();
void XuatThongTinCaiDat();

void XuatThongTinCaiDat_Sound();
void XuatThongTinCaiDat_General();
void XuatThongTinCaiDat_Display();
void XuatTatCaThongTinCaiDat();

void NhapThongTinCaiDat_Sound();
void NhapThongTinCaiDat_General();
void NhapThongTinCaiDat_Display();

int menu();

//int checkCar(Car& check_car);

void downloadLanguage();
void downloadTimeZone();

const vector<string> explode(const string& s, const char& c) // hàm phân tách chuỗi cho timezones và language. 
//Phân tách ra các dòng khi gặp kí tự c
{
	string buff{ "" };
	vector<string> v;				// Lưu từng thành phần được ngăn nhau bởi c

	for (auto n : s)
	{
		if (n != c)
			buff += n;
		else if (n == c && buff != "")
		{
			if (buff[0] == ' ')
			{
				buff.erase(buff.begin());
			}
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "") {
		if (buff[0] == ' ')
		{
			buff.erase(buff.begin());
		}
		v.push_back(buff);	// tránh trường hợp để xót đối tượng cuối cùng khi k gặp ký tự c
	}

	return v;
}

/* 
The structure of file text is:
Common: [Common information];Display: [Display information];Sound: [Sound information];General: [General information]
*/
const vector<string> explodeInfo(const string& s, const char& c) {
	string buff{ "" };
	vector<string> v;				// Lưu từng thành phần được ngăn nhau bởi c

	// because in general timezone have character ':" 
	// so you need to delete at first when before it is common, sound, ... 
	bool k = true;		

	for (auto n : s)
	{
		if (n != c) {
			buff += n;
			if (n == ':' && k) {
				// the structure is "Info:" so it's just title not the value for using
				// set to default
				buff = "";
				k = !k;
			}
		}
		else if (n == c && buff != "")
		{
			// delete the character ' ' for at first
			if (buff[0] == ' ') {
				buff.erase(buff.begin());
			}
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "") {
		if (buff[0] == ' ') {
			buff.erase(buff.begin());
		}
		v.push_back(buff);
	}
	return v;
}

int main()
{
	downloadTimeZone();
	downloadLanguage();


	getValueFromFile("Setting.txt");
	system("pause");

	bool outloop = true;
	do
	{
		system("cls");
		outloop = true;
		int choice;
		choice = menu();
		cin.clear();
		switch (choice)
		{
		case 1:
			NhapThongTinCaiDat();
			break;
		case 2:
			XuatThongTinCaiDat();
			break;
		case 3:
			outloop = false;
			saveFile(listCar);
		default:
			break;
		}
		system("pause");
	} while (outloop == true);

	cout << "Bye bye!!!..." << endl;	

	/*system("cls");
	string s1;
	cin >> s1;
	bTree->searchByKey(s1);*/



	return 0;
}

void downloadLanguage()
{
	ifstream ifile("languages.txt");
	if (ifile.is_open()) {
		while (!ifile.eof())
		{
			string line;
			CommonInfo newlanguage;
			getline(ifile, line);
			vector<string> data = explode(line, '/');
			if (data.size() >= 2) {
				newlanguage.setNum(data[0]);
				newlanguage.setName(data[1]);
				languageList.push_back(newlanguage);
				languageListCopy.push_back(newlanguage);
			}
		}

		ifile.close();

		sort(languageList.begin(), languageList.end(), compareName);
		for (size_t i = 0; i < languageListCopy.size(); i++)
		{
			languageList[i].setNum(to_string(i + 1));
		}

	}
	else
	{
		cerr << "Couldn't open Language file." << endl;
	}
}

void downloadTimeZone()
{
	ifstream ifile("timezones.txt");
	if (ifile.is_open()) {
		while (!ifile.eof())
		{
			string line;
			CommonInfo newTimezone;
			getline(ifile, line);
			vector<string> data = explode(line, '/');
			if (data.size() >= 2) {
				newTimezone.setNum(data[0]);
				newTimezone.setName(data[1]);
				timezoneList.push_back(newTimezone);
			}
		}
	}
	else
	{
		cerr << "Couldn't open Language file." << endl;
	}
}


// edited part 2
void getValueFromFile(string fileName)
{
	if (checkFile(fileName))
	{
		// open file
		ifstream ifile("Setting.txt", ios_base::app);

		// check if file is open
		if (ifile.fail())
		{
			cout << "CAN'T OPEN FILE" << endl;
		}
		else
		{
			ifile.seekg(0, ios::end);	// put ptr to the end of file
			int value = ifile.tellg();	// return value of position that appropriate with size of file 
			if (value != 0)
			{
				// if file has data --> put ptr to begin() for reading
				ifile.seekg(0, ios::beg);
				int val = ifile.tellg();
				while (!ifile.eof())
				{
					string line;
					getline(ifile, line);

					if (line == "")
					{
						break;
					}

					// each line is all info for one user
					vector<string> data = explode(line, ';');

					// data will have 4 sections: common, display, sound, general
					vector<string> common = explodeInfo(data[0], ',');
					vector<string> display = explodeInfo(data[1], ',');
					vector<string> sound = explodeInfo(data[2], ',');
					vector<string> general = explodeInfo(data[3], ',');

					Car newCar;

					// set common info
					newCar.setCarName(common[0]);
					newCar.setEmail(common[1]);
					newCar.setPerKey(common[2]);
					newCar.setODO(stoi(common[3]));
					newCar.setSer(stoi(common[4]));

					// set display info
					newCar.getDisplay()->set_light_level(stoi(display[0]));
					newCar.getDisplay()->set_screen_light_level(stoi(display[1]));
					newCar.getDisplay()->set_taplo_light_level(stoi(display[2]));

					// set sound info
					newCar.getSound()->set_call_level(stoi(sound[0]));
					newCar.getSound()->set_media_level(stoi(sound[1]));
					newCar.getSound()->set_navi_level(stoi(sound[2]));
					newCar.getSound()->set_notification_level(stoi(sound[3]));

					// set general info
					newCar.getGeneral()->set_timeZone(general[0]);
					newCar.getGeneral()->set_language(general[1]);


					// add new car to list
					bTree->insert(newCar);
				}
			}

			cout << "The size of list car is: " << bTree->index << "\n\n";
			ifile.close();
		}
	}
	else
	{
		cout << "File broken" << endl;
	}
}

// checked part 2 
void saveFile(list<Car> listC)
{
	if (bTree->index == 0)
	{
		cout << "No car has been saved" << endl;
	}
	else
	{
		if (checkFile("Setting.txt"))
		{
			// open file
			ofstream ofile("Setting.txt", ios_base::trunc);

			// add element to list
			bTree->addEleToSave();

			try
			{
				if (ofile.is_open())
				{
					list<Car>::iterator it = listCar.begin();
					for (it ; it != listCar.end() ; it++)
					{
						ofile << "Common: " << it->getCarName() << ", " << it->getEmail()
							<< ", " << it->getPersonalKey() << ", " << it->getODO() << ", "
							<< it->getServiceRemind() << "; "
							<< "Display: " << it->getDisplay()->get_light_level() << ", "
							<< it->getDisplay()->get_screen_light_level() << ", "
							<< it->getDisplay()->get_taplo_light_level() << "; "
							<< "Sound: " << it->getSound()->get_call_level() << ", "
							<< it->getSound()->get_media_level() << ", "
							<< it->getSound()->get_navi_level() << ", "
							<< it->getSound()->get_notification_level() << "; "
							<< "General: " << it->getGeneral()->get_timeZone() << ", "
							<< it->getGeneral()->get_language() << endl;
					}
					
				}
				else
				{
					throw exception();
				}
			}
			catch (const std::exception&)
			{
				cout << "Couldn't open file" << endl;
			}
			
		
		}
	}
	
}

// edited
bool checkFile(string path)
{
	ifstream file(path);
	return file.good();
}

// checked
// Đây là phần hiển thị thông tin lựa chọn cài đặt MH-2
void NhapThongTinCaiDat()
{
	bool check = false;
	do {
		system("cls");
		string selection;
		check = false;
		cout << "----- SELECT MENU -----" << endl;
		cout << "1. Display setting" << endl;
		cout << "2. Sound setting" << endl;
		cout << "3. General setting" << endl;
		cout << "0. Exit" << endl;
		cout << "Your selection: ";
		cin >> selection;
		if ((selection >= "a" && selection <= "z") || (selection >= "A" && selection <= "Z")) {
			cout << "You can't type character. Please type again." << endl;
			check = true;			// điều kiện để tiếp tục vòng lặp
			system("pause");
			continue;
		}
		int sele = stoi(selection);
		switch (sele)
		{
		case 1: {
			NhapThongTinCaiDat_Display();
			break;
		}
		case 2: {
			NhapThongTinCaiDat_Sound();
			break;
		}
		case 3: {
			NhapThongTinCaiDat_General();
			break;
		}
		case 0: {
			break;
		}
		default: {
			cout << "You type wrong choice please select again." << endl;
			check = true;
			system("pause");
			//break;
		}
		}
	} while (check == true);
}

// checked
void XuatThongTinCaiDat()
{
	bool check = false;
	do {
		system("cls");
		string selection;
		check = false;
		cout << "----- SELECT MENU -----" << endl;
		cout << "1. Print Display setting infomation" << endl;
		cout << "2. Print Sound setting infomation" << endl;
		cout << "3. Print General setting infomation" << endl;
		cout << "4. Print all setting infomation" << endl;
		cout << "0. Exit" << endl;
		cout << "Your selection: ";
		cin >> selection;
		if ((selection >= "a" && selection <= "z") || (selection >= "A" && selection <= "Z")) {
			cout << "You can't type character. Please type again." << endl;
			check = true;			// điều kiện để tiếp tục vòng lặp
			system("pause");
			continue;
		}
		int sele = stoi(selection);
		switch (sele)
		{
		case 1: {
			XuatThongTinCaiDat_Display();
			break;
		}
		case 2: {
			XuatThongTinCaiDat_Sound();
			break;
		}
		case 3: {
			XuatThongTinCaiDat_General();
			break;
		}
		case 4: {
			XuatTatCaThongTinCaiDat();
			break;
		}
		case 0: {
			break;
		}
		default: {
			cout << "You type wrong choice please select again." << endl;
			check = true;
			system("pause");
			//break;
		}
		}
	} while (check == true);
}

// checked part 2																																					
void XuatThongTinCaiDat_Sound()
{

	if (bTree->index != 0)
	{
		system("cls");
		cout << "--- SOUND SETTING ---" << endl;
		cout << left;
		cout << setw(5) << "" << setw(20) << "Owner name" << setw(25) << "Email" << setw(15) << "Key number"
			<< setw(15) << "ODO number" << setw(25) << "Remind service (km)" << endl
			<< setw(5) << "" << setw(10) << "Media" << setw(10) << "Call" << setw(15) << "Navigation"
			<< setw(15) << "Notification" << endl;
		bTree->leftNodeRight(2);
	}
	else
	{
		cout << "\n\t--->There's still have no car in data" << endl;
	}
}

// checked part 2
void XuatThongTinCaiDat_General()
{
	if (bTree->index != 0)
	{
		system("cls");
		cout << "--- GENERAL SETTING ---" << endl;
		cout << left;
		cout << setw(5) << "" << setw(20) << "Owner name" << setw(25) << "Email" << setw(15) << "Key number"
			<< setw(15) << "ODO number" << setw(25) << "Remind service (km)" << endl
			<< setw(5) << "" << setw(20) << "Timezone" << setw(15) << "Language" << endl;
		bTree->leftNodeRight(3);
	}
	else
	{
		cout << "\n\t--->There's still have no car in data" << endl;
	}
}

// checked part 2
void XuatThongTinCaiDat_Display()
{

	if (bTree->index != 0)
	{
		system("cls");
		cout << "--- DISPLAY SETTING ---" << endl;
		cout << left;
		cout << setw(5) << "" << setw(20) << "Owner name" << setw(25) << "Email" << setw(15) << "Key number"
			<< setw(15) << "ODO number" << setw(25) << "Remind service (km)" << endl
			<< setw(5)<< "" << setw(20) << "Light level"
			<< setw(25) << "Screen light level" << setw(20) << "Taplo light level" << endl;
		bTree->leftNodeRight(1);
	}
	else
	{
		cout << "\n\t--->There's still have no car in data" << endl;
	}
}

// checked part 2
void XuatTatCaThongTinCaiDat()
{
	system("cls");

	// Ask user choose the way to display info 
	string selection = "0";		// for checking if user enter the character or not
	int checkCar = 0;
	string info;
	cout << "PLEASE CHOOSE PRINT INFOMATION FOLLOWING"
		<< "\n1. Personal key"
		<< "\n2. Car name" << endl;

	// check if user inputed correct choice
	do
	{
		checkCar = 0;
		cout << "(1 or 2)? ";
		cin >> selection;
		if (!(selection == "1" || selection == "2"))
		{
			cout << "\nYou must type 1 or 2" << endl;
			checkCar = 1;
			continue;
		}

	} while (checkCar == 1);

	// base on option that user inputed
	// the following section is inputed the infomation
	if (selection == "1")
	{
		cout << "Please enter your Key: ";
	}
	else
	{
		cout << "Please enter your car name: ";
	}
	cin.ignore();
	getline(cin, info);
	
	// display infomation
	system("cls");
	cout << "--- ALL INFOMATION SETTING ---" << endl;
	cout << left;
	if (selection == "1")
	{
		bTree->searchByKey(info);
	}
	else
	{
		bTree->searchByName(info);
	}

}

// checked part 2
void NhapThongTinCaiDat_Sound()
{
	string ans;
	do
	{
		system("cls");
		cout << "--- INPUT SOUND SETTING ---" << endl;
		cout << "Car index: " << bTree->index + 1 << endl;
		Car newCar;
		newCar.nhapThongTin();
		Node* searchNode = NULL;
		searchNode = bTree->search(newCar.getPersonalKey());
		if (searchNode == NULL) {
			cout << "This is a new car, data will be appended to your list." << endl;
			newCar.getSound()->nhapThongTin();
			bTree->insert(newCar);
		}
		else
		{
			cout << "The car has already existed in your list, data will be overwritten." << endl;
			newCar.getSound()->nhapThongTin();
			searchNode->data.updateCar(&newCar, 2);
		}
		cout << "Will you input for Car " << bTree->index + 1 << "(y/n)? ";
		cin >> ans;
		while (ans != "y" && ans != "n")
		{
			cout << "You type the wrong choice. Please type again." << endl;
			cout << "Will you input for Car " << bTree->index + 1 << "(y/n)? ";
			cin >> ans;
		}
	} while (ans == "y");
}

// checked part 2
void NhapThongTinCaiDat_Display()
{
	string ans = "n";

	do
	{
		system("cls");
		cout << "--- INPUT DISPLAY SETTING ---" << endl;
		cout << "Car index: " << bTree->index + 1 << endl;
		Car newCar;
		newCar.nhapThongTin();
		Node* searchNode = NULL;
		searchNode = bTree->search(newCar.getPersonalKey());
		if (searchNode == NULL) {
			cout << "---> This is a new car, data will be appended to your list." << endl;
			newCar.getDisplay()->nhapThongTin();			// Tiến hành nhập thông tin display vào thông tin xe mới
			bTree->insert(newCar);
		}
		else
		{
			cout << "---> The car has already existed in your list, data will be overwritten." << endl;
			newCar.getDisplay()->nhapThongTin();
			searchNode->data.updateCar(&newCar, 1);			// Tiến hành update thông tin display vào listcar
		}
		cout << "Will you input for Car " << bTree->index + 1 << "(y/n)? ";
		cin >> ans;
		while (ans != "y" && ans != "n")
		{
			cout << "You type the wrong choice. Please type again." << endl;
			cout << "Will you input for Car " << bTree->index + 1 << "(y/n)? ";
			cin >> ans;
		}

	} while (ans == "y");

		
}

// checked part 2
void NhapThongTinCaiDat_General()
{
	string ans;
	do
	{
		system("cls");
		cout << "--- INPUT GENERAL SETTING ---" << endl;
		cout << "Car index: " << bTree->index + 1 << endl;
		Car newCar;
		newCar.nhapThongTin();
		Node* searchNode = NULL;
		searchNode = bTree->search(newCar.getPersonalKey());
		if (searchNode == NULL) {
			cout << "---> This is a new car, data will be appended to your list." << endl;
			system("pause");
			newCar.getGeneral()->nhapThongTin();
			bTree->insert(newCar);
		}
		else
		{
			cout << "---> The car has already existed in your list, data will be overwritten." << endl;
			system("pause");
			newCar.getGeneral()->nhapThongTin();
			searchNode->data.updateCar(&newCar, 3);
		}
		cout << "Will you input for Car " << bTree->index + 1 << "(y/n)? ";
		cin >> ans;
		while (ans != "y" && ans != "n")
		{
			cout << "You type the wrong choice. Please type again." << endl;
			cout << "Will you input for Car " << bTree->index + 1 << "(y/n)? ";
			cin >> ans;
		}
	} while (ans == "y");
}

int menu()
{
	string selection;

	cout << "--- SELECT MENU ---" << endl;
	cout << "1. Input setting infomation" << endl;
	cout << "2. Print setting infomation" << endl;
	cout << "3. Exit" << endl;
	cout << "Your selection: ";
	cin >> selection;
	while (selection != "1" && selection != "2" && selection != "3")
	{
		cout << "You type a wrong choice. Please type again!" << endl;
		cout << "Your selection: ";
		cin >> selection;
	}
	return stoi(selection);
}


