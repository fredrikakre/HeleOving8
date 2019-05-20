#include "Meetingwindow.h"


MeetingWindow::MeetingWindow(Point xy, int w, int h, const string & title)
	: Window(xy, w, h, title)
	, quitBtn(Point{ fieldPad + fieldW + 2*btnW + pad, pad }, btnW, btnH, "Quit", cb_quit)
	, addP(Point{ fieldPad + fieldW + btnW, pad}, btnW, btnH, "Add", cb_add)
	, personName(Point{fieldPad, pad}, fieldW, fieldH, "Name")
	, personEmail(Point{ fieldPad, 2* pad + fieldH }, fieldW, fieldH, "Email")
	, personSeats(Point{ fieldPad, 3 * pad + 2*fieldH }, fieldW, fieldH, "Seats")
	, data(Point{fieldPad+fieldW+btnW, 2*pad + btnW}, 3*fieldW, fieldW, "Display")
	, testOut_box(Point{ fieldPad + 3*fieldW + btnW, pad}, fieldW, fieldH, "Update:")
	{
	//ATTACH
	attach(quitBtn);
	attach(addP);
	attach(personName);
	attach(personEmail);
	attach(personSeats);
	attach(data);
	attach(testOut_box);
	//OTHER
	testOut_box.put("No error found.");
}

void MeetingWindow::cb_quit(Address, Address pw) {
	reference_to<MeetingWindow>(pw).hide();
}

void MeetingWindow::cb_add(Address, Address pw) {
	reference_to<MeetingWindow>(pw).addPerson();
	reference_to<MeetingWindow>(pw).displayPeople();
}

void MeetingWindow::displayPeople() {
	stringstream sso;
	for (Person* p : people) {
		sso << *p << endl;
	}
	data.put(sso.str());
	
}

void MeetingWindow::addPerson() {
	const string& name = personName.get_string();
	const string& email = personEmail.get_string();
	int seats = personSeats.get_int();
	try {
		if (name.empty()) throw "No name inserted\n";
		if (email.empty()) throw "No email inserted\n";
		if (seats == 0 || seats == NULL) throw 10;
	}
	catch (string) {
		testOut_box.put("Bad input.");
		return;
	}
	catch (int) {
		testOut_box.put("No seats.");
		Person* newPtr = new Person(personName.get_string(), personEmail.get_string(), nullptr); //Ingen bil
		people.push_back(newPtr);
		return;
	}
	testOut_box.put("Seats.");
	Car* carptr = new Car(seats);
	carptr->reserveFreeSeats();
	Person* newPtr = new Person(personName.get_string(), personEmail.get_string(), carptr); //med bil
	people.push_back(newPtr);
}

void MeetingWindow::Print() {
	for (auto i : people) {
		cout << i->getName();
	}
}


