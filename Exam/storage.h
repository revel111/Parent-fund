#pragma once

#include "family.h"
#include "section.h"
#include "specialist.h"

class Storage {
protected:
	map<int, Family> families;
	map<int, Section> sections;
	map<int, Specialist> specialists;
	vector <int> lastId_Table;

public:
	Storage();

	map<int, Family> getFamily();

	map<int, Section> getSection();

	map<int, Specialist> getSpecialist();

	int getNextID(int numberTable);

	void addFamily(Family obj);

	void removeFamily(Family obj);

	void addSection(Section obj);

	void removeSection(Section obj);

	void addSpecialist(Specialist obj);

	void removeSpecialist(Specialist obj);

	void saveSection();

	void readSection();

	void saveFamily();

	void readFamily();

	void saveSpecialist();

	void readSpecialist();
};