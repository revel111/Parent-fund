#pragma once
#include "header.h"

class Section  {
protected:
	string name;
	string speciality;
	string region;
	int ID;
	vector <int> specialists;
	vector <int> families;
	friend class Storage;

public:
	string getName();

	string getSpeciality();

	string getRegion();

	vector <int> getIdSpecialists();

	vector <int> getIdFamilies();

	int getID();

	Section(): name("-")
	{}

	Section(string name, string speciality, string region, vector <int> specialists, vector <int> families) : name(name), speciality(speciality), region(region), specialists(specialists), families(families)
	{}

	Section(const Section& obj);

	void setName(string p_name);

	void setSpeciality(string p_speciality);

	void setRegion(string p_region);

	void AddSpecialist(int id);

	void AddFamily(int id);

	static Section create();

	void print();

	bool operator== (Section f1);
}; 