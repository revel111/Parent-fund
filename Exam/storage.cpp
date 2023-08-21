#include "storage.h"


Storage::Storage() {
	for (int i = 0; i < 3; i++) {
		lastId_Table.push_back(0);
	}
}

map<int, Family> Storage::getFamily() {
	return families;
}

map<int, Section> Storage::getSection() {
	return sections;
}

map<int, Specialist> Storage::getSpecialist() {
	return specialists;
}

int Storage::getNextID(int numberTable)
{
	if (numberTable > 2 || numberTable < 0) {
		throw "Number table more or less count table";
	}
	return lastId_Table[numberTable]++;
}

void Storage::addFamily(Family obj) {
	if (obj.getSurname().empty()) {
		system("cls");
		cout << "Incorrect input \n";
		system("pause");
		return;
	}
	bool flag = false;
	int nextID = 0;
	int number = 0;
	if (families.size() == 0) {
		nextID = getNextID(number);
		obj.ID = nextID;
		families.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
		return;
	}

	map <int, Family>::iterator it = families.begin();
	while (it != families.end()) {
		if (it->second == obj) {
			flag = true;
			cout << "Families already exist \n";
		}
		it++;
	}
	nextID = getNextID(number);
	obj.ID = nextID;
	it = families.begin();
	families.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
}

void Storage::removeFamily(Family obj) {
	if (obj.getSurname().empty() || obj.getReason().empty()) {
		system("cls");
		cout << "Incorrect input \n";
		system("pause");
		return;
	}

	map <int, Family>::iterator it = families.begin();
	while (it != families.end()) {
		if (it->second == obj) {
			families.erase(it);
			return;
		}
		it++;
	}
	cout << "No file \n";
}

void Storage::addSection(Section obj) {
	if (obj.getName().empty() || obj.getSpeciality().empty() || obj.getRegion().empty()) {
		system("cls");
		cout << "Incorrect input \n";
		system("pause");
		return;
	}
	bool flag = false;
	int nextID = 0;
	int number = 0;
	if (sections.size() == 0) {
		nextID = getNextID(number);
		obj.ID = nextID;
		sections.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
		return;
	}

	map <int, Section>::iterator it = sections.begin();
	while (it != sections.end()) {
		if (it->second == obj) {
			flag = true;
			cout << "Sections already exist \n";
		}
		it++;
	}
	nextID = getNextID(number);
	obj.ID = nextID;
	it = sections.begin();
	sections.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
}

void Storage::removeSection(Section obj) {
	if (obj.getName().empty()) {
		system("cls");
		cout << "Incorrect input \n";
		system("pause");
		return;
	}

	map <int, Section>::iterator it = sections.begin();
	while (it != sections.end()) {
		if (it->second == obj) {
			sections.erase(it);
			return;
		}
		it++;
	}
	cout << "Section not found \n";
}

void Storage::addSpecialist(Specialist obj) {
	if (obj.getName().empty() || obj.getSurname().empty() || obj.getDirection().empty()) {
		system("cls");
		cout << "Incorrect input \n";
		system("pause");
		return;
	}
	bool flag = false;
	int nextID = 0;
	int number = 0;
	if (specialists.size() == 0) {
		nextID = getNextID(number);
		obj.ID = nextID;
		specialists.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
		return;
	}

	map <int, Specialist>::iterator it = specialists.begin();
	while (it != specialists.end()) {
		if (it->second == obj) {
			flag = true;
			cout << "Specialists already exist \n";
		}
		it++;
	}
	nextID = getNextID(number);
	obj.ID = nextID;
	it = specialists.begin();
	specialists.emplace(piecewise_construct, forward_as_tuple(nextID), forward_as_tuple(obj));
}

void Storage::removeSpecialist(Specialist obj) {
	if (obj.getSurname().empty()) {
		system("cls");
		cout << "Incorrect input \n";
		system("pause");
		return;
	}

	map <int, Specialist>::iterator it = specialists.begin();
	while (it != specialists.end()) {
		if (it->second == obj) {
			specialists.erase(it);
			return;
		}
		it++;
	}
	cout << "Specialist not found \n";
}

