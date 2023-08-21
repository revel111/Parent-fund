#include "family.h"

string Family::getSurname() {
	return surname;
}
float Family::getPayout() {
	return payout;
}
string Family::getReason() {
	return reason;
}
int Family::getID() {
	return ID;
}

void Family::setSurname(string p_surname) {
	surname = p_surname;
}

void Family::setPayout(float p_payout) {
	payout = p_payout;
}

void Family::setReason(string p_reason) {
	reason = p_reason;
}

Family::Family(const Family& obj) {
	surname = obj.surname;
	payout = obj.payout;
	reason = obj.reason;
}

Family Family::create() {
	string surname;
	float payout;
	string reason;
	cin.ignore();
	cout << "Enter surname: ";
	getline(cin, surname);
	cout << "Enter payout: ";
	cin >> payout;
	cout << "Enter reason	: ";
	getline(cin, reason);
	cin.ignore();
	return Family(surname, payout, reason);
}

void Family::print() {
	cout << "Surname: " << surname << "\n";
	cout << "Payout: " << payout << "\n";
	cout << "Reason: " << reason << "\n";
	cout << "============ \n";
}

bool Family::operator== (Family f1) {
	if (f1.getSurname() == surname && f1.getReason() == reason) {
		return true;
	}
	else {
		return false;
	}
}