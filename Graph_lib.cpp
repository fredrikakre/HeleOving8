#include "Graph_lib.h"

using namespace Graph_lib;

int Choice::add(const string& item)
{
	return reference_to<Fl_Choice>(pw).add(item.c_str());
	// reference_to<Fl_Multiline_Output>(pw).value(s.c_str());
}

void Choice::attach(Graph_lib::Window& win)
{
	pw = new Fl_Choice(loc.x, loc.y, width, height, label.c_str());
	// pw->align(FL_ALIGN_TOP);
	own = &win;
}


// Fra øving 5
void Multiline_out_box::put(int i)
{
	Fl_Multiline_Output& po = reference_to<Fl_Multiline_Output>(pw);
	std::stringstream ss;
	ss << i;
	po.value(ss.str().c_str());
}

void Multiline_out_box::put(const string& s)
{
	reference_to<Fl_Multiline_Output>(pw).value(s.c_str());
}

void Multiline_out_box::attach(Graph_lib::Window& win)
{
	pw = new Fl_Multiline_Output(loc.x, loc.y, width, height, label.c_str());
	pw->align(FL_ALIGN_TOP);
	own = &win;
}



