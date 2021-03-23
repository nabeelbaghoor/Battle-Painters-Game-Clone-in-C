#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<ctime>
#include <MMSystem.h>
#include"helpnew.h"
#include <WinUser.h>
void setFontSize(int FontSize);
void GetDesktopResolution(int& horizontal, int& vertical);
void input();
void get_rand_key(int dir);
void get_opp_rand_key(int dir);
void opp_input();
void opp_random_input();
void move_without_input();
void brush();
void opp_brush();
void draw();
void border();
void timebar();
void fruit();
void fruit_now();
void remove_fruit();
void speed_powerup();
void speed_powerup_now();
void remove_speed_powerup();
void thick_powerup();
void thick_powerup_now();
void remove_thick_powerup();
void de_color_powerup();
void de_color_powerup_now();
void remove_de_color_powerup();
void de_color_opp_player();
void de_color_player();
void re_color();
void music();
void menu();
void logic();
void time_round();
void check_collision();
void undone_collison();
//rotation input
void newinput();
void opp_newinput();
void opp_random_newinput();
void newbrush();
void opp_newbrush();
void move_without_newinput();
void remove_scrollbar();
void options();
void submenu();
void check_winner();
void get_rand_key_new(int);
void get_opp_rand_key_new(int);
void Clockwise(double& angle, double& x_move, double& y_move);
void Anti_Clockwise(double& angle, double& x_move, double& y_move);
void get_pixel_color();
using namespace std;
/////flag
int remove_thick_powerup_flag, remove_decolor_powerup_flag, remove_speed_powerup_flag, remove_fruit_flag;

int opp_random_newinput_limit = 0,time_now=0;
int start_flag = 0, gametype_flag = 0, controls_flag = 0, enter_flag_options = 0, enter_flag_sub = 0;
int rotation_ctrl_flag = 0, four_key_ctrl_flag = 0, volume_on_flag = 0, volume_off_flag = 0;
int menu_flag = 0, options_flag = 0, submenu_flag = 0, call_options = 0, call_menu = 0, call_submenu = 0;
int back_flag = 0, single_battle_flag = 0, multi_battle_flag = 0;
int gameover = false, key = 1, opp_key = 2, _round = 1, options_key, submenu_key, junk, gamestart = false,pause_key;
int opp_sdistance = 0, sdistance = 0, option_x, option_y;
int fruit_score_texture = 0, fruit_score_speed = 0, fruit_score_thick = 10;
int thick = 30, opp_thick = 30, border_thick = 4, fruit_thick = 20, speed_powerup_thick = 20, thick_powerup_thick = 40, time_ball_thick = 40, de_color_powerup_thick = 30, time_ball_dist = 45;
int texture = 5, opp_texture = 5, border_texture = 2;///texture+speed
int speed, opp_speed, border_speed = 0;//// negative speed
int width, height;
int orig_width, orig_height;
//int x, y, x2, y2;
//int oppx, oppy, oppx2, oppy2;
int de_color_powerup_x1, de_color_powerup_x2, de_color_powerup_y1, de_color_powerup_y2;
int fruit_x1, fruit_y1, fruit_x2, fruit_y2;
int speed_powerup_x1, speed_powerup_y1, speed_powerup_x2, speed_powerup_y2;
int thick_powerup_x1, thick_powerup_y1, thick_powerup_x2, thick_powerup_y2;
int r, g, b, rb, gb, bb;
int r_new=0, g_new=0, b_new=0;
int start_time = 0, end_time = 0, mid_time = 0, no_of_intervals = 0;
int start_time_collision = 0, end_time_collision = 0, mid_time_collision = 0, no_of_intervals_collision = 0;
int interval = 2000, interval_for_collision = 500, interval_for_de_color_opp = 1000, interval_for_de_color_player = 1000;
int flag_collision = 0, speed_powerup_flag = 0, thick_powerup_flag = 0, de_color_powerup_flag=0;
int color_1=0, color_2=0, color_3=255, opp_color_1=255, opp_color_2=0, opp_color_3=0;
int start_time_de_color_player = 0, end_time_de_color_player = 0, mid_time_de_color_player = 0, no_of_intervals_de_color_player = 0;
int start_time_de_color_opp = 0, end_time_de_color_opp = 0, mid_time_de_color_opp = 0, no_of_intervals_de_color_opp = 0;
int de_color_player_flag = 0,de_color_opp_player_flag = 0;
int old_opp_texture,old_texture,old_opp_speed,old_speed;
int de_color_again_flag = 1;
int color_score = 0, color_score_opp = 0;
int enter_key=0;
//NEW ROTATION INPUT
//Player1 Variables
double theeta_1 = 4 * (2 * 3.2 / 180);
double x, y, x2, y2;
double horizontal_1 = 7 * sin(theeta_1), vertical_1 = 7 * cos(theeta_1);

