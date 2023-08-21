#include "section.h"

string Section::getName() {
	return name;
}

string Section::getSpeciality() {
	return speciality;
}

string Section::getRegion() {
	return region;
}

vector <int> Section::getIdSpecialists() {
	return specialists;
}

vector <int> Section::getIdFamilies() {
	return families;
}

int Section::getID() {
	return ID;
}

Section::Section(const Section& obj) {
	name = obj.name;
	speciality = obj.speciality;
	region = obj.region;
	specialists = obj.specialists;
	families = obj.families;
}


void Section::setName(string p_name) {
	name = p_name;
}

void Section::setSpeciality(string p_speciality) {
	speciality = p_speciality;
}

void Section::setRegion(string p_region) {
	region = p_region;
}

void Section::AddSpecialist(int id) {
	specialists.push_back(id);
}

void Section::AddFamily(int id) {
	families.push_back(id);
}

Section Section::create() {
	string name;
	string speciality;
	string region;
	vector <int> specialists;
	vector <int> families;
	cin.ignore();
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter speciality: ";
	getline(cin, speciality);
	cout << "Enter region: ";
	getline(cin, region);
	return Section(name, speciality, region, specialists, families);
}

void Section::print() {
	cout << "Name: " << name << "\n";
	cout << "Speciality: " << speciality << "\n";
	cout << "Region: " << region << "\n";
	cout << "============ \n";
}

bool Section::operator== (Section f1) {
	if (f1.getName() == name && f1.getSpeciality() == speciality) {
		return true;
	}
	else {
		return false;
	}
}