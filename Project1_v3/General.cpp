#include "General.h"
#include "CommonInfo.h"

using namespace std;

extern vector<CommonInfo> languageList;			// define extern that announce that this variable is existed but need to include header
extern vector<CommonInfo> timezoneList;


bool compareNum(CommonInfo& a, CommonInfo& b)
{
	return a.getNumber() < b.getNumber();
}

bool compareName(CommonInfo& a, CommonInfo& b)
{
	return a.getName() < b.getName();
}


General::General(string time, string lang) : Setting()
{
	set_timeZone(time);
	set_language(lang);
}

General::~General()
{
}

void General::nhapThongTin()
{
	// nhập thông tin của timezone
	string ans1;
	int size = timezoneList.size();
	do
	{
		system("cls");
		cout << "--- SELECT TIMEZONE DATA ---" << endl;
		for (int i = 0; i < size; ++i) {
			cout << i + 1 << ": ";
			timezoneList[i].printInfo();			// In ra thông tin timezone để lựa chọn
		}
		cout << "YOUR SELECTION: ";
		cin >> ans1;
		if (stoi(ans1) < 0 || stoi(ans1) > size) {
			cout << "You type wrong answer. Please answer again." << endl;
			system("pause");
		}
	} while (stoi(ans1) < 0 || stoi(ans1) > size);
	timeZone = timezoneList[stoi(ans1) - 1].getNumber();		// lưu biến timezone với thông số đã chọn
	// Do ta lưu múi giờ nên dùng getNumber

// nhập thông tin language
	string ans2;
	int size2 = languageList.size();
	do
	{
		system("cls");
		cout << "--- SELECT TIMEZONE DATA ---" << endl;
		for (int i = 0; i < size2; ++i) {
			languageList[i].printInfo();
		}
		cout << "YOUR SELECTION: ";
		cin >> ans2;
		if (stoi(ans2) < 0 || stoi(ans2) > size2) {
			cout << "You type wrong answer. Please answer again." << endl;
			system("pause");
		}
	} while (stoi(ans2) < 0 || stoi(ans2) > size);
	language = languageList[stoi(ans2) - 1].getName();
}

void General::xuatThongTin()
{
	cout << "\tTime zone: " << timeZone << endl;
	cout << "\tLanguage: " << language << endl;
}

string General::get_language() const
{
	return language;
}

string General::get_timeZone() const
{
	return timeZone;
}

void General::set_timeZone(const string data)
{
	bool check = false;
	for (size_t i = 0; i < timezoneList.size(); i++)
	{
		if (data == timezoneList[i].getNumber()) {
			timeZone = data;
			check = true;
			break;
		}
	}

	if (!check)
	{
		timeZone = "(GMT+07:00)";		// set the default value if you set the wrong number
	}
}

void General::set_language(const string data)
{
	bool check = false;
	for (size_t i = 0; i < languageList.size(); i++)
	{
		if (data == languageList[i].getName()) {
			language = data;
			check = true;
			break;
		}
	}

	if (!check)
	{
		language = "Vietnamese";
	}
}
