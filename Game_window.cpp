//Splash Screen Class Header FileREAL
#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Game_window.h"
#include "find_solution.h"


Game_window::Game_window(Point xy, int width, int height, const string& title):
	Window(xy,width,height,title),
	background(Point(0,0),width,height),
	pancake(Point(150,200),"images/pancake1.jpg"),
	game_name(Point(0,0),"images/title.jpg"),
	name(Point(45,(height-45)),"images/name.jpg"),
	button_cover1(Point(500,height-35),"images/button_cover.jpg"),
	next_button1(Point(500,height-35),50,20,"images/Rules",cb_next_to_rules),
	rules(Point(0,150),"images/rules.jpg"),
	next_button2(Point(500,height-35),50,20,"",cb_next_to_input),
	button_cover2(Point(500,height-35),"images/button_cover2.jpg"),
	in_name(Point(width/2-50,height/2),100,40,""),
	surr_rect_1(Point(0,0),width/2-50,height),
	surr_rect_2(Point(350,0),width/2-50,height),
	surr_rect_3(Point(0,0),width,height/2),
	surr_rect_4(Point(0,height-(height/2-40)),width,height/2-40),
	quit_button(Point(5,height-35),50,20,"",cb_quit),
	quit_cover(Point(5,height-35),"images/quit.jpg"),
	to_menu(Point(width/2-50,(height/2)+50),100,50,"",cb_get_name),
	to_menu_cover(Point(width/2-50,(height/2)+50),"images/begin.jpg"),
	main_screen(Point(0,0),"images/menu.jpg"),
	two(Point(250,90),100,60,"",cb_two),
	three(Point(354,126),100,60,"",cb_three),
	four(Point(408,199),100,60,"",cb_four),
	five(Point(438,289),100,60,"",cb_five),
	six(Point(405,371),100,60,"",cb_six),
	seven(Point(348,446),100,60,"",cb_seven),
	eight(Point(242,476),100,60,"",cb_eight),
	nine(Point(149,429),100,60,"",cb_nine),
	ten(Point(87,352),100,60,"",cb_ten),
	eleven(Point(85,248),100,60,"",cb_eleven),
	twelve(Point(127,149),100,60,"",cb_twelve),
	slot_one(Point(275,470),50,30,"",cb_slot_one),
	slot_two(Point(275,440),50,30,"",cb_slot_two),
	slot_three(Point(275,410),50,30,"",cb_slot_three),
	slot_four(Point(275,380),50,30,"",cb_slot_four),
	slot_five(Point(275,350),50,30,"",cb_slot_five),
	slot_six(Point(275,320),50,30,"",cb_slot_six),
	slot_seven(Point(275,290),50,30,"",cb_slot_seven),
	slot_eight(Point(275,260),50,30,"",cb_slot_eight),
	slot_nine(Point(275,230),50,30,"",cb_slot_nine),
	slot_ten(Point(275,200),50,30,"",cb_slot_ten),
	slot_eleven(Point(275,170),50,30,"",cb_slot_eleven),
	slot_twelve(Point(275,140),50,30,"",cb_slot_twelve),
	game_background(Point(0,0),"images/game_back.jpg"),
	count(0),
	pos(0),
	min_number(0),
	score(0),
	bonus(false),
	enter_name(Point(0,150),"images/enter_name.jpg"),
	lose_game(Point(0,0),"images/lose_game.jpg"),
	win_game(Point(0,0),"images/win_game.jpg"),
	beat_computer(Point(0,0),"images/beat_computer.jpg"),
	play(Point(540,565),"images/play.jpg"),
	play_again(Point(540,565),50,30,"",[](Address,Address pw)//lambda expression c++11 feature
										  {reference_to<Game_window>(pw).next_to_input();})
{
	// sets up the intial screen and creates all the objects going to be used
	background.set_fill_color(Color::white);
	surr_rect_1.set_color(Color::white);
	surr_rect_2.set_color(Color::white);
	surr_rect_3.set_color(Color::white);
	surr_rect_4.set_color(Color::white);
	surr_rect_1.set_fill_color(Color::white);
	surr_rect_2.set_fill_color(Color::white);
	surr_rect_3.set_fill_color(Color::white);
	surr_rect_4.set_fill_color(Color::white);
	
	attach(background);
	attach(game_name);
	attach(pancake);
	attach(name);
	attach(next_button1);
	attach(button_cover1);
	attach(quit_button);
	attach(quit_cover);
	
}
//--------------------------------------------------------------------------------------
bool check_stack(vector<Pancake*>& pancakes,vector<int*>& stack_order)//checks the stack of pancakes to see if it's in order
{
	stack_order.clear();//clears stack_order vector
	int correct_count{0};
	for(int i=0;i<pancakes.size();++i)
	{
		int* temp = new int(pancakes[i]->get_size());
		stack_order.push_back(temp);
		if(*stack_order[i]==(i+1))
		{
			correct_count++;//this adds to pancake.size() if all the order is correct
		}
	}
	if(correct_count==pancakes.size())
	{
		return true;
	}
	return false;
}
int real_stack_pos(int p,vector<Pancake_coord*>& points_y)//this finds the inverted position of the button since I made the first button on the bottom
{
	int position(0);
	switch(p)
	{
		case 1: position = points_y.size(); break;
		case 2: position = points_y.size()-1; break;
		case 3: position = points_y.size()-2; break;
		case 4: position = points_y.size()-3; break;
		case 5: position = points_y.size()-4; break;
		case 6: position = points_y.size()-5; break;
		case 7: position = points_y.size()-6; break;
		case 8: position = points_y.size()-7; break;
		case 9: position = points_y.size()-8; break;
		case 10: position = points_y.size()-9; break;
		case 11: position = points_y.size()-10; break;
		case 12: position = points_y.size()-11; break;
		
	}
	return position;
}
void Game_window::set_score(int min, int size, int moves)//sets the score
{
	if(bonus&&moves<min)
	{
		score = ((100 - (10*(moves - min_number)))*size)+1000;
	}
	else
	{
		score = ((100 - (10*(moves - min_number)))*size);
	}
	if(score < 0)
	{
		lost_game();
	}
}
void Game_window::flip(int p,vector<Pancake_coord*>& points_y,vector<Pancake*>& pancakes)//flips pancakes and counts how many flips the user has done and calculates current score
{
	int real_pos = 0;
	real_pos = real_stack_pos(p,points_y);
	vector<Pancake*>temp;
	for(int i = 0; i<real_pos;i++)
	{
		temp.push_back(pancakes[i]);
		cout<<pancakes[i]->get_size()<<endl;
	}
	reverse(temp.begin(),temp.end());
	for(int i = 0; i<real_pos;++i)
	{
		pancakes[i]=temp[i];
	}
	for(int i = 0; i<pos;i++)
	{
		detach(*pancakes[i]);
		
		pancakes[i]->set_ycoord(points_y[i]->get_ycoord());
		pancakes[i]->set_position(points_y[i]->get_position());
		attach(*pancakes[i]);
		redraw();
	}
	++count;
	set_score(min_number,pancakes.size(),count);
	cerr<<"the score is "<<score<<endl;
}
//--------------------------------------------------------------------------------------------
//these functions are for finding the min number of flips
void flip_stack(int b,vector<int>& a)
{
	vector<int>temp;
	for(int i = 0; i<b;i++)
	{
		temp.push_back(a[i]);
	}
	reverse(temp.begin(),temp.end());
	for(int i = 0; i<b;i++)
	{
		a[i]=temp[i];
	}
}
int Game_window::big_find_min(vector<int*>& pos)//finds the flips for stacks greater than 10
{
	vector<int>temp;
	vector<int> *temp_pointer;
	int current_big = pos.size();
	int counter{0};
	int add_score{0};
	for(int i = 0; i<pos.size();++i)//dereferences position 
	{
		int temp1 = *pos[i];
		temp.push_back(temp1);
	}
	while(temp.size() > 9)
	{
		vector<int>::iterator i = temp.begin();
		i = std::find(temp.begin(),temp.end(),current_big);//finds where the biggest one is and makes it on the bottom
		int dis = distance(temp.begin(),i);
		flip_stack(dis+1,temp);
		++counter;
		flip_stack(current_big,temp);
		++counter;
		current_big -= 1;
		temp.pop_back();//deletes the last stack and repeates until the size is 9
	}
	add_score += counter;
	temp_pointer = find_solution(temp);
	return add_score + temp_pointer->size();//calculates the min num of flips
}
int Game_window::find_min(vector<int*>& pos)//this works for nine
{	
	vector<int> *a;
	vector<int>temp;
		for(int i = 0; i<pos.size();++i)
		{
			int temp1 = *pos[i];
			temp.push_back(temp1);
		}
		a = find_solution(temp);
		return a->size();
}
void Game_window::shuffle(vector<Pancake*>& a,vector<Pancake_coord*>& points_y)
{
	vector<int*> temp;//needed for the check_stack function
	unsigned seed = time(0);//randomizes the shuffle
	srand(seed);
	int random = rand()%10;
	if(a.size()==2)//if there are 2 pancakes, it is always inverted
	{
		flip(1,points_y,a);
		for(int i = 0; i<a.size();++i)
		{
			a[i]->set_ycoord(points_y[i]->get_ycoord());
			a[i]->set_position(points_y[i]->get_position());
			int* temp = new int(a[i]->get_size());
			stack_order.push_back(temp);
		}
	}
	else{//else it would shuffle randomly
		for(int i = 0; i<random;++i)
		{
			random_shuffle(a.begin(),a.end());
		}
		for(int i = 0; i<a.size();++i)
		{
			a[i]->set_ycoord(points_y[i]->get_ycoord());
			a[i]->set_position(points_y[i]->get_position());
			int* temp = new int(a[i]->get_size());
			stack_order.push_back(temp);
		}
		if(check_stack(a,temp))//makes sure the stack isn't shuffled in order so it randomizes it once more if it is in order
		{	stack_order.clear();
			cerr<<"alternative is called"<<endl;
			random_shuffle(a.begin(),a.end());
			for(int i = 0; i<a.size();++i)
			{
				a[i]->set_ycoord(points_y[i]->get_ycoord());
				a[i]->set_position(points_y[i]->get_position());
				int* temp = new int(a[i]->get_size());
				stack_order.push_back(temp);
			}
		}
	}
	if(stack_order.size()<=9)
	{
		min_number = find_min(stack_order);
	}
	else
	{
		min_number = big_find_min(stack_order);
	}

}
//---------------------------------------------------------------------------------------------------------------
void Game_window::create_pancakes(int s, vector<Pancake*>& p,vector<Pancake_coord*>& points_y)//creates pancakes and assigns its y value from a vector of y values 
{
	for(int i = 0; i < s; ++i)
	{
		Pancake* temp_pan = new Pancake(Point(300,(points_y[i])->get_ycoord()),i+1,points_y[i]->get_position(),15*i);
		p.push_back(temp_pan);

	}
	shuffle(p,points_y);
}
void create_points(int s,vector<Pancake_coord*>& points_y)//creates the vector of y values
{
	int y_coord = s*30;
	int opposite_position = s-1;
	for(int i = 0; i < s; ++i)
	{
		Pancake_coord* a = new Pancake_coord(500-y_coord,s-opposite_position);
		points_y.push_back(a);
		y_coord -= 30;
		--opposite_position;
	}

	
}
//-------------------------------------------------------------------------------------------------------------------------
void Game_window::set_up_main()//deletes the buttons
{
	detach(main_screen);
	detach(two);
	detach(three);
	detach(four);
	detach(five);
	detach(six);
	detach(seven);
	detach(eight);
	detach(nine);
	detach(ten);
	detach(eleven);
	detach(twelve);
	redraw();
}
void Game_window::attach_main()//sets up main menu
{
	detach(in_name);
	detach(surr_rect_1);
	detach(surr_rect_2);
	detach(surr_rect_3);
	detach(surr_rect_4);
	detach(game_name);
	detach(quit_cover);
	detach(to_menu);
	detach(to_menu_cover);
	detach(enter_name);

	attach(main_screen);
	attach(quit_cover);
	attach(two);
	attach(three);
	attach(four);
	attach(five);
	attach(six);
	attach(seven);
	attach(eight);
	attach(nine);
	attach(ten);
	attach(eleven);
	attach(twelve);
}
void Game_window::end_game()//clears the pancakes
{
	detach(game_background);
	for(int i = 0; i < pancakes.size(); ++i)
	{
		detach(*pancakes[i]);
	}
}
void Game_window::quit()
{
	hide();
}
void Game_window::next_to_rules()//goes to rules page
{
	
	detach(pancake);
	detach(name);
	detach(next_button1);
	detach(button_cover1);
	detach(quit_cover);
	
	attach(rules);
	attach(next_button2);
	attach(button_cover2);
	attach(quit_cover);
	
	redraw();
	
}
void Game_window::next_to_input()//goes to input page
{
	detach(rules);
	detach(next_button2);
	detach(button_cover2);
	detach(background);
	detach(game_name);
	detach(quit_cover);
	
	attach(in_name);
	attach(surr_rect_1);
	attach(surr_rect_2);
	attach(surr_rect_3);
	attach(surr_rect_4);
	attach(game_name);
	attach(quit_cover);
	attach(to_menu);
	attach(to_menu_cover);
	attach(enter_name);
	
	redraw();
}

