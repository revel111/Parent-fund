#include "storage.h"
#include "header.h"


int main() {
	setlocale(LC_ALL,"RUS");
	Storage data;
	data.readSection();
	data.readFamily();
	data.readSpecialist();

	int ch = 0;
	int ch1 = 0;
	int ch2 = 0;

	do {
		cout << "Press 1 if you want to enter as administrator \n";
		cout << "Press 2 if you want to enter as user \n";
		cout << "Press 0 if you want to exit \n";
		cin >> ch1;
		switch (ch1)
		{
		case 1:
			do {
				cout << "---------You enter as administrator--------- \n";
				cout << " \n";
				cout << "Enter 1 if you want to add section \n";
				cout << "Enter 2 if you want to add specialist \n";
				cout << "Enter 3 if you want to add family \n";
				cout << "Enter 4 if you want to show sections \n";
				cout << "Enter 5 if you want to show specialists \n";
				cout << "Enter 6 if you want to show families \n";
				cout << "Enter 7 if you want to delete section \n";
				cout << "Enter 8 if you want to delete specialist \n";
				cout << "Enter 9 if you want to delete families \n";
				cout << "Enter 0 if you want to exit \n";
				cin >> ch;

				if (ch == 1) {
					Section temp;
					temp = Section::create();
					data.addSection(temp);
					data.saveSection();
				}
				else if (ch == 2) {
					Specialist temp;
					temp = Specialist::create();
					data.addSpecialist(temp);
					data.saveSpecialist();
				}
				else if (ch == 3) {
					Family temp;
					temp = Family::create();
					data.addFamily(temp);
					data.saveFamily();
				}
				else if (ch == 4) {
					map<int, Section> sections=data.getSection();
					map<int, Section>::iterator it = sections.begin();
					while (it!=sections.end()) {
						it->second.print();
						it++;
					}
				}
				else if (ch == 5) {
					map<int, Specialist> specialists = data.getSpecialist();
					map<int, Specialist>::iterator it = specialists.begin();
					while (it!= specialists.end()) {
						it->second.print();
						it++;
					}
				}
				else if (ch == 6) {
					map<int, Family> families = data.getFamily();
					map<int, Family>::iterator it = families.begin();
					while (it != families.end()) {
						it->second.print();
						it++;
					}
				}
				else if (ch == 7) {
					map<int, Section> sections = data.getSection();
					map<int, Section>::iterator it = sections.begin();
					while (it != sections.end()) {
						it->second.print();
						it++;
					}

					string temp_name;
					cin.ignore();
					cout << "Enter the name of section which you want to delete \n";
					getline(cin, temp_name);

					it = sections.begin();
					while (it != sections.end()) {
						if (temp_name == it->second.getName()) {
							data.removeSection(it->second);
							break;
						}
						it++;
					}
					data.saveSection();
				}
				else if (ch == 8) {
					map<int, Specialist> specialists = data.getSpecialist();
					map<int, Specialist>::iterator it = specialists.begin();
					while (it != specialists.end()) {
						it->second.print();
						it++;
					}

					string temp_name;
					cin.ignore();
					cout << "Enter the surname of specialist which you want to delete \n";
					getline(cin, temp_name);

					it = specialists.begin();
					while (it != specialists.end()) {
						if (temp_name == it->second.getSurname()) {
							data.removeSpecialist(it->second);
							break;
						}
						it++;
					}
					data.saveSpecialist();
				}
				else if (ch == 9) {
					map<int, Family> families = data.getFamily();
					map<int, Family>::iterator it = families.begin();
					while (it != families.end()) {
						it->second.print();
						it++;
					}

					string temp_name;
					cout << "Enter the surname of family which you want to delete \n";
					getline(cin, temp_name);

					it = families.begin();
					while (it != families.end()) {
						if (temp_name == it->second.getSurname()) {
							data.removeFamily(it->second);
							break;
						}
						it++;
					}
					data.saveFamily();
				}
				else  {
					break;
				}
				break;
		case 2:
			do {
				cout << "---------You enter as Specialist--------- \n";
				cout << " \n";
				cout << "Enter 1 if you want to show sections \n";
				cout << "Enter 2 if you want to show families \n";
				cout << "Enter 3 if you want to add family \n";
				cout << "Enter 4 if you want to delete families \n";
				cout << "Enter 0 if you want to exit \n";
				cin >> ch2;
				if (ch2 == 1) {
					map<int, Section> sections = data.getSection();
					map<int, Section>::iterator it = sections.begin();
					while (it != sections.end()) {
						it->second.print();
						it++;
					}
				}
				else if (ch2 == 2) {
					map<int, Family> families = data.getFamily();
					map<int, Family>::iterator it = families.begin();
					while (it != families.end()) {
						it->second.print();
						it++;
					}
				}
				else if (ch2 == 3) {
					Family temp;
					temp = Family::create();
					data.addFamily(temp);
					data.saveFamily();
				}
				else if (ch2 == 4) {
					map<int, Family> families = data.getFamily();
					map<int, Family>::iterator it = families.begin();
					while (it != families.end()) {
						it->second.print();
						it++;
					}

					string temp_name;
					cout << "Enter the name of family which you want to delete \n";
					getline(cin, temp_name);

					it = families.begin();
					while (it != families.end()) {
						if (temp_name == it->second.getSurname()) {
							data.removeFamily(it->second);
							break;
						}
						it++;
					}
					data.saveFamily();
				}
				else {
					break;
				}
				break;
			} while (ch2 != 0);
			} while (ch != 0);
		}
	}
	while (ch1 != 0);
	system("pause");
	return 0;
}