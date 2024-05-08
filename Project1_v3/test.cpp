//#include <iostream>
//#include <vector>
//#include <sstream>
//#include "General.h"
//#include "CommonInfo.h"
//#include <string>
//
//using namespace std;
//
//vector<CommonInfo> languageList;
//vector<CommonInfo> timezoneList;
//
//
//const vector<string> explodeInfo(const string& s, const char& c) {
//	string buff{ "" };
//	vector<string> v;				// Lưu từng thành phần được ngăn nhau bởi c
//
//	// because in general timezone have character ':" 
//	// so you need to delete at first when before it is common, sound, ... 
//	bool k = true;
//
//	for (auto n : s)
//	{
//		if (n != c) {
//			buff += n;
//			if (n == ':' && k ) {
//				// the structure is "Info:" so it's just title not the value for using
//				// set to default
//				buff = "";
//				k = !k;
//			}
//		}
//		else if (n == c && buff != "")
//		{
//			// delete the character ' ' for at first
//			if (buff[0] == ' ') {
//				buff.erase(buff.begin());
//			}
//			v.push_back(buff);
//			buff = "";
//		}
//	}
//	if (buff != "")
//		v.push_back(buff);
//	return v;
//}
//
////int main() {
////	string s1 = "Common: linh, 19022001, doanlinh@gmail.com\n"
////		"Display: 3, 3, 4\n"
////		"Sound: 4, 4, 4, 4\n"
////		"General: (GMT:+07:00), Vietnamese\n";
////
////	vector<string> line;
////	line = explodeInfo(s1, '\n');
////
////	cout << "The info of index 1 is: " << endl;
////	cout << line[3];
////
////	vector<string> display;
////	display = explodeInfo(line[3], ',');
////
////	cout << "\n\nThe information of display value is: ";
////	for (size_t i = 0; i < display.size(); i++)
////	{
////		cout << display[i] << ' ';
////	}
////	cout << endl;
////
////	return 0;
////}
//
//
//// test vector
//#include <vector>
//
//int main() {
//
//	vector<int> it1;
//	vector<int> it2 = { 3, 4, 5 };
//
//	it1.insert(it1.end(), it2.begin(), it2.end());
//
//	for (size_t i = 0; i < it1.size(); i++)
//	{
//		cout << it1[i] << ' ';
//	}
//	cout << endl;
//
//	return 0;
//}