#pragma once
#include "header.h"

class Family {
protected:
	string surname;
	float payout;
	string reason;
	int ID;
	friend class Storage;

public:
	string getSurname();

	float getPayout();

	string getReason();

	int getID();

	void setSurname(string p_surname);

	void setPayout(float p_payout);

	void setReason(string p_reason);

	Family() : surname("-")
	{};

	Family(string surname, float payout, string reason):  surname(surname), payout(payout), reason(reason)
	{}

	Family(const Family& obj);

	static Family create();

	void print();

	bool operator== (Family f1);
};