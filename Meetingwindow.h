#pragma once
//#include "Car.h"
//#include "Meeting.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Car.h"
#include "Meeting.h"
#include "Graph_lib.h"


static constexpr float scale = 1;
static constexpr int pad = 15 * scale;
static constexpr int btnW = 40 * scale;
static constexpr int btnH = 25 * scale;
static constexpr int fieldW =  100 * scale;
static constexpr int fieldH = 20 * scale;
static constexpr int fieldPad = 50 * scale;


class MeetingWindow : public Window {
	Button quitBtn;
	Button addP;
	In_box personName;
	In_box personEmail;
	In_box personSeats;
	Out_box testOut_box;
	Multiline_out_box data;
	Vector_ref<Car > cars;
	Vector_ref<Person > people;
public:
	MeetingWindow(Point xy, int w, int h, const string& title);
	void addPerson();
	void Print();
	static void cb_quit(Address, Address pw);
	static void cb_add(Address, Address pw);
	void displayPeople();
	
};