#include "Car.h"
#include "std_lib_facilities.h"
using namespace std;
Car::Car(int fSeats) : freeSeats(fSeats) {}
bool Car::hasFreeSeats() const{
	if (freeSeats > 0) {
		return true;
	}
	return false;
}
void Car::reserveFreeSeats() {
	freeSeats -= 1;
}

Person::Person(string n, string e, Car* c = nullptr) : name(n), email(e), car(c) {}
string Person::getEmail() {
	return email;
}
void Person::setEmail(string e) {
	email = e;
}
string Person::getName() const {
	return name;
}
bool Person::hasAvailableSeats() const{
	if (car->hasFreeSeats()) {
		return true;
	}
	return false;

}


ostream& operator<<(ostream& os, const Person& p) {
	os << p.name << " (" << p.email << ")\t" << "Has seats: " << p.hasAvailableSeats();
	return os;
}


