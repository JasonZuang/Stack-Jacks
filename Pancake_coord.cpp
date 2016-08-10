#include "std_lib_facilities_4.h"
#include "Pancake_coord.h"

Pancake_coord::Pancake_coord(int y ,int p):
y_coord(y),
position(p)
{}
int Pancake_coord::get_ycoord() const
{
	return y_coord;
}
int Pancake_coord::get_position() const
{
	return position;
}