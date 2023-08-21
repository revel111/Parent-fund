#pragma once
#include "header.h"

class Specialist {
protected:
	string name;
	string surname;
	string direction;
	int age;
	int ID;
	friend class Storage;

public:
	string getName();

	string getSurname();

	string getDirection(); 

	int getAge();

	int getID();

	void setAge(int p_age);

	void setName(string p_name);

	void setSurname(string p_surname);

	void setDirection(string p_direction);

	Specialist(): age(-1)
	{}

	Specialist(string name, string surname, string direction, int age) : name(name), surname(surname), direction(direction),age(age)
	{}

	Specialist(const Specialist& obj);

	static Specialist create();

	void print();

	bool operator== (Specialist f1);
};