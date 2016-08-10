#include "std_lib_facilities_4.h"
#include "Graph.h"        // get access to our graphics library facilities
#include "GUI.h"
#include "Window.h"
#include "Pancake.h"

using namespace Graph_lib;
using namespace std;


Pancake::Pancake(Point xy, int s, int p,int c)
    :
	size(s),
	position(p),
	e1(xy,25*s,30),
    b1(Point(xy.x-22,xy.y), "images/pan_button.jpg"),
	color(c)
{
	e1.set_fill_color(c);
}

void Pancake::draw_lines() const
{
	e1.draw_lines();
	b1.draw_lines();
}
int Pancake::get_size() const
{
	return size;
}
int Pancake::get_ycoord() const
{
	return e1.point(0).y;
}
void Pancake::set_ycoord(int y)
{
	e1.set_point(0,Point(e1.point(0).x,y));
	b1.set_point(0,Point(b1.point(0).x,y));
}
int Pancake::get_position() const
{
	return position;
}
void Pancake::set_position(int x)
{
	position = x;
}

//need to override move()
