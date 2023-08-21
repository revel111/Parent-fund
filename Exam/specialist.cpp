#include "specialist.h"

string Specialist::getName() {
	return name;
}

string Specialist::getSurname() {
	return surname;
}

string Specialist::getDirection() {
	return direction;
}

int Specialist::getAge() {
	return age;
}

int Specialist::getID() {
	return ID;
}

void Specialist::setAge(int p_age) {
	age = p_age;
}

void Specialist::setName(string p_name) {
	name = p_name;
}

void Specialist::setSurname(string p_surname) {
	surname = p_surname;
}

void Specialist::setDirection(string p_direction) {
	direction = p_direction;
}

Specialist::Specialist(const Specialist& obj) {
	name = obj.name;
	surname = obj.surname;
	direction = obj.direction;
	age = obj.age;
}

Specialist Specialist::create() {
	string name;
	string surname;
	string direction;
	int age;
	cin.ignore();
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter surname: ";
	getline(cin, surname);
	cout << "Enter direction: ";
	getline(cin, direction);
	cout << "Enter age: ";
	cin >> age;
	return Specialist(name, surname, direction, age);
}

void Specialist::print() {
	cout << "Name: " << name << "\n";
	cout << "Surname: " << surname << "\n";
	cout << "Direction: " << direction << "\n";
	cout << "Age: " << age << "\n";
	cout << "============ \n";
}

bool Specialist::operator== (Specialist f1) {
	if (f1.getName() == name && f1.getSurname() == surname) {
		return true;
	}
	else {
		return false;
	}
}