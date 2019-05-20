#include "std_lib_facilities.h"
#include "Meeting.h"
#include "Car.h"


set<const Meeting*> Meeting::meetings;				//Hvorfor må man initialisere denne? Og hvorfor her?
Meeting::Meeting(int sT, int eT, Campus l, string s, Person* lead) : startTime(sT), endTime(eT), location(l), subject(s), leader(lead) {
	this->addParticipant(leader);
	meetings.insert(this);
}
Meeting::~Meeting() { 
	meetings.erase(this);
}

void Meeting::addParticipant(const Person* po) {
	participants.insert(po);
}
ostream& operator<< (ostream& os, const Meeting& m) {
	Person lead = m.getLeader();  vector<string> participants = m.getParticipantList(); string participantsString;
	for (int i = 0; i < participants.size(); ++i) participantsString += ("|" + participants[i]);
	os << m.getSubject() << "|" << m.getLocationString() << "|" << m.getStartTime() << "|" << m.getEndTime() << "|" << lead.getName() << participantsString << endl;
	return os;
}
vector<const Person*> Meeting::findPotentialCoDriving() {
	vector<const Person*> people;											
	for (const Meeting* AMeeting : meetings) {				//Går gjennom settet meetings
		if (AMeeting->getLocation() == location &&			//Sjekker om møtet deler lokasjon, dag og tider
			AMeeting->getDay() == day &&
			AMeeting->getStartTime() == startTime &&
			AMeeting->getEndTime() == endTime) {
			for (const Person* APerson : AMeeting->getParticipantsListPERSON()) {	//Sjekker om bilen har ledig plass
				if (APerson->hasAvailableSeats()) people.push_back(APerson);
			}
		}
	}
	return people;
}

int Meeting::getDay()const{
	return day;
}
int Meeting::getStartTime()const {
	return startTime;
}
int Meeting::getEndTime()const {
	return endTime;
}
Campus Meeting::getLocation()const {
	return location;
}
string Meeting::getLocationString() const{
	switch (location) {
	case Campus::Dragvoll: return "Dragvoll";
	case Campus::Glos: return "Glos";
	case Campus::Tunga: return "Tunga";
	default: cout << "Don't recognize location";
	}
}
string Meeting::getSubject()const {
	return subject;
}
Person Meeting::getLeader()const {
	return *leader;
}
vector<string> Meeting::getParticipantList()const {
	vector<string> nameList;
	for (const auto i : participants) {
		nameList.push_back(i->getName());
	}
	return nameList;
}
set<const Person*> Meeting::getParticipantsListPERSON() const {
	return participants;
}

