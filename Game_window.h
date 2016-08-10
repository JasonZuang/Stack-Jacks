//Splash Screen Class Header FileREAL
#include "std_lib_facilities_4.h"
#include "Graph.h"
#include "Pancake.h"
#include "Pancake_coord.h"
#include <algorithm>
#include <fstream>

struct Game_window : Graph_lib::Window
{
		Game_window(Point xy, int width, int height, const string& title);
	
		static void cb_next_to_rules(Address,Address);
		static void cb_next_to_input(Address,Address);
		static void cb_quit(Address,Address);
		static void cb_get_name(Address,Address);
		
		static void cb_two(Address,Address);
		static void cb_three(Address,Address);
		static void cb_four(Address,Address);
		static void cb_five(Address,Address);
		static void cb_six(Address,Address);
		static void cb_seven(Address,Address);
		static void cb_eight(Address,Address);
		static void cb_nine(Address,Address);
		static void cb_ten(Address,Address);
		static void cb_eleven(Address,Address);
		static void cb_twelve(Address,Address);
		
		static void cb_slot_one(Address,Address);
		static void cb_slot_two(Address,Address);
		static void cb_slot_three(Address,Address);
		static void cb_slot_four(Address,Address);
		static void cb_slot_five(Address,Address);
		static void cb_slot_six(Address,Address);
		static void cb_slot_seven(Address,Address);
		static void cb_slot_eight(Address,Address);
		static void cb_slot_nine(Address,Address);
		static void cb_slot_ten(Address,Address);
		static void cb_slot_eleven(Address,Address);
		static void cb_slot_twelve(Address,Address);
		
		
		void next_to_rules();
		void next_to_input();
		void get_name();
		void set_up_main();
		void end_game();
		void lost_game();
		void won_game();
		void flip(int p,vector<Pancake_coord*>& points_y,vector<Pancake*>& pancakes);
		void shuffle(vector<Pancake*>& a,vector<Pancake_coord*>& points_y);
		void create_pancakes(int s, vector<Pancake*>& p,vector<Pancake_coord*>& points_y);
		void set_score(int min, int size, int moves);
		void assign_scores();
		void display_scores();
		void display_scores1(Simple_window& a);
		void display_scores2(Simple_window& a);
		void display_scores3(Simple_window& a);
		void scores();
		void attach_main();
		void quit();
		
		int find_min(vector<int*>& pos);
		int big_find_min(vector<int*>& pos);
		
		void ltwo();
		void lthree();
		void lfour();
		void lfive();
		void lsix();
		void lseven();
		void leight();
		void lnine();
		void lten();
		void leleven();
		void ltwelve();
		
		void sone();
		void stwo();
		void sthree();
		void sfour();
		void sfive();
		void ssix();
		void sseven();
		void seight();
		void snine();
		void sten();
		void seleven();
		void stwelve();
		
		
	
	private:
	Rectangle background;
	Rectangle surr_rect_1;
	Rectangle surr_rect_2;
	Rectangle surr_rect_3;
	Rectangle surr_rect_4;
	
	Image pancake;
	Image game_name;
	Image name;
	Image button_cover1;
	Image button_cover2;
	Image quit_cover;
	Image rules;
	Image to_menu_cover;
	Image main_screen;
	Image game_background;
	Image enter_name;
	Image lose_game;
	Image win_game;
	Image beat_computer;
	Image play;
	
	Button next_button1;
	Button next_button2;
	Button quit_button;
	Button play_again;
	Button to_menu;
	
	Button two;
	Button three;
	Button four;
	Button five;
	Button six;
	Button seven;
	Button eight;
	Button nine;
	Button ten;
	Button eleven;
	Button twelve;
	
	Button slot_one;
	Button slot_two;
	Button slot_three;
	Button slot_four;
	Button slot_five;
	Button slot_six;
	Button slot_seven;
	Button slot_eight;
	Button slot_nine;
	Button slot_ten;
	Button slot_eleven;
	Button slot_twelve;

	In_box in_name;
	
	String player_name;
	
	string high_name1 = " ";
	string high_name2 = " ";
	string high_name3 = " ";
	string high_name4 = " ";
	string high_name5 = " ";
	
	string high_score1 = " ";
	string high_score2 = " ";
	string high_score3 = " ";
	string high_score4 = " ";
	string high_score5 = " ";
	
	vector<string> temp1;
	vector<int> temp2;
	string temp3, temp7;
	int temp4, temp5, temp6, temp8;
	
	vector<Pancake_coord*> points_y;
	vector<Pancake*> pancakes;
	vector<int*> stack_order;
	
	int min_number;
	int score;
	int count;
	int pos;
	
	bool bonus;
	
	
	
	
	
	
	
};