void Storage::saveSection() {
	FILE* file;
	fopen_s(&file, "sections.bin", "wb");
	if (file == NULL)
	{
		cout << "No file \n";
		return;
	}

	int secSize = sections.size();
	fwrite(&secSize, sizeof(secSize), 1, file);
	if (sections.size() != 0)
	{
		map<int, Section>::iterator itSec = sections.begin();
		while (itSec != sections.end()) {

			int ID = itSec->first;
			fwrite(&ID, sizeof(ID), 1, file);

			char* buffer = nullptr;
			int size = 1;

			size = itSec->second.getName().size();
			buffer = new char[size + 1]{};
			strcpy_s(buffer, sizeof(char) * size + 1, itSec->second.getName().c_str());
			fwrite(&size, sizeof(int), 1, file);
			fwrite(&*buffer, sizeof(char) * size, 1, file);
			delete[]buffer;

			size = itSec->second.getSpeciality().size();
			buffer = new char[size + 1]{};
			strcpy_s(buffer, sizeof(char) * size + 1, itSec->second.getSpeciality().c_str());
			fwrite(&size, sizeof(int), 1, file);
			fwrite(&*buffer, sizeof(char) * size, 1, file);
			delete[]buffer;

			size = itSec->second.getRegion().size();
			buffer = new char[size + 1]{};
			strcpy_s(buffer, sizeof(char) * size + 1, itSec->second.getRegion().c_str());
			fwrite(&size, sizeof(int), 1, file);
			fwrite(&*buffer, sizeof(char) * size, 1, file);
			delete[]buffer;

			vector <int> specialists = itSec->second.getIdSpecialists();
			int sizeSpecialists = specialists.size();

			fwrite(&sizeSpecialists, sizeof(int), 1, file);
			if (specialists.size() != 0)
			{
				for (int i = 0; i < sizeSpecialists; i++)
				{
					fwrite(&specialists[i], sizeof(int), 1, file);
				}
			}

			vector <int> families = itSec->second.getIdFamilies();
			int sizeFamilies = families.size();

			fwrite(&sizeFamilies, sizeof(int), 1, file);
			if (sizeFamilies != 0)
			{
				for (int i = 0; i < sizeFamilies; i++)
				{
					fwrite(&families[i], sizeof(int), 1, file);
				}
			}

			itSec++;
		}
	}
	fclose(file);
}

void Storage::readSection() {

	FILE* file;
	fopen_s(&file, "sections.bin", "rb");
	if (file == NULL)
	{
		cout << "No file \n";
		return;
	}

	int secSize = 0;
	fread(&secSize, sizeof(secSize), 1, file);
	for (int i = 0; i < secSize; i++)
	{

		string name;
		string speciality;
		string region;
		vector <int> specialists;
		vector <int> families;
		int ID = 0;
		fread(&ID, sizeof(ID), 1, file);



		int size = 1;
		char* buffer = nullptr;


		fread(&size, sizeof(int), 1, file);
		buffer = new char[size + 1]{};
		fread(&*buffer, sizeof(char) * size, 1, file);
		name = buffer;
		delete[]buffer;

		fread(&size, sizeof(int), 1, file);
		buffer = new char[size + 1]{};
		fread(&*buffer, sizeof(char) * size, 1, file);
		speciality = buffer;
		delete[]buffer;

		fread(&size, sizeof(int), 1, file);
		buffer = new char[size + 1]{};
		fread(&*buffer, sizeof(char) * size, 1, file);
		region = buffer;
		delete[]buffer;

		int sizeSpecialists = 0;
		fread(&sizeSpecialists, sizeof(int), 1, file);
		if (sizeSpecialists != 0)
		{
			for (int i = 0; i < sizeSpecialists; i++)
			{
				int data;
				fread(&specialists[i], sizeof(int), 1, file);
				families.push_back(data);
			}
		}

		int sizeFamilies = 0;
		fread(&sizeFamilies, sizeof(int), 1, file);
		if (sizeFamilies != 0)
		{
			for (int i = 0; i < sizeFamilies; i++)
			{
				int data;
				fread(&data, sizeof(int), 1, file);
				families.push_back(data);
			}
		}
		Section temp(name, speciality, region, specialists, families);
		temp.ID = ID;
		sections.emplace(piecewise_construct, forward_as_tuple(ID), forward_as_tuple(temp));
	}
	fclose(file);
}

void Storage::saveFamily() {
	FILE* file;
	fopen_s(&file, "families.bin", "wb");
	if (file == NULL)
	{
		cout << "No file \n";
		return;
	}

	int famSize = families.size();
	fwrite(&famSize, sizeof(famSize), 1, file);
	if (families.size() != 0)
	{
		map<int, Family>::iterator itFam = families.begin();
		while (itFam != families.end()) {

			int ID = itFam->first;
			fwrite(&ID, sizeof(ID), 1, file);


			char* buffer = nullptr;
			int size = 1;

			size = itFam->second.getSurname().size();
			buffer = new char[size + 1]{};
			strcpy_s(buffer, sizeof(char) * size + 1, itFam->second.getSurname().c_str());
			fwrite(&size, sizeof(int), 1, file);
			fwrite(&*buffer, sizeof(char) * size, 1, file);
			delete[]buffer;

			float payout = itFam->second.getPayout();
			fwrite(&payout, sizeof(payout), 1, file);

			size = itFam->second.getReason().size();
			buffer = new char[size + 1]{};
			strcpy_s(buffer, sizeof(char) * size + 1, itFam->second.getReason().c_str());
			fwrite(&size, sizeof(int), 1, file);
			fwrite(&*buffer, sizeof(char) * size, 1, file);
			delete[]buffer;

			itFam++;
		}
	}
	fclose(file);
}

