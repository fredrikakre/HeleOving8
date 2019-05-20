#pragma once
// Kode som utvider Graph_lib for øving 8

#include "GUI.h"
#include "FL/Fl_Choice.H"

namespace Graph_lib {

struct Choice : Widget
{
	Choice(Point xy, int w, int h, const string& s) : Widget(xy, w, h, s, 0)
	{}

	int add(const string& item);

	void clear_value() 
	{
		static_cast<Fl_Choice*>(pw)->value(0);
	}

	void attach(Graph_lib::Window& win) override;

	int value()
	{
		return static_cast<Fl_Choice*>(pw)->value();
	}
};

// Fra øving 5
struct Multiline_out_box : Widget
{
	Multiline_out_box(Point xy, int w, int h, const string& s) : Widget(xy, w, h, s, 0)
	{}
	void put(int);
	void put(const string&);

	void attach(Window& win);
};
} // namespace Graph_lib