void Game_window::get_name()//gets the name and stores it
{
	player_name = in_name.get_string();
	
	attach_main();
	redraw();
}
//------------------------------------------------------------------------------------------------------------------
//these functions are for the different levels
void Game_window::ltwo()
{
	int size = 2;
	pos = size;
	attach(game_background);

	create_points(size,points_y);
	create_pancakes(size,pancakes,points_y);
	for(auto p : pancakes)//ranged base for loop 
	{
		attach(*p);
	}
	if(pancakes[0]->get_size()==1) bonus = true;
	set_up_main();
	attach(slot_one);
	attach(slot_two);
	attach(quit_cover);
	redraw();
	
}
void Game_window::lthree()
{	
	int size = 3;
	pos = size;
	attach(game_background);
	
	create_points(size,points_y);
	create_pancakes(size,pancakes,points_y);
	for(auto p : pancakes)//ranged base for loop 
	{
		attach(*p);
	}
	set_up_main();
	if(pancakes[0]->get_size()==1) bonus = true;
	attach(slot_one);
	attach(slot_two);
	attach(slot_three);
	attach(quit_cover);
	redraw();
}
void Game_window::lfour()
{attach(game_background);
	int size = 4;
	pos = size;
	attach(game_background);

	
	create_points(size,points_y);
	create_pancakes(size,pancakes,points_y);
	for(auto p : pancakes)//ranged base for loop 
	{
		attach(*p);
	}
	set_up_main();
	if(pancakes[0]->get_size()==1) bonus = true;
	attach(slot_one);
	attach(slot_two);
	attach(slot_three);
	attach(slot_four);
	attach(quit_cover);
	redraw();
}
void Game_window::lfive()
{
	int size = 5;
	pos = size;
	attach(game_background);
	
	create_points(size,points_y);
	create_pancakes(size,pancakes,points_y);
	for(auto p : pancakes)//ranged base for loop 
	{
		attach(*p);
	}
	set_up_main();
	if(pancakes[0]->get_size()==1) bonus = true;
	attach(slot_one);
	attach(slot_two);
	attach(slot_three);
	attach(slot_four);
	attach(slot_five);
	attach(quit_cover);
	redraw();
}
void Game_window::lsix()
{
	int size = 6;
	pos = size;
	attach(game_background);
	
	create_points(size,points_y);
	create_pancakes(size,pancakes,points_y);
	for(auto p : pancakes)//ranged base for loop 
	{
		attach(*p);
	}
	set_up_main();
	if(pancakes[0]->get_size()==1) bonus = true;
	attach(slot_one);
	attach(slot_two);
	attach(slot_three);
	attach(slot_four);
	attach(slot_five);
	attach(slot_six);
	attach(quit_cover);
	redraw();
}
void Game_window::lseven()
{
	int size = 7;
	pos = size;
	attach(game_background);
	
	create_points(size,points_y);
	create_pancakes(size,pancakes,points_y);
	for(auto p : pancakes)//ranged base for loop 
	{
		attach(*p);
	}
	set_up_main();
	if(pancakes[0]->get_size()==1) bonus = true;
	attach(slot_one);
	attach(slot_two);
	attach(slot_three);
	attach(slot_four);
	attach(slot_five);
	attach(slot_six);
	attach(slot_seven);
	attach(quit_cover);
	
	redraw();
}
void Game_window::leight()
{
	int size = 8;
	pos = size;
	attach(game_background);
	
	create_points(size,points_y);
	create_pancakes(size,pancakes,points_y);
	for(auto p : pancakes)//ranged base for loop 
	{
		attach(*p);
	}
	set_up_main();
	if(pancakes[0]->get_size()==1) bonus = true;
	attach(slot_one);
	attach(slot_two);
	attach(slot_three);
	attach(slot_four);
	attach(slot_five);
	attach(slot_six);
	attach(slot_seven);
	attach(slot_eight);
	attach(quit_cover);
	redraw();
}
void Game_window::lnine()
{
	int size = 9;
	pos = size;
	attach(game_background);

	create_points(size,points_y);
	create_pancakes(size,pancakes,points_y);
	for(auto p : pancakes)//ranged base for loop 
	{
		attach(*p);
	}
	set_up_main();
	if(pancakes[0]->get_size()==1) bonus = true;
	attach(slot_one);
	attach(slot_two);
	attach(slot_three);
	attach(slot_four);
	attach(slot_five);
	attach(slot_six);
	attach(slot_seven);
	attach(slot_eight);
	attach(slot_nine);
	attach(quit_cover);
	redraw();
}
void Game_window::lten()
{
	int size = 10;
	pos = size;
	attach(game_background);
	
	create_points(size,points_y);
	create_pancakes(size,pancakes,points_y);
	for(auto p : pancakes)//ranged base for loop 
	{
		attach(*p);
	}
	set_up_main();
	if(pancakes[0]->get_size()==1) bonus = true;
	attach(slot_one);
	attach(slot_two);
	attach(slot_three);
	attach(slot_four);
	attach(slot_five);
	attach(slot_six);
	attach(slot_seven);
	attach(slot_eight);
	attach(slot_nine);
	attach(slot_ten);
	attach(quit_cover);
	redraw();
}
void Game_window::leleven()
{
	int size = 11;
	pos = size;
	attach(game_background);
	
	create_points(size,points_y);
	create_pancakes(size,pancakes,points_y);
	for(auto p : pancakes)//ranged base for loop 
	{
		attach(*p);
	}
	set_up_main();
	if(pancakes[0]->get_size()==1) bonus = true;
	attach(slot_one);
	attach(slot_two);
	attach(slot_three);
	attach(slot_four);
	attach(slot_five);
	attach(slot_six);
	attach(slot_seven);
	attach(slot_eight);
	attach(slot_nine);
	attach(slot_ten);
	attach(slot_eleven);
	attach(quit_cover);
	redraw();
}
void Game_window::ltwelve()
{
	int size = 12;
	pos = size;
	attach(game_background);
	
	create_points(size,points_y);
	create_pancakes(size,pancakes,points_y);
	for(auto p : pancakes)//ranged base for loop 
	{
		attach(*p);
	}
	set_up_main();
	if(pancakes[0]->get_size()==1) bonus = true;
	attach(slot_one);
	attach(slot_two);
	attach(slot_three);
	attach(slot_four);
	attach(slot_five);
	attach(slot_six);
	attach(slot_seven);
	attach(slot_eight);
	attach(slot_nine);
	attach(slot_ten);
	attach(slot_eleven);
	attach(slot_twelve);
	attach(quit_cover);
	redraw();

}
//------------------------------------------------------------------------------------------------------------
//code for the individual buttons
void Game_window::sone()
{
	int pos = 1;
	flip(pos,points_y,pancakes);
	  
	redraw();
	if(check_stack(pancakes,stack_order))won_game();
	++count;
	cout<<pos<<endl;//outputs current score in termial...debug purposes
}
void Game_window::stwo()
{
	int pos = 2;
	flip(pos,points_y,pancakes);
	  
	redraw();
	if(check_stack(pancakes,stack_order))won_game();
	//cout<<pos<<endl;
}
void Game_window::sthree()
{
	int pos = 3;
	flip(pos,points_y,pancakes);
	  
	redraw();
	if(check_stack(pancakes,stack_order))won_game();
	 ;
	cout<<pos<<endl;
}
void Game_window::sfour()
{
	int pos = 4;
	flip(pos,points_y,pancakes);
	  
	redraw();
	if(check_stack(pancakes,stack_order))won_game();
	 ;
	cout<<pos<<endl;
}
void Game_window::sfive()
{
	int pos = 5;
	flip(pos,points_y,pancakes);
	  
	redraw();
	if(check_stack(pancakes,stack_order))won_game();
	 ;
	cout<<pos<<endl;
}
void Game_window::ssix()
{
	int pos = 6;
	int s = pancakes.size();
	flip(pos,points_y,pancakes);
	  
	redraw();
	if(check_stack(pancakes,stack_order))won_game();
	 ;
	cout<<pos<<endl;
}
void Game_window::sseven()
{
	int pos = 7;
	flip(pos,points_y,pancakes);
	  
	redraw();
	if(check_stack(pancakes,stack_order))won_game();
	 ;
	cout<<pos<<endl;
}
void Game_window::seight()
{
	int pos = 8;
	flip(pos,points_y,pancakes);
	  
	redraw();
	if(check_stack(pancakes,stack_order))won_game();
	 ;
	cout<<pos<<endl;
}
void Game_window::snine()
{
	int pos = 9;
	flip(pos,points_y,pancakes);
	  
	redraw();
	if(check_stack(pancakes,stack_order))won_game();

	cout<<pos<<endl;
}
void Game_window::sten()
{
	int pos = 10;
	flip(pos,points_y,pancakes);
	  
	redraw();
	if(check_stack(pancakes,stack_order))won_game();
	cout<<pos<<endl;
}
void Game_window::seleven()
{
	int pos = 11;
	flip(pos,points_y,pancakes);
	  
	redraw();
	if(check_stack(pancakes,stack_order))won_game();
	cout<<pos<<endl;
}
void Game_window::stwelve()
{
	int pos = 12;
	flip(pos,points_y,pancakes);
	  
	redraw();
	if(check_stack(pancakes,stack_order))won_game();
	cout<<pos<<endl;
}
//-------------------------------------------------------------------------------------------------------------------
void Game_window::lost_game()
{
	end_game();
	scores();
	attach(lose_game);
	attach(quit_button);
	attach(quit_cover);
	attach(play_again);
	attach(play);
	//MAKE LEADER BOARDS APPEAR HERE
	redraw();
	display_scores();
}
void Game_window::won_game()
{
	end_game();
	if(score>1000)
	{
		attach(beat_computer);
		attach(quit_button);
		attach(quit_cover);
		attach(play_again);
		attach(play);
	}
	
	//writes the winner's name to the scores list
	ofstream scores1;
	scores1.open("scores.txt", fstream::app);
	scores1 << player_name << ' ' << score << endl;
	scores1.close();
	scores();
	
	attach(win_game);
	attach(quit_button);
	attach(quit_cover);
	attach(play_again);
	attach(play);
	redraw();
	display_scores();
}
void Game_window::scores()
{
	/*vector<string> temp1;
	vector<int> temp2;
	string temp3, temp7;
	int temp4, temp5, temp6, temp8;*/
	
	//reads the full list of names & scores into 2 vectors
	ifstream scores2;
	scores2.open("scores.txt");
	while(scores2 >> temp3 >> temp4)
	{
		temp1.push_back(temp3);
		temp2.push_back(temp4);
	}
	scores2.close();
	
	//sorts the vectors into descending order
	for(int count = 0; count < temp2.size(); ++count)
	{
		temp5 = temp2[count];
		temp6 = count;
		for(int index = count+1; index < temp2.size(); ++index)
		{
			if(temp2[index] > temp5)
			{
				temp5 = temp2[index]; //greatest value
				temp6 = index;		//where it happened
			}
		}
		
		temp7 = temp1[count];
		temp1[count] = temp1[temp6];
		temp1[temp6] = temp7;
		
		temp8 = temp2[count];
		temp2[count] = temp2[temp6];
		temp2[temp6] = temp8;
	}
	assign_scores();
}
void Game_window::assign_scores()
{
	if(temp2.size() >= 1){
		high_name1 = temp1[0];
		high_score1 = static_cast<ostringstream*>( &(ostringstream() << temp2[0]) )->str();
		
		if(temp2.size() >= 2){
			high_name2 = temp1[1];
			high_score2 = static_cast<ostringstream*>( &(ostringstream() << temp2[1]) )->str();
			
			if(temp2.size() >= 3){
				high_name3 = temp1[2];
				high_score3 = static_cast<ostringstream*>( &(ostringstream() << temp2[2]) )->str();
				
				if(temp2.size() >= 4){
					high_name4 = temp1[3];
					high_score4 = static_cast<ostringstream*>( &(ostringstream() << temp2[3]) )->str();
					
					if(temp2.size() >= 5){
						high_name5 = temp1[4];
						high_score5 = static_cast<ostringstream*>( &(ostringstream() << temp2[4]) )->str();
					}
				}
			}
		}
	}
}
void Game_window::display_scores()
{
	Simple_window high_scores(Point(200,465),400,150,"High Scores");
	
	//attaches the ranking numbers
	Text one(Point(105, 20), "1. ");Text two(Point(105, 50), "2. ");Text three(Point(105, 80), "3. ");Text four(Point(105, 110), "4. ");Text five(Point(105, 140), "5. ");
	
	one.set_font_size(20);two.set_font_size(20);three.set_font_size(20);four.set_font_size(20);five.set_font_size(20);
	
	high_scores.attach(one);high_scores.attach(two);high_scores.attach(three);high_scores.attach(four);high_scores.attach(five);
	
	//attaches high score names
	Text high_name_text1(Point(125, 20), high_name1);Text high_name_text2(Point(125, 50), high_name2);Text high_name_text3(Point(125, 80), high_name3);Text high_name_text4(Point(125, 110), high_name4);Text high_name_text5(Point(125, 140), high_name5);
	
	high_name_text1.set_font_size(20);high_name_text2.set_font_size(20);high_name_text3.set_font_size(20);high_name_text4.set_font_size(20);high_name_text5.set_font_size(20);
	
	high_scores.attach(high_name_text1);high_scores.attach(high_name_text2);high_scores.attach(high_name_text3);high_scores.attach(high_name_text4);high_scores.attach(high_name_text5);
	
	//attaches high scores
	Text high_score_text1(Point(250, 20), high_score1);Text high_score_text2(Point(250, 50), high_score2);Text high_score_text3(Point(250, 80), high_score3);Text high_score_text4(Point(250, 110), high_score4);Text high_score_text5(Point(250, 140), high_score5);
	
	high_score_text1.set_font_size(20);high_score_text2.set_font_size(20);high_score_text3.set_font_size(20);high_score_text4.set_font_size(20);high_score_text5.set_font_size(20);
	
	high_scores.attach(high_score_text1);high_scores.attach(high_score_text2);high_scores.attach(high_score_text3);high_scores.attach(high_score_text4);high_scores.attach(high_score_text5);
	
	high_scores.wait_for_button();
}
//call_back functions for all the buttons
void Game_window::cb_next_to_input(Address,Address pw)
{
	reference_to<Game_window>(pw).next_to_input();
}
void Game_window::cb_next_to_rules(Address,Address pw)
{
	reference_to<Game_window>(pw).next_to_rules();
}
void Game_window::cb_quit(Address,Address pw)
{
	reference_to<Game_window>(pw).quit();
}
void Game_window::cb_get_name(Address,Address pw)
{
	reference_to<Game_window>(pw).get_name();
}
void Game_window::cb_two(Address,Address pw)
{
	reference_to<Game_window>(pw).ltwo();
}
void Game_window::cb_three(Address,Address pw)
{
	reference_to<Game_window>(pw).lthree();
}
void Game_window::cb_four(Address,Address pw)
{
	reference_to<Game_window>(pw).lfour();
}
void Game_window::cb_five(Address,Address pw)
{
	reference_to<Game_window>(pw).lfive();
}
void Game_window::cb_six(Address,Address pw)
{
	reference_to<Game_window>(pw).lsix();
}
void Game_window::cb_seven(Address,Address pw)
{
	reference_to<Game_window>(pw).lseven();
}
void Game_window::cb_eight(Address,Address pw)
{
	reference_to<Game_window>(pw).leight();
}
void Game_window::cb_nine(Address,Address pw)
{
	reference_to<Game_window>(pw).lnine();
}
void Game_window::cb_ten(Address,Address pw)
{
	reference_to<Game_window>(pw).lten();
}
void Game_window::cb_eleven(Address,Address pw)
{
	reference_to<Game_window>(pw).leleven();
}
void Game_window::cb_twelve(Address,Address pw)
{
	reference_to<Game_window>(pw).ltwelve();
}