void Storage::readFamily() {
	FILE* file;
	fopen_s(&file, "families.bin", "wb");
	if (file == NULL)
	{
		cout << "No file \n";
		return;
	}

	int famSize = families.size();
	fwrite(&famSize, sizeof(famSize), 1, file);
	if (families.size() != 0)
	{
		map<int, Family>::iterator itFam = families.begin();
		while (itFam != families.end()) {

			int ID = itFam->first;
			fwrite(&ID, sizeof(ID), 1, file);

			char* buffer = nullptr;
			int size = 1;

			size = itFam->second.getSurname().size();
			buffer = new char[size + 1]{};
			strcpy_s(buffer, sizeof(char) * size + 1, itFam->second.getSurname().c_str());
			fwrite(&size, sizeof(int), 1, file);
			fwrite(&*buffer, sizeof(char) * size, 1, file);
			delete[]buffer;

			float payout = itFam->second.getPayout();
			fwrite(&payout, sizeof(payout), 1, file);

			size = itFam->second.getReason().size();
			buffer = new char[size + 1]{};
			strcpy_s(buffer, sizeof(char) * size + 1, itFam->second.getReason().c_str());
			fwrite(&size, sizeof(int), 1, file);
			fwrite(&*buffer, sizeof(char) * size, 1, file);
			delete[]buffer;

			itFam++;
		}
	}
	fclose(file);
}

void Storage::saveSpecialist() {
	FILE* file;
	fopen_s(&file, "specialists.bin", "wb");
	if (file == NULL)
	{
		cout << "No file \n";
		return;
	}

	int specSize = specialists.size();
	fwrite(&specSize, sizeof(specSize), 1, file);
	if (specialists.size() != 0)
	{
		map<int, Specialist>::iterator itSpec = specialists.begin();
		while (itSpec != specialists.end()) {

			int ID = itSpec->first;
			fwrite(&ID, sizeof(ID), 1, file);

			char* buffer = nullptr;
			int size = 1;

			size = itSpec->second.getName().size();
			buffer = new char[size + 1]{};
			strcpy_s(buffer, sizeof(char) * size + 1, itSpec->second.getName().c_str());
			fwrite(&size, sizeof(int), 1, file);
			fwrite(&*buffer, sizeof(char) * size, 1, file);
			delete[]buffer;

			size = itSpec->second.getSurname().size();
			buffer = new char[size + 1]{};
			strcpy_s(buffer, sizeof(char) * size + 1, itSpec->second.getSurname().c_str());
			fwrite(&size, sizeof(int), 1, file);
			fwrite(&*buffer, sizeof(char) * size, 1, file);
			delete[]buffer;

			size = itSpec->second.getDirection().size();
			buffer = new char[size + 1]{};
			strcpy_s(buffer, sizeof(char) * size + 1, itSpec->second.getDirection().c_str());
			fwrite(&size, sizeof(int), 1, file);
			fwrite(&*buffer, sizeof(char) * size, 1, file);
			delete[]buffer;

			int age = itSpec->second.getAge();
			fwrite(&age, sizeof(age), 1, file);

			itSpec++;
		}
	}
	fclose(file);
}

void Storage::readSpecialist() {
	FILE* file;
	fopen_s(&file, "specialists.bin", "rb");
	if (file == NULL)
	{
		cout << "No file \n";
		return;
	}

	int specSize = 0;
	fread(&specSize, sizeof(specSize), 1, file);
	for (int i = 0; i < specSize; i++)
	{
		string name;
		string surname;
		string direction;
		int age;

		int ID = 0;
		fread(&ID, sizeof(ID), 1, file);

		int size = 1;
		char* buffer = nullptr;

		fread(&size, sizeof(int), 1, file);
		buffer = new char[size + 1]{};
		fread(&*buffer, sizeof(char) * size, 1, file);
		name = buffer;
		delete[]buffer;

		fread(&size, sizeof(int), 1, file);
		buffer = new char[size + 1]{};
		fread(&*buffer, sizeof(char) * size, 1, file);
		surname = buffer;
		delete[]buffer;


		fread(&age, sizeof(age), 1, file);

		fread(&*buffer, sizeof(char) * size, 1, file);
		direction = buffer;
		delete[]buffer;

		Specialist temp(name, surname, direction, age);
		temp.ID = ID;
		specialists.emplace(piecewise_construct, forward_as_tuple(ID), forward_as_tuple(temp));
	}
	fclose(file);
}