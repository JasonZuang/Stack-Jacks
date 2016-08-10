#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Game_window.h"

int main()
{
	Game_window win(Point(100,100),600,600,"Splash");
	
	
	return gui_main();
}