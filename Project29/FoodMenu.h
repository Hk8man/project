#pragma once
#include "UserCheck.h"
#define _CRT_SECURE_NO_WARNINGS

/*
int main() {
	// 현재 시각을 시스템 클럭에서 가져오기
	auto now = std::chrono::system_clock::now();

	// 시스템 클럭 시간을 시간_t로 변환
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

	// 시간_t를 로컬 시간으로 변환
	std::tm* localTime = std::localtime(&currentTime);

	// 현재 시각의 시간 부분을 int로 저장
	int currentHour = localTime->tm_hour;

	// 결과 출력
	std::cout << "Current hour: " << currentHour << std::endl;

	return 0;
}
*/

class Food { // Base class
public:
	string name;
	string location;

	Food(string name, string location) //Admin에서 food를 새롭게 추가할 경우
	{
		this->name = name;
		this->location = location;
	}
	virtual ~Food() {}

	//getter
	string getName() const { return this->name; }
	string getLocation() const { return this->location; }
	void virtual print()
	{
		cout << "Name : " << this->getName() << endl;
		cout << "Location : " << this->getLocation() << endl;
	}

	//setter
	void virtual setInfo(string name, string location)
	{
		this->name = name;
		this->location = location;
	}
};

class Baedalgeek : public Food // Derived class
{
private:
	int start_time;
	int end_time;
public:
	Baedalgeek(string name, string location, int start, int end)
		: Food(name, location)
	{
		this->start_time = start;
		this->end_time = end;
	}
	//getter
	int getS_Time() const { return this->start_time; }
	int getE_Time() const { return this->end_time; }
	void print() override
	{
		Food::print();
		cout << "Valid time : " << setfill('0') << setw(2) << getS_Time() << ":00 ~ "
			<< setfill('0') << setw(2) << getE_Time() << ":00" << endl;
	}

	//setter
	void setInfo(string name, string location, int start, int end)
	{
		Food::setInfo(name, location);
		this->start_time = start;
		this->end_time = end;
	}

	void time_checker()
	{
		
	}
};

class Hak_sik : public Food // Derived class
{
private:
	int start_time;
	int end_time;
	string type;

public:
	enum Specific {
		GENERAL_MENU = 1,
		SPECIFIC_MENU = 2
	};

	Hak_sik(string name, string location, Specific spec, int start, int end)
		: Food(name, location), type(cafeteriaToString(spec)), start_time(start), end_time(end) {}

	// getter
	int getS_Time() const { return this->start_time; }
	int getE_Time() const { return this->end_time; }
	string getType() const { return this->type; }
	void print() override {
		Food::print();
		cout << "Type : " << this->getType() << endl;
		cout << "Valid time : " << setfill('0') << setw(2) << getS_Time() << ":00 ~ "
			<< setfill('0') << setw(2) << getE_Time() << ":00" << endl;
	}

	// setter
	void setInfo(string name, Specific spec, int start, int end) {
		Food::setInfo(name, cafeteriaToString(spec));
		this->start_time = start;
		this->end_time = end;
	}

private:
	static string cafeteriaToString(Specific spec) {
		switch (spec) {
		case GENERAL_MENU: return "General_menu";
		case SPECIFIC_MENU: return "Specific_menu";
		default: return "unknown";
		}
	}
};

class Cafe : public Food
{
private:

public:
	Cafe(string name, string location)
		: Food(name, location)
	{}
	//getter

	void print() override
	{
		Food::print();

	}

	//setter
	void setInfo(string name, string location)
	{
		Food::setInfo(name, location);

	}
};