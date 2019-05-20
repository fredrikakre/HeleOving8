#pragma once
using namespace std;
#include "Car.h"
#include "std_lib_facilities.h"

enum class Campus { Glos, Dragvoll, Tunga };


class Meeting {
	int day, startTime, endTime;
	string subject;
	Campus location;
	const Person* leader;
	set<const Person*> participants;
	static set<const Meeting*> meetings;			// Static: Finnes bare ett "meetings"sett for all objekter av denne classen
public:
	Meeting(int sT, int eT, Campus l, string s, Person* lead);
	~Meeting();
	vector<const Person*> findPotentialCoDriving();

	int getDay()const;
	int getStartTime()const;
	int getEndTime()const;
	Campus getLocation()const;
	string getLocationString() const;
	string getSubject()const;
	Person getLeader()const;
	void addParticipant(const Person* po);
	vector<string> getParticipantList()const;
	set<const Person*> getParticipantsListPERSON() const;
};

ostream& operator<< (ostream& os, const Meeting& m);