//Player2 Variables
double oppx, oppy, oppx2, oppy2;
double theeta_2 = 4* (2 * 3.2 / 180);
double horizontol_2 = 7 * sin(theeta_2), Vertical_2 = -7 * cos(theeta_2);
//new
int MAX_WIDTH;
int MAX_HEIGHT;
int red, green, blue, alpha;
int color_percent = 0, color_percent_opp = 0;
int sum=1;
//winner
int winner_round_1=-1, winner_round_2=-1, winner_round_3=-1,winner_game=-1;
int main()
{
	//system("mspaint.exe op.jpg");
	setFontSize(36);
	//system("color 9");//back,for
	GetDesktopResolution(width, height);
	orig_width = width, orig_height = height;
	height -= 50;
	x = width / 3, y = height / 2, x2 = x + thick, y2 = y + thick;
	oppx = width / 3, oppy = height / 3, oppx2 = oppx + opp_thick, oppy2 = oppy + opp_thick;
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	remove_scrollbar();
	//system("color 99");
	//system("mode 650");
	//system("mode con COLS=700");
	//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	//SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	//PlaySound(TEXT("qw.wav"), NULL, SND_SYNC);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 22);
	menu();
	do
	{
		if (options_flag == 0 || call_options == 1)
			options();
		if (submenu_flag == 0 || call_submenu == 1)
			submenu();
	} while (!gamestart && !gameover);
	if (single_battle_flag == 0 && multi_battle_flag == 0)
		multi_battle_flag=1;
	if (four_key_ctrl_flag == 0 && rotation_ctrl_flag == 0)
		rotation_ctrl_flag = 1;
	if (volume_on_flag == 0 && volume_off_flag == 0)
		volume_on_flag = 1;
	if (volume_on_flag)
		PlaySound("menu1.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	//system("cls");
	//system("color 0F");
	//HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //just once
	//SetConsoleTextAttribute(color, 15);
	myRect(0, 0, orig_width, orig_height, 255, 255, 255, 255, 255, 255);
	//myRect(0, height, orig_width, orig_height, 0, 0, 0,255,255,255);
	//myLine(0, height-10, width, height-10, 7);
	start_time = clock();
	//start_time = start_time *( 10 ^ (-3));
	gotoxy(0, 20); //height + time_ball_thick + 10);
	cout << "ROUND:" << _round;
	gotoxy(8, 20); //height + time_ball_thick + 10);
	cout << "TIME";
	gotoxy(57, 20);
	if (single_battle_flag)
			cout << "SINGLE BATTLE";
		else
			cout << "MULTIPLAYER";
	//draw();
	border();
	myRect(245, height+1, width - 305, orig_height, 0, 0, 255, 0, 0, 255);
	timebar();
	fruit();
	speed_powerup();
	thick_powerup();
	de_color_powerup();
	if (rotation_ctrl_flag)
		speed = 40, opp_speed = 40;
	else if (four_key_ctrl_flag)
		speed = 20, opp_speed = 20;
	while (!gameover)
	{
		///////////////////speed
		if (rotation_ctrl_flag)
			speed = 30, opp_speed = 30;
		else if (four_key_ctrl_flag)
			speed = 20, opp_speed = 20;
		/////////////////thicknes
		thick = 30, opp_thick = 30;
		//////////////////texture for four key control
		texture = 5, opp_texture = 5;
		////////////////colour
		color_1 = 0, color_2 = 0, color_3 = 255, opp_color_1 = 255, opp_color_2 = 0, opp_color_3 = 0;
		while (no_of_intervals <= 18 && !gameover)
		{
			//isoundkeypressed(sound_key);//m
			//if(sound_key)
			isoptionKeyPressed(pause_key);
			if (pause_key == 1)//p
			{
				pause_key=0;
				do
				{
					isoptionKeyPressed(pause_key);
				} while (pause_key != 4);
				time_now = clock();
				time_now = time_now - start_time;
				start_time += time_now;
			}
			//if (pause_key == 2)//m
			//if (pause_key == 3)//back

			//timebar();
			time_round();
			//player
			if (x > border_thick && y > border_thick && x2 < width - border_thick && y2 < height - border_thick)
			{
				if (rotation_ctrl_flag)
				{
					newbrush();
					newinput();
				}
				else if (four_key_ctrl_flag)
				{
					brush();
					input();
				}
				logic();
				//music();
				//fruit_now();
				if (rotation_ctrl_flag)
					move_without_newinput();
				else if (four_key_ctrl_flag)
					move_without_input();
			}
			if (x <= border_thick)
			{
				x += 4;
				x2 += 4;
				if (four_key_ctrl_flag)
					get_rand_key(1);
				if (rotation_ctrl_flag)
					get_rand_key_new(1);
				//move_without_input();
			}
			if (y <= border_thick)
			{
				y += 4;
				y2 += 4;
				if (four_key_ctrl_flag)
					get_rand_key(2);
				if (rotation_ctrl_flag)
					get_rand_key_new(2);
				//move_without_input();
			}
			if (x2 >= width - border_thick)
			{
				x -= 4;
				x2 -= 4;
				if (four_key_ctrl_flag)
					get_rand_key(3);
				if (rotation_ctrl_flag)
					get_rand_key_new(1);
				//move_without_input();
			}
			if (y2 >= height - border_thick)
			{
				y -= 4;
				y2 -= 4;
				if (four_key_ctrl_flag)
					get_rand_key(4);
				if (rotation_ctrl_flag)
					get_rand_key_new(2);
				//move_without_input();
			}
			//fruit
			if (remove_fruit_flag && ((x >= fruit_x1 && y >= fruit_y1 && x <= fruit_x2 && y <= fruit_y2) || (x2 >= fruit_x1 && y2 >= fruit_y1 && x2 <= fruit_x2 && y2 <= fruit_y2) || (x <= fruit_x1 && y <= fruit_y1 && x2 >= fruit_x1 && y2 >= fruit_y1 && x <= fruit_x2 && y <= fruit_y2 && x2 >= fruit_x2 && y2 >= fruit_y2) || (x <= fruit_x1 && y <= fruit_y1 && x <= fruit_x2 && y >= fruit_y2) || (x2 <= fruit_x1 && y2 <= fruit_y1 && x2 >= fruit_x2 && y2 >= fruit_y2)))
			{
				/*if (texture < 7 && fruit_score_texture>5)
				{
					texture += 2;
					fruit_score_texture = 0;
				}*/
				if (speed > 2 && fruit_score_speed > 5)
				{
					speed -= 2;
					fruit_score_speed = 0;
				}
				if (thick < 100 && fruit_score_thick>5 && thick > 10)
				{
					thick += 5;
					fruit_score_thick = 0;
				}
				if (remove_fruit_flag)
				{
					remove_fruit();
					remove_fruit_flag = 0;
				}
				/*if(no_of_intervals==3 || no_of_intervals == 6 || no_of_intervals == 9 || no_of_intervals == 12 || no_of_intervals == 15 || no_of_intervals == 18)
					fruit();*/
				fruit_score_texture++;
				fruit_score_speed++;
			}
			//speed_powerup
			if (remove_speed_powerup_flag && ((x >= speed_powerup_x1 && y >= speed_powerup_y1 && x <= speed_powerup_x2 && y <= speed_powerup_y2) || (x2 >= speed_powerup_x1 && y2 >= speed_powerup_y1 && x2 <= speed_powerup_x2 && y2 <= speed_powerup_y2) || (x <= speed_powerup_x1 && y <= speed_powerup_y1 && x2 >= speed_powerup_x1 && y2 >= speed_powerup_y1 && x <= speed_powerup_x2 && y <= speed_powerup_y2 && x2 >= speed_powerup_x2 && y2 >= speed_powerup_y2) || (x <= speed_powerup_x1 && y <= speed_powerup_y1 && x <= speed_powerup_x2 && y >= speed_powerup_y2) || (x2 <= speed_powerup_x1 && y2 <= speed_powerup_y1 && x2 >= speed_powerup_x2 && y2 >= speed_powerup_y2)))
			{
				if (rotation_ctrl_flag && speed > 10)
					speed -= 5;
				else if (four_key_ctrl_flag && speed > 10)
					speed -= 5;
				if (remove_speed_powerup_flag)
				{
					remove_speed_powerup();
					remove_speed_powerup_flag = 0;
				}
				/*if(no_of_intervals == 2 || no_of_intervals == 8 || no_of_intervals == 14)
					speed_powerup();*/
				speed_powerup_flag = 1;
			}
			//thick_powerup
			if (remove_thick_powerup_flag && ((x >= thick_powerup_x1 && y >= thick_powerup_y1 && x <= thick_powerup_x2 && y <= thick_powerup_y2) || (x2 >= thick_powerup_x1 && y2 >= thick_powerup_y1 && x2 <= thick_powerup_x2 && y2 <= thick_powerup_y2) || (x <= thick_powerup_x1 && y <= thick_powerup_y1 && x2 >= thick_powerup_x1 && y2 >= thick_powerup_y1 && x <= thick_powerup_x2 && y <= thick_powerup_y2 && x2 >= thick_powerup_x2 && y2 >= thick_powerup_y2) || (x <= thick_powerup_x1 && y <= thick_powerup_y1 && x <= thick_powerup_x2 && y >= thick_powerup_y2) || (x2 <= thick_powerup_x1 && y2 <= thick_powerup_y1 && x2 >= thick_powerup_x2 && y2 >= thick_powerup_y2)))
			{
				if (thick < 70 && thick>10)
					thick += 10;
				if (remove_thick_powerup_flag)
				{
					remove_thick_powerup();
					remove_thick_powerup_flag = 0;
				}
				/*if (no_of_intervals == 4 || no_of_intervals == 10 || no_of_intervals == 16)
					thick_powerup();*/
				thick_powerup_flag = 1;
			}
			//de_color_powerup
			if (remove_decolor_powerup_flag &&((x >= de_color_powerup_x1 && y >= de_color_powerup_y1 && x <= de_color_powerup_x2 && y <= de_color_powerup_y2) || (x2 >= de_color_powerup_x1 && y2 >= de_color_powerup_y1 && x2 <= de_color_powerup_x2 && y2 <= de_color_powerup_y2) || (x <= de_color_powerup_x1 && y <= de_color_powerup_y1 && x2 >= de_color_powerup_x1 && y2 >= de_color_powerup_y1 && x <= de_color_powerup_x2 && y <= de_color_powerup_y2 && x2 >= de_color_powerup_x2 && y2 >= de_color_powerup_y2) || (x <= de_color_powerup_x1 && y <= de_color_powerup_y1 && x <= de_color_powerup_x2 && y >= de_color_powerup_y2) || (x2 <= de_color_powerup_x1 && y2 <= de_color_powerup_y1 && x2 >= de_color_powerup_x2 && y2 >= de_color_powerup_y2)))
			{

				/////do
				/*if (four_key_ctrl_flag)
				{
					old_opp_texture = opp_texture;
					opp_texture = 1;
					old_opp_speed = opp_speed;
					opp_speed -= 10;
				}*/
				de_color_opp_player();
				if (remove_decolor_powerup_flag)
				{
					remove_de_color_powerup();
					remove_decolor_powerup_flag = 0;
				}
				/*if (no_of_intervals == 6 || no_of_intervals == 12 || no_of_intervals == 18)
					de_color_powerup();*/
				//de_color_powerup_flag = 1;
			}
			//opp_sdistance
			//if (opp_sdistance == 500)
			//opp_texture++;
			//opponent(computer)
			if (oppx > border_thick && oppy > border_thick && oppx2 < width - border_thick && oppy2 < height - border_thick)
			{
				if (rotation_ctrl_flag)
				{
					opp_newbrush();
					if (multi_battle_flag)
						opp_newinput();
					else if (single_battle_flag)
						opp_random_newinput();
				}
				else if (four_key_ctrl_flag)
				{
					opp_brush();
					if (multi_battle_flag)
						opp_input();
					else if (single_battle_flag)
						opp_random_input();
				}
				logic();
			}
			if (oppx <= border_thick)
			{
				oppx+=4;
				oppx2+= 4;
				if (four_key_ctrl_flag && multi_battle_flag)
					get_opp_rand_key(1);
				if (rotation_ctrl_flag && multi_battle_flag)
					get_opp_rand_key_new(1);
			}
			if (oppy <= border_thick)
			{
				oppy+= 4;
				oppy2+= 4;
				if (four_key_ctrl_flag && multi_battle_flag)
					get_opp_rand_key(2);
				if (rotation_ctrl_flag && multi_battle_flag)
					get_opp_rand_key_new(2);
			}
			if (oppx2 >= width - border_thick)
			{
				oppx-= 4;
				oppx2-= 4;
				if (four_key_ctrl_flag && multi_battle_flag)
					get_opp_rand_key(3);
				if (rotation_ctrl_flag && multi_battle_flag)
					get_opp_rand_key_new(1);
			}
			if (oppy2 >= height - border_thick)
			{
				oppy-= 4;
				oppy2-= 4;
				if (four_key_ctrl_flag && multi_battle_flag)
					get_opp_rand_key(4);
				if (rotation_ctrl_flag && multi_battle_flag)
					get_opp_rand_key_new(2);
			}
			//friuit for opp
			if (remove_fruit_flag && ((oppx >= fruit_x1 && oppy >= fruit_y1 && oppx <= fruit_x2 && oppy <= fruit_y2) || (oppx2 >= fruit_x1 && oppy2 >= fruit_y1 && oppx2 <= fruit_x2 && oppy2 <= fruit_y2) || (oppx <= fruit_x1 && oppy <= fruit_y1 && oppx2 >= fruit_x1 && oppy2 >= fruit_y1 && oppx <= fruit_x2 && oppy <= fruit_y2 && oppx2 >= fruit_x2 && oppy2 >= fruit_y2) || (oppx <= fruit_x1 && oppy <= fruit_y1 && oppx <= fruit_x2 && oppy >= fruit_y2) || (oppx2 <= fruit_x1 && oppy2 <= fruit_y1 && oppx2 >= fruit_x2 && oppy2 >= fruit_y2)))
			{
				/*if (texture < 7 && fruit_score_texture>5)
				{
					opp_texture += 2;
					fruit_score_texture = 0;
				}*/
				if (opp_speed > 2 && fruit_score_speed > 5)
				{
					opp_speed -= 2;
					fruit_score_speed = 0;
				}
				if (opp_thick < 100 && fruit_score_thick>5 && opp_thick > 10)
				{
					opp_thick += 5;
					fruit_score_thick = 0;
				}
				if (remove_fruit_flag)
				{
					remove_fruit();
					remove_fruit_flag = 0;
				}
				//fruit();
				fruit_score_texture++;
				fruit_score_speed++;
			}
			//speed_powerup for opp
			if (remove_speed_powerup_flag && ((oppx >= speed_powerup_x1 && oppy >= speed_powerup_y1 && oppx <= speed_powerup_x2 && oppy <= speed_powerup_y2) || (oppx2 >= speed_powerup_x1 && oppy2 >= speed_powerup_y1 && oppx2 <= speed_powerup_x2 && oppy2 <= speed_powerup_y2) || (oppx <= speed_powerup_x1 && oppy <= speed_powerup_y1 && oppx2 >= speed_powerup_x1 && oppy2 >= speed_powerup_y1 && oppx <= speed_powerup_x2 && oppy <= speed_powerup_y2 && oppx2 >= speed_powerup_x2 && oppy2 >= speed_powerup_y2) || (oppx <= speed_powerup_x1 && oppy <= speed_powerup_y1 && oppx <= speed_powerup_x2 && oppy >= speed_powerup_y2) || (oppx2 <= speed_powerup_x1 && oppy2 <= speed_powerup_y1 && oppx2 >= speed_powerup_x2 && oppy2 >= speed_powerup_y2)))
			{
				if (rotation_ctrl_flag && opp_speed > 10)
					opp_speed -= 10;
				else if (four_key_ctrl_flag && opp_speed > 10)
					opp_speed -= 10;
				if (remove_speed_powerup_flag)
				{
					remove_speed_powerup();
					remove_speed_powerup_flag = 0;
				}
				//speed_powerup();
				speed_powerup_flag = 1;
			}
			//thick_powerup for opp
			if (remove_thick_powerup_flag && ((oppx >= thick_powerup_x1 && oppy >= thick_powerup_y1 && oppx <= thick_powerup_x2 && oppy <= thick_powerup_y2) || (oppx2 >= thick_powerup_x1 && oppy2 >= thick_powerup_y1 && oppx2 <= thick_powerup_x2 && oppy2 <= thick_powerup_y2) || (oppx <= thick_powerup_x1 && oppy <= thick_powerup_y1 && oppx2 >= thick_powerup_x1 && oppy2 >= thick_powerup_y1 && oppx <= thick_powerup_x2 && oppy <= thick_powerup_y2 && oppx2 >= thick_powerup_x2 && oppy2 >= thick_powerup_y2) || (oppx <= thick_powerup_x1 && oppy <= thick_powerup_y1 && oppx <= thick_powerup_x2 && oppy >= thick_powerup_y2) || (oppx2 <= thick_powerup_x1 && oppy2 <= thick_powerup_y1 && oppx2 >= thick_powerup_x2 && oppy2 >= thick_powerup_y2)))
			{
				if (opp_thick < 70 && opp_thick>10)
					opp_thick += 10;
				if (remove_thick_powerup_flag)
				{
					remove_thick_powerup();
					remove_thick_powerup_flag = 0;
				}
				//thick_powerup();
				thick_powerup_flag = 1;
			}
			//de_color_powerup_opp
			if (remove_decolor_powerup_flag && ((oppx >= de_color_powerup_x1 && oppy >= de_color_powerup_y1 && oppx <= de_color_powerup_x2 && oppy <= de_color_powerup_y2) || (oppx2 >= de_color_powerup_x1 && oppy2 >= de_color_powerup_y1 && oppx2 <= de_color_powerup_x2 && oppy2 <= de_color_powerup_y2) || (oppx <= de_color_powerup_x1 && oppy <= de_color_powerup_y1 && oppx2 >= de_color_powerup_x1 && oppy2 >= de_color_powerup_y1 && oppx <= de_color_powerup_x2 && oppy <= de_color_powerup_y2 && oppx2 >= de_color_powerup_x2 && oppy2 >= de_color_powerup_y2) || (oppx <= de_color_powerup_x1 && oppy <= de_color_powerup_y1 && oppx <= de_color_powerup_x2 && oppy >= de_color_powerup_y2) || (oppx2 <= de_color_powerup_x1 && oppy2 <= de_color_powerup_y1 && oppx2 >= de_color_powerup_x2 && oppy2 >= de_color_powerup_y2)))
			{
				/////do
				/*if (four_key_ctrl_flag)
				{
					old_opp_texture = opp_texture;
					opp_texture = 1;
					old_opp_speed = opp_speed;
					opp_speed -= 10;
				}*/
				de_color_player();
				if (remove_decolor_powerup_flag)
				{
					remove_de_color_powerup();
					remove_decolor_powerup_flag = 0;
				}
				//de_color_powerup();
				//de_color_player_flag = 1;
			}
			check_collision();
			//time_round
			end_time = clock();
			mid_time = end_time - start_time;
			no_of_intervals = mid_time / interval;
			//check_collision
			end_time_collision = clock();
			mid_time_collision = end_time_collision - start_time_collision;
			no_of_intervals_collision = mid_time_collision / interval_for_collision;
			undone_collison();
			//de_color
			//player
			end_time_de_color_player = clock();
			mid_time_de_color_player = end_time_de_color_player - start_time_de_color_player;
			no_of_intervals_de_color_player = mid_time_de_color_player / interval_for_de_color_player;
			//opp
			end_time_de_color_opp = clock();
			mid_time_de_color_opp = end_time_de_color_opp - start_time_de_color_opp;
			no_of_intervals_de_color_opp = mid_time_de_color_opp / interval_for_de_color_opp;
			re_color();

			///new powerup
			if (remove_fruit_flag == 0 && (no_of_intervals == 3 || no_of_intervals == 6 || no_of_intervals == 9 || no_of_intervals == 12 || no_of_intervals == 15 || no_of_intervals == 18))
			{
				fruit();
				remove_fruit_flag = 1;
			}
			if (remove_speed_powerup_flag == 0 && (no_of_intervals == 2 || no_of_intervals == 8 || no_of_intervals == 14))
			{
				speed_powerup();
				remove_speed_powerup_flag = 1;
			}
			if (remove_thick_powerup_flag == 0 && (no_of_intervals == 4 || no_of_intervals == 10 || no_of_intervals == 16))
			{
				thick_powerup();
				remove_thick_powerup_flag = 1;
			}
			if (remove_decolor_powerup_flag == 0 && (no_of_intervals == 6 || no_of_intervals == 12 || no_of_intervals == 18))
			{
				de_color_powerup();
				remove_decolor_powerup_flag = 1;
			}

		}
		get_pixel_color();
		sum = color_score + color_score_opp;
		color_percent = (color_score * 100) / sum;
		color_percent_opp = (color_score_opp*100)/ sum;
		_round++;
		system("cls");
		myRect(0, 0, orig_width, orig_height, 255, 255, 255, 255, 255, 255);
		gotoxy(57, 20);
		if (single_battle_flag)
			cout << "SINGLE BATTLE";
		else
			cout << "MULTIPLAYER";
		gotoxy(30, 10);
		check_winner();
		if (_round<4)// && winner_game!=-1)
			cout << "ROUND " << _round;
			gotoxy(25, 12);
			cout << "PLAYER 1\t" << color_percent << " %";
			gotoxy(25, 14);
			cout << "PLAYER 2\t" << color_percent_opp << " %";
			gotoxy(0, 0);
			do
			{
				isoptionKeyPressed(enter_key);

			} while (enter_key != 4);
			enter_key = 0;
			//system("PAUSE");
			//Sleep(100);
			system("cls");
			////////////////////////to end
			if (gameover == 1)
			{
				system("cls");
				myRect(0, 0, orig_width, orig_height, 255, 255, 255, 255, 255, 255);
				gotoxy(25, 10);
				cout << "PLAYER " << winner_game << " IS WINNER";
				gameover = 1;
				gotoxy(0, 0);
				do
				{
					isoptionKeyPressed(enter_key);

				} while (enter_key != 4); 
				enter_key = 0;
				//system("pause");
			}
			//////////////////////////////to end
			no_of_intervals = 0;
			start_time = clock();
			mid_time = 0;
			end_time = 0;
			x = width / 3, y = height / 2, x2 = x + thick, y2 = y + thick;
			oppx = width / 3, oppy = height / 3, oppx2 = oppx + opp_thick, oppy2 = oppy + opp_thick;
			gotoxy(0, 20); //height + time_ball_thick + 10);
			cout << "ROUND:" << _round;
			gotoxy(8, 20); //height + time_ball_thick + 10);
			cout << "TIME";
			gotoxy(57, 20);
			if (single_battle_flag)
				cout << "SINGLE BATTLE";
			else
				cout << "MULTIPLAYER";
			draw();
			border();
			myRect(245, height+1, width - 305, orig_height, 0, 0, 255, 0, 0, 255);
			timebar();
			fruit();
			speed_powerup();
			thick_powerup();
			de_color_powerup();
	}

}
void GetDesktopResolution(int& horizontal, int& vertical)
{
	RECT desktop;
	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();
	// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &desktop);
	// The top left corner will have coordinates (0,0)
	// and the bottom right corner will have coordinates
	// (horizontal, vertical)
	horizontal = desktop.right;
	vertical = desktop.bottom;
}
void music()
{
	Beep(1873238322, 238322);
}
void draw()
{
	myRect(0, 0, width, height, 255, 255, 255, 255, 255, 255);

}
void border()
{
	//up
	for (int i = 0; i < width; i += border_texture)
	{
		myEllipse(i, 0, i + border_thick, border_thick, 0, 255, 0);
		Sleep(border_speed);
	}
	//right
	for (int j = 0; j < height - 10; j += border_texture)
	{
		myEllipse(width - border_thick, j, width, j + border_thick, 0, 255, 0);
		Sleep(border_speed);
	}
	//down
	for (int i = width; i > 0; i -= border_texture)
	{
		myEllipse(i + border_thick, height - border_thick, i, height, 0, 255, 0);
		Sleep(border_speed);
	}
	//left
	for (int j = height; j > 0; j -= border_texture)
	{
		myEllipse(0, j - border_thick, border_thick, j, 0, 255, 0);
		Sleep(border_speed);
	}
}
void brush()
{
	x2 = x + thick, y2 = y + thick;
	myEllipse(x, y, x2, y2, color_1, color_2, color_3);
	//myEllipse_optional(x, y, x2, y2, color_1, color_2, color_3);
	Sleep(speed);
}
void fruit()
{
	r = rand() % 255, g = rand() % 255, b = rand() % 255;
	//	rb = rand() % 255, gb = rand() % 255, bb = rand() % 255;
	fruit_x1 = rand() % (width - border_thick - 2 * fruit_thick) + border_thick, fruit_x2 = fruit_x1 + fruit_thick, fruit_y1 = rand() % (height - border_thick - 2 * fruit_thick) + border_thick, fruit_y2 = fruit_y1 + fruit_thick;
	myEllipse_optional(fruit_x1, fruit_y1, fruit_x2, fruit_y2, r, g, b);
	//circle(fruit_x1, fruit_y1, rand() % 20 + 20);
	remove_fruit_flag = 1;
}
void fruit_now()
{
	myEllipse_optional(fruit_x1, fruit_y1, fruit_x2, fruit_y2, r, g, b);
}
void remove_fruit()
{
	myEllipse_optional(fruit_x1, fruit_y1, fruit_x2, fruit_y2, 255, 255, 255);
	//PlaySound("p.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
void speed_powerup()
{
	r = rand() % 255, g = rand() % 255, b = rand() % 255;
	//	rb = rand() % 255, gb = rand() % 255, bb = rand() % 255;
	speed_powerup_x1 = rand() % (width - border_thick - 2 * speed_powerup_thick) + border_thick, speed_powerup_x2 = speed_powerup_x1 + speed_powerup_thick, speed_powerup_y1 = rand() % (height - border_thick - 2 * speed_powerup_thick) + border_thick, speed_powerup_y2 = speed_powerup_y1 + speed_powerup_thick;
	myRect(speed_powerup_x1, speed_powerup_y1, speed_powerup_x2, speed_powerup_y2, r, g, b, r, g, b);
	//circle(fruit_x1, fruit_y1, rand() % 20 + 20);
	remove_speed_powerup_flag = 1;
}
void speed_powerup_now()
{
	myRect(speed_powerup_x1, speed_powerup_y1, speed_powerup_x2, speed_powerup_y2, r, g, b, r, g, b);
}
void remove_speed_powerup()
{
	myRect(speed_powerup_x1, speed_powerup_y1, speed_powerup_x2, speed_powerup_y2, 255, 255, 255, 255, 255, 255);
	//PlaySound("p.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
void thick_powerup()
{
	r = rand() % 255, g = rand() % 255, b = rand() % 255;
	//	rb = rand() % 255, gb = rand() % 255, bb = rand() % 255;
	thick_powerup_x1 = rand() % (width - border_thick - 2 * thick_powerup_thick) + border_thick, thick_powerup_x2 = thick_powerup_x1 + thick_powerup_thick, thick_powerup_y1 = rand() % (height - border_thick - 2 * thick_powerup_thick) + border_thick, thick_powerup_y2 = thick_powerup_y1 + thick_powerup_thick;
	myTriangle(thick_powerup_x1, thick_powerup_y1, thick_powerup_x2, thick_powerup_y2, r, g, b, r, g, b);
	//circle(fruit_x1, fruit_y1, rand() % 20 + 20);
	remove_thick_powerup_flag = 1;
}
void thick_powerup_now()
{
	myTriangle(thick_powerup_x1, thick_powerup_y1, thick_powerup_x2, thick_powerup_y2, r, g, b, r, g, b);
}
void remove_thick_powerup()
{
	myTriangle(thick_powerup_x1, thick_powerup_y1, thick_powerup_x2, thick_powerup_y2, 255, 255, 255, 255, 255, 255);
	//PlaySound("p.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

void opp_brush()
{
	oppx2 = oppx + opp_thick, oppy2 = oppy + opp_thick;
	myEllipse(oppx, oppy, oppx2, oppy2, opp_color_1, opp_color_2, opp_color_3);
	Sleep(opp_speed);
	opp_sdistance++;
}
void get_rand_key(int dir)
{
	do
	{
		key = rand() % 4 + 1;
	} while (key == dir);
}
void get_opp_rand_key(int dir)
{
	do
	{
		opp_key = rand() % 4 + 1;
	} while (opp_key == dir);
}
void input()
{
	key;
	isCursorKeyPressed(key);
	switch (key)
	{
	case 2:
		y -= texture;
		y2 -= texture;
		break;
	case 1:
		x -= texture;
		x2 -= texture;
		break;
	case 3:
		x += texture;
		x2 += texture;
		break;
	case 4:
		y += texture;
		y2 += texture;
		break;
	/*case '`':
		gameover = true;
		break;*/
	}
}
void move_without_input()
{
	switch (key)
	{
	case 2:
		y -= texture;
		y2 -= texture;
		break;
	case 1:
		x -= texture;
		x2 -= texture;
		break;
	case 3:
		x += texture;
		x2 += texture;
		break;
	case 4:
		y += texture;
		y2 += texture;
		break;
	}
}
void opp_random_input()
{
	//srand(time(NULL));
	int random, flag = rand() % 4 + 1;
	if (flag == 1)
	{
		srand(time(NULL));
		random = rand() % 4 + 1;
	}
	else if (flag == 2)
		random = rand() % 4 + 1;
	else if (flag == 3)
	{
		random = rand() % 4 + 1;
	}
	else
	{
		srand(time(NULL));
		random = rand() % 4 + 1;
	}
	switch (random)
	{
	case 1:
		oppy -= opp_texture;
		oppy2 -= opp_texture;
		break;
	case 2:
		oppx -= opp_texture;
		oppx2 -= opp_texture;
		break;
	case 3:
		oppx += opp_texture;
		oppx2 += opp_texture;
		break;
	case 4:
		oppy += opp_texture;
		oppy2 += opp_texture;
		break;
	}
}
void opp_input()
{
	opp_key;
	isCursorKeyPressed_leftcontrols(opp_key);
	switch (opp_key)
	{
	case 2:
		oppy -= opp_texture;
		oppy2 -= opp_texture;
		break;
	case 1:
		oppx -= opp_texture;
		oppx2 -= opp_texture;
		break;
	case 3:
		oppx += opp_texture;
		oppx2 += opp_texture;
		break;
	case 4:
		oppy += opp_texture;
		oppy2 += opp_texture;
		break;
	/*case '`':
		gameover = true;
		break;*/
	}
}

void logic()
{

}
void menu()
{
	gotoxy(23, 10);
	cout << "WELCOME TO NULL STUDIOS";
	//cout << "\n\n\n\n\n\n\n\n\n\n";
	_getch();
	system("cls");

}
void timebar()
{
	for (int i = 250; i<width - 340; i += time_ball_dist)
	{
		myEllipse_optional(i, height + 5, i + time_ball_thick, height + 5 + time_ball_thick, 0, 0, 0);
	}
}
void time_round()
{
	for (int i = 250, k = 1; i < width - 340 && k <= no_of_intervals; i += time_ball_dist, k++)
	{
		myEllipse_optional(i, height + 5, i + time_ball_thick, height + 5 + time_ball_thick, 255, 255, 255);
	}
}
void setFontSize(int FontSize)
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = FontSize; // leave X as zero
	info.FontWeight = FW_NORMAL;
	//	wcscpy(info.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}
void check_collision()
{
	if ((x >= oppx && y >= oppy && x <= oppx2 && y <= oppy2) || (x2 >= oppx && y2 >= oppy && x2 <= oppx2 && y2 <= oppy2) || (x <= oppx && y <= oppy && x2 >= oppx && y2 >= oppy && x <= oppx2 && y <= oppy2 && x2 >= oppx2 && y2 >= oppy2) || (x <= oppx && y <= oppy && x <= oppx2 && y >= oppy2) || (x2 <= oppx && y2 <= oppy && x2 >= oppx2 && y2 >= oppy2))
	{
		//re_color();
		if (speed_powerup_flag == 1 || thick_powerup_flag == 1)
		{
			if (speed_powerup_flag == 1)
			{
				speed += 5;
				speed_powerup_flag = 0;
			}
			if (thick_powerup_flag == 1 && thick > 15)                ////////##
			{
				thick -= 10;
				thick_powerup_flag = 0;
			}
		}
		else
		{
			if (flag_collision == 0)
			{
				speed += 70;                             ////////////////////##
				start_time_collision = clock();
				flag_collision = 1;
			}
		}

	}
}
void undone_collison()
{
	if (speed > 75 && no_of_intervals_collision >= 10 && no_of_intervals_collision <= 15 && flag_collision == 1)  /////##
	{
		speed -= 70;
		flag_collision = 0;
	}
}
void Anti_Clockwise(double& angle, double& x_move, double& y_move)
{
	angle += 4*(2 * 3.2 / 180);
	x_move = 7*sin(angle);
	y_move = 7 * cos(angle);
}
void Clockwise(double& angle, double& xmove, double& ymove)
{
	angle -= 4 * (2 * 3.2 / 180);
	xmove = 7 * sin(angle);
	ymove = 7 * cos(angle);
}
void newinput()
{
	if (isCursorKeyPressednew(key))
	{
		if (key == 3) //press right arrow key to move in clockwise direction(Player 1)
			Clockwise(theeta_1, horizontal_1, vertical_1);
		if (key == 1) //press left arrow key to move in anti_clockwise direction(Player 1)
			Anti_Clockwise(theeta_1, horizontal_1, vertical_1);
	}
}
void opp_newinput()
{
	//srand(time(NULL));
	//opp_key = rand() % 2;
	if (isCursorKeyPressednew(opp_key))
	{
		if (opp_key == 4) //press D key to move in clockwise direction(Player 2)
			Clockwise(theeta_2, horizontol_2, Vertical_2);
		if (opp_key == 2) //press A key to move in anticlockwise direction(Player 2)
			Anti_Clockwise(theeta_2, horizontol_2, Vertical_2);
	}
}
void newbrush()
{
	//player
	x = x + horizontal_1;		
	x2 = x + thick;				
	y = y + vertical_1;			
	y2 = y + thick;				
	//player ellipse
	myEllipse(x, y, x2, y2, color_1, color_2, color_3);//yellow colour
	Sleep(speed);
}
void opp_newbrush()
{
	oppx = oppx + horizontol_2;			
	oppx2 = oppx + opp_thick;			
	oppy = oppy + Vertical_2;			
	oppy2 = oppy + opp_thick;						
	//player ellipse
	myEllipse(oppx, oppy, oppx2, oppy2, opp_color_1, opp_color_2, opp_color_3);//yellow colour
	Sleep(opp_speed);
}
void move_without_newinput()
{

}
void opp_random_newinput()
{
	srand(time(NULL));
	opp_key = rand() % 2;
	//opp_random_newinput_limit = 0;
	if (opp_key == 0)
		opp_key = 4;
	if (opp_key == 1)
		opp_key = 2;
	if (opp_key == 2)
		Clockwise(theeta_2, horizontol_2, Vertical_2);
	else if (opp_key == 4)
		Anti_Clockwise(theeta_2, horizontol_2, Vertical_2);
}
void get_rand_key_new(int dir)
{
	do
	{
		key = rand() % 2 + 1;
	} while (key == dir);
}
void get_opp_rand_key_new(int dir)
{
	do
	{
		opp_key = rand() % 2 + 1;
	} while (opp_key == dir);
}
void remove_scrollbar()
{
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	csbi.dwSize.X = csbi.dwMaximumWindowSize.X;
	csbi.dwSize.Y = csbi.dwMaximumWindowSize.Y;
	SetConsoleScreenBufferSize(hstdout, csbi.dwSize);

	HWND x_x = GetConsoleWindow();
	ShowScrollBar(x_x, SB_BOTH, FALSE);
}
void options()
{
	system("cls");
	option_x = 30;
	system("color F0");
	myRect(0, 0, orig_width, orig_height, 255, 255, 255, 255, 255, 255);
	gotoxy(option_x, 6);
	cout << "  START";
	gotoxy(option_x, 8);
	cout << "GAME TYPE";
	gotoxy(option_x, 10);
	cout << " CONTROLS";
	gotoxy(option_x, 12);
	cout << " OPTIONS";
	gotoxy(option_x, 14);
	cout << "   QUIT";
	option_y = 6;
	//gotoxy(option_x, 6);
	option_y = 6;
	isCursorKeyPressed(junk);
	while (enter_flag_options != 1 && !gameover && !gamestart)
	{

		isCursorKeyPressednew2(options_key);
		switch (options_key)
		{
		case 2://up
			if (option_y >= 8)
				option_y -= 2;
			break;
		case 1://enter
			if (option_y == 6)
				start_flag = 1;
			else if (option_y == 8)
				gametype_flag = 1;
			else if (option_y == 10)
				controls_flag = 1;
			else if (option_y == 12)
				options_flag = 1;
			else if (option_y == 14)
				gameover = true;
			enter_flag_options = 1;
			break;
		case 3://backspace
			break;
		case 4://down
			if (option_y <= 12)
				option_y += 2;
			break;
		case 5://escape
			gameover = true;
			break;
		}
		options_key = 0;
		system("color F0");
		gotoxy(option_x, option_y);
	}
	myRect(0, 0, orig_width, orig_height, 0, 0, 0, 0, 0, 0);
	enter_flag_options = 0;
	//options_flag = 1;
	//call_submenu = 1;
}
void submenu()
{
	system("cls");
	if (start_flag)
	{
		gamestart = 1;
		start_flag = 0;
	}
	else if (gametype_flag)
	{
		option_x = 25;
		myRect(0, 0, orig_width, orig_height, 255, 255, 255, 255, 255, 255);
		gotoxy(option_x, 6);
		cout << " SELECT BATTLE TYPE";
		gotoxy(option_x, 8);
		cout << "";
		gotoxy(option_x, 10);
		cout << "   SINGLE BATTLE";
		gotoxy(option_x, 12);
		cout << "    MULTIPLAYER ";
		gotoxy(option_x, 14);
		cout << "       BACK";
		option_y = 6;
		//gotoxy(option_x, 10);
		cout << "";
		isCursorKeyPressed(junk);
		option_y = 10;
		while (enter_flag_sub != 1 && !gameover && !gamestart)
		{
			isCursorKeyPressednew2(submenu_key);
			switch (submenu_key)
			{
			case 2://up
				if (option_y >= 12)
					option_y -= 2;
				break;
			case 1://enter
				if (option_y == 10)
				{
					single_battle_flag = 1;
					multi_battle_flag = 0;
				}
				else if (option_y == 12)
				{
					multi_battle_flag = 1;
					single_battle_flag = 0;
				}
				else if (option_y == 14)
				{
					back_flag = 1;
					call_options = 1;
				}
				enter_flag_sub = 1;
				break;
			case 3://backspace
				call_options = 1;
				enter_flag_sub = 1;//////////////dual
				back_flag = 1;
				break;
			case 4://down
				if (option_y <= 12)
					option_y += 2;
				break;
			case 5://escape
				gameover = true;
				break;
			}
			submenu_key = 0;
			system("color F0");
			gotoxy(option_x, option_y);
		}
		gametype_flag = 0;
		enter_flag_sub = 0;
	}
	else if (controls_flag)
	{
		option_x = 25;
		myRect(0, 0, orig_width, orig_height, 255, 255, 255, 255, 255, 255);
		gotoxy(option_x, 6);
		cout << "   CONTROLS";
		gotoxy(option_x, 8);
		cout << "";
		gotoxy(option_x, 10);
		cout << "FOUR KEY CONTROL";
		gotoxy(option_x, 12);
		cout << "ROTATION CONTROL";
		gotoxy(option_x, 14);
		cout << "       BACK";
		option_y = 6;
		//gotoxy(option_x, 10);
		cout << "";
		isCursorKeyPressed(junk);
		option_y = 10;
		while (enter_flag_sub != 1 && !gameover && !gamestart)
		{
			isCursorKeyPressednew2(submenu_key);
			switch (submenu_key)
			{
			case 2://up
				if (option_y >= 12)
					option_y -= 2;
				break;
			case 1://enter
				if (option_y == 10)
				{
					four_key_ctrl_flag = 1;
					rotation_ctrl_flag = 0;
				}
				else if (option_y == 12)
				{
					rotation_ctrl_flag = 1;
					four_key_ctrl_flag = 0;
				}
				else if (option_y == 14)
				{
					back_flag = 1;
					call_options = 1;
				}
				enter_flag_sub = 1;
				break;
			case 3://backspace
				call_options = 1;
				enter_flag_sub = 1;//////////////dual
				back_flag = 1;
				break;
			case 4://down
				if (option_y <= 12)
					option_y += 2;
				break;
			case 5://escape
				gameover = true;
				break;
			}
			submenu_key = 0;
			system("color F0");
			gotoxy(option_x, option_y);
		}
		enter_flag_sub = 0;
		controls_flag = 0;
	}
	else if (options_flag)
	{
		option_x = 25;
		myRect(0, 0, orig_width, orig_height, 255, 255, 255, 255, 255, 255);
		gotoxy(option_x, 6);
		cout << "TURN ON/OFF VOLUME";
		gotoxy(option_x, 8);
		cout << "";
		gotoxy(option_x, 10);
		cout << "      ON";
		gotoxy(option_x, 12);
		cout << "      OFF";
		gotoxy(option_x, 14);
		cout << "      BACK";
		option_y = 6;
		//gotoxy(option_x, 10);
		cout << "";
		isCursorKeyPressed(junk);
		option_y = 10;
		while (enter_flag_sub != 1 && !gameover && !gamestart)
		{
			isCursorKeyPressednew2(submenu_key);
			switch (submenu_key)
			{
			case 2://up
				if (option_y >= 12)
					option_y -= 2;
				break;
			case 1://enter
				if (option_y == 10)
					volume_on_flag = 1;
				else if (option_y == 12)
					volume_off_flag = 1;
				else if (option_y == 14)
				{
					back_flag = 1;
					call_options = 1;
				}
				enter_flag_sub = 1;
				break;
			case 3://backspace
				call_options = 1;
				enter_flag_sub = 1;//////////////dual
				back_flag = 1;
				break;
			case 4://down
				if (option_y <= 12)
					option_y += 2;
				break;
			case 5://escape
				gameover = true;
				break;
			}
			submenu_key = 0;
			system("color F0");
			gotoxy(option_x, option_y);
		}
		enter_flag_sub = 0;
		options_flag = 0;
	}
	//submenu_flag = 1;
	system("cls");
}
void de_color_powerup()
{
	r = rand() % 255, g = rand() % 255, b = rand() % 255;
	//	rb = rand() % 255, gb = rand() % 255, bb = rand() % 255;
	de_color_powerup_x1 = rand() % (width - border_thick - 2 * de_color_powerup_thick) + border_thick, de_color_powerup_x2 = de_color_powerup_x1 + de_color_powerup_thick, de_color_powerup_y1 = rand() % (height - border_thick - 2 * de_color_powerup_thick) + border_thick, de_color_powerup_y2 = de_color_powerup_y1 + de_color_powerup_thick;
	myTriangle(de_color_powerup_x1, de_color_powerup_y1, de_color_powerup_x2, de_color_powerup_y2, 0, 0, 0, r, g, b);
	//circle(fruit_x1, fruit_y1, rand() % 20 + 20);
}
void de_color_powerup_now()
{
	myTriangle(de_color_powerup_x1, de_color_powerup_y1, de_color_powerup_x2, de_color_powerup_y2, 0, 0, 0, r, g, b);
}
void remove_de_color_powerup()
{
	myTriangle(de_color_powerup_x1, de_color_powerup_y1, de_color_powerup_x2, de_color_powerup_y2, 255, 255, 255, 255, 255, 255);
	//PlaySound("p.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
void de_color_player()
{
	color_1 = 255,color_2 = 255,color_3 = 255;
	de_color_player_flag = 1;
	start_time_de_color_player = clock();
}
void de_color_opp_player()
{
	opp_color_1 = 255, opp_color_2 = 255, opp_color_3 = 255;
	de_color_opp_player_flag = 1;
	start_time_de_color_opp = clock();
}
void re_color()
{
	if (de_color_opp_player_flag && no_of_intervals_de_color_opp>=10 && no_of_intervals_de_color_opp<=15)
	{
		opp_color_1 = 255, opp_color_2 = 0, opp_color_3 = 0;
		de_color_opp_player_flag = 0;
		/*if (four_key_ctrl_flag)
		{
			opp_texture = old_opp_texture;
			opp_speed=old_opp_speed;
		}*/
	}
	if (de_color_player_flag && no_of_intervals_de_color_player >= 10 && no_of_intervals_de_color_player <= 15)
	{
		color_1 = 0, color_2 = 0, color_3 = 255;
		de_color_player_flag = 0;
		/*if (four_key_ctrl_flag)
		{
			texture = old_texture;
			speed = old_speed;
		}*/
	}
}
void check_winner()
{
	if (_round == 1)
	{
		if (color_percent == color_percent_opp)
			winner_round_1 = 0;//draw
		else if (color_percent > color_percent_opp)
			winner_round_1 = 1;
		else
			winner_round_1 = 2;
	}
	else if (_round == 2)
	{
		if (color_percent == color_percent_opp)
			winner_round_2 = 0;//draw
		else if (color_percent > color_percent_opp)
			winner_round_2= 1;
		else
			winner_round_2 = 2;
		if (winner_round_1 == winner_round_2)
		{
			winner_game = winner_round_1;
			gameover = 1;
		}
	}
	else if (_round == 3)
	{
		if (color_percent == color_percent_opp)
			winner_round_3 = 0;//draw
		else if (color_percent > color_percent_opp)
			winner_round_3 = 1;
		else
			winner_round_3 = 2;
		if (winner_round_2 == winner_round_3)
		{
			winner_game = winner_round_3;
			gameover = 1;
		}
		else if (winner_round_1 == winner_round_3)
		{
			winner_game = winner_round_3;
			gameover = 1;
		}
	}
}
void get_pixel_color()
{

	////////////////////////////////////////////////////////////////////////////
	HDC hdc, hdcTemp;
	RECT rect;
	BYTE* bitPointer;
	hdc = GetDC(HWND_DESKTOP);
	//GetWindowRect(HWND_DESKTOP, &rect);
	int MAX_WIDTH = width;
	int MAX_HEIGHT = height;

	hdcTemp = CreateCompatibleDC(hdc);
	BITMAPINFO bitmap;
	bitmap.bmiHeader.biSize = sizeof(bitmap.bmiHeader);
	bitmap.bmiHeader.biWidth = MAX_WIDTH;
	bitmap.bmiHeader.biHeight = MAX_HEIGHT;
	bitmap.bmiHeader.biPlanes = 1;
	bitmap.bmiHeader.biBitCount = 32;
	bitmap.bmiHeader.biCompression = BI_RGB;
	bitmap.bmiHeader.biSizeImage = MAX_WIDTH * 4 * MAX_HEIGHT;
	bitmap.bmiHeader.biClrUsed = 0;
	bitmap.bmiHeader.biClrImportant = 0;
	HBITMAP hBitmap2 = CreateDIBSection(hdcTemp, &bitmap, DIB_RGB_COLORS, (void**)(&bitPointer), NULL, NULL);
	SelectObject(hdcTemp, hBitmap2);
	BitBlt(hdcTemp, 0, 0, MAX_WIDTH, MAX_HEIGHT, hdc, 0, 0, SRCCOPY);
	for (int i = 0; i < (MAX_WIDTH * 4 * MAX_HEIGHT); i += 4)
	{
		red = (int)bitPointer[i];
		green = (int)bitPointer[i + 1];
		blue = (int)bitPointer[i + 2];
		alpha = (int)bitPointer[i + 3];

		x = i / (4 * MAX_HEIGHT);
		y = i / (4 * MAX_WIDTH);

		if (red == 255 && green == 0 && blue == 0)////its BGR error so invert rgb to bgr
			color_score++;
		if (red == 0 && green == 0 && blue == 255)
			color_score_opp++;
	}
	////////////////////////////////////////////////////////////////////////////////////////
}