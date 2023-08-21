#pragma once
#include "Header.h"

class Department {
public:
	string getName() {
		return name;
	}
	string getAmount_sections() {
		return name;
	}
	string getMatter() {
		return matter;
	}
	vector <int> getIdSections() {
		return sections;
	}
	
	Department(Department& other) = delete;
	void operator=(const Department&) = delete;

	static Department* GetInstance()
	{
		if (department == nullptr) {
			department = new Department();
		}
		return department;
	}

	Department(): name("-")
	{}
	Department(string name, string amount_sections, string matter, vector <int> sections): name(name), amount_sections(amount_sections), matter(matter), sections(sections)
	{}

	void AddSection(int id) {
		sections.push_back(id);
	}

	void setName(string p_name){
		name = p_name;
	}
	void setAmount_sections(string p_sections) {
		amount_sections = p_sections;
	}
	void setMatter(string p_matter) {
		matter = p_matter;
	}
	
	void print() {
		cout << "Name: " << name << "\n";
		cout << "Amount of sections: " << amount_sections << "\n";
		cout << "Matter: " << matter << "\n";
	}
protected:
	string name;
	string amount_sections;
	string matter;
	vector <int> sections; //id секций

	static Department* department;
};