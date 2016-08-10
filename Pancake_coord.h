//this class is to include only the y coordinate of a pancake and a number for the value it's suppose to be
#include "std_lib_facilities_4.h"
struct Pancake_coord
{
	Pancake_coord(int y, int p);
	
	int get_ycoord() const;
	int get_position() const;
	private:
		int y_coord;
		int position;
	
};