void Game_window::cb_slot_one(Address,Address pw)
{
	reference_to<Game_window>(pw).sone();
}
void Game_window::cb_slot_two(Address,Address pw)
{
	reference_to<Game_window>(pw).stwo();
}
void Game_window::cb_slot_three(Address,Address pw)
{
	reference_to<Game_window>(pw).sthree();
}
void Game_window::cb_slot_four(Address,Address pw)
{
	reference_to<Game_window>(pw).sfour();
}
void Game_window::cb_slot_five(Address,Address pw)
{
	reference_to<Game_window>(pw).sfive();
}
void Game_window::cb_slot_six(Address,Address pw)
{
	reference_to<Game_window>(pw).ssix();
}
void Game_window::cb_slot_seven(Address,Address pw)
{
	reference_to<Game_window>(pw).sseven();
}
void Game_window::cb_slot_eight(Address,Address pw)
{
	reference_to<Game_window>(pw).seight();
}
void Game_window::cb_slot_nine(Address,Address pw)
{
	reference_to<Game_window>(pw).snine();
}
void Game_window::cb_slot_ten(Address,Address pw)
{
	reference_to<Game_window>(pw).sten();
}
void Game_window::cb_slot_eleven(Address,Address pw)
{
	reference_to<Game_window>(pw).seleven();
}
void Game_window::cb_slot_twelve(Address,Address pw)
{
	reference_to<Game_window>(pw).stwelve();
}
