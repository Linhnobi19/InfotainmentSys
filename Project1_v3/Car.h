#pragma once
#include "Display.h"
#include "General.h"
#include "Setting.h"
#include "Sound.h"
#include <iostream>

using namespace std;
class Car : public Setting {
private://1 đối tượng car có 3 đối tượng sau
	Display* display;
	Sound* sound;
	General* general;
public:
	Car();// hàm tạo và hủy
	~Car();
	Display* getDisplay(); // các hàm get để lấy đối tượng và chỉnh sửa các đối tượng này
	Sound* getSound();
	General* getGeneral();
	void updateCar(Car* car, int option);// hàm update khi người dùng nhập xe đã tồn tại
};
