// pancakes header
#include "std_lib_facilities_4.h"
#include "Graph.h"        // get access to our graphics library facilities
#include "GUI.h"
#include "Window.h"


using namespace Graph_lib;
using namespace std;

//---------------------------------------------------------------------------------------------------

struct Pancake :Graph_lib::Shape{
    Pancake(Point a, int s,int p,int c);
	void draw_lines() const;
    int get_size() const;
	int get_ycoord() const;
	void set_ycoord(int y);
	int get_position() const;
	void set_position(int x); 

private:
	Ellipse e1;
	int size;
	int position;
	int color;
	Image b1;
};
