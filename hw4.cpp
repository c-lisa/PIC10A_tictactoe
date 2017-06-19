/***************
Lisa Chiang
Pic 10A Homework 4
October 21, 2016
***************/

#include "ccc_win.h"
#include <cmath>
using namespace std;

bool tl = false, tm = false, tr = false;
bool ml = false, mm = false, mr = false;
bool bl = false, bm = false, br = false;

//creating snap; what n is = to 
int which_square(Point location) {
	int n = 0;

	double x = location.get_x();
	double y = location.get_y();

	if ((-9 <= x) && (x < -3)) n = 1; //column 1
	else if ((-3 <= x) && (x < 3)) n = 2; //column 2
	else if ((3 <= x) && (x < 9)) n = 3; //column 3

	if ((-9 <= y) && (y < -3)) n += 6; //row 3
	else if ((-3 <= y) && (y < 3)) n += 3; //row 2
	else if ((3 <= y) && (y < 9)) n += 0; //row 1

	return n;
}

//
Point snap(Point location) {
	int square = which_square(location);

	if (square == 1) return Point(-6, 6);
	else if (square == 2) return Point(0, 6);
	else if (square == 3) return Point(6, 6);
	else if (square == 4) return Point(-6, 0);
	else if (square == 5) return Point(0, 0);
	else if (square == 6) return Point(6, 0);
	else if (square == 7) return Point(-6, -6);
	else if (square == 8) return Point(0, -6);
	else if (square == 9) return Point(6, -6);
}

//bool related 
bool occupied(Point location)
{
	int square = which_square(location);

	if (square == 1) return tl;
	else if (square == 2) return tm;
	else if (square == 3) return tr;
	else if (square == 4) return ml;
	else if (square == 5) return mm;
	else if (square == 6) return mr;
	else if (square == 7) return bl;
	else if (square == 8) return bm;
	else if (square == 9) return br;
}

void mark(Point location)
{
	int square = which_square(location);

	if (square == 1) tl = true;
	else if (square == 2) tm = true;
	else if (square == 3) tr = true;
	else if (square == 4) ml = true;
	else if (square == 5) mm = true;
	else if (square == 6) mr = true;
	else if (square == 7) bl = true;
	else if (square == 8) bm = true;
	else if (square == 9) br = true;
}

void unmark(Point location)
{
	tl = false, tm = false, tr = false;
	ml = false, mm = false, mr = false;
	bl = false, bm = false, br = false;
}

void drawing_cat(Point location) {

	Point a = snap(location);

	//calibrating to exact center
	double x, y;
	x = a.get_x(); y = a.get_y();

	//creating nose
	Point n1(x - 0.5, y); Point n2(x + 0.5, y); Point n3(x, y - 0.5);
	Line no1(n1, n2); Line no2(n1, n3); Line no3(n2, n3);
	cwin << no1 << no2 << no3;

	//creating the eyes 
	Point e1(x - 1.5, y + 0.5); Point e2(x + 1.5, y + 0.5);
	cwin << e1 << e2;

	//creating the face
	Point f1(x - 2.5, y + 2.5); Point f2(x - 1.5, y + 1.5);
	Point f3(x + 1.5, y + 1.5); Point f4(x + 2.5, y + 2.5);
	Point f5(x + 2.5, y - 0.5); Point f6(x, y - 2);
	Point f7(x - 2.5, y - 0.5);
	Line fa1(f1, f2); Line fa2(f2, f3); Line fa3(f3, f4); Line fa4(f4, f5);
	Line fa5(f5, f6); Line fa6(f6, f7); Line fa7(f7, f1);
	cwin << fa1 << fa2 << fa3 << fa4 << fa5 << fa6 << fa7;

	//creating the whiskers
	Point w1(x - 0.75, y); Point w2(x - 1.75, y);
	Point w3(x - 0.75, y - 0.5); Point w4(x - 1.75, y - 0.7);
	Point w5(x + 0.75, y); Point w6(x + 1.75, y);
	Point w7(x + 0.75, y - 0.5); Point w8(x + 1.75, y - .7);
	Line wh1(w1, w2); Line wh2(w3, w4); Line wh3(w5, w6); Line wh4(w7, w8);
	cwin << wh1 << wh2 << wh3 << wh4;
}

void drawing_dog(Point location)
{
	Point b = snap(location);

	//calibrating to exact center
	double x, y;

	x = b.get_x();
	y = b.get_y();

	//creating nose
	Point nos1(x - 0.5, y); Point nos2(x + 0.5, y);
	Point nos3(x, y - 0.5);
	Line nose1(nos1, nos2); Line nose2(nos1, nos3); Line nose3(nos2, nos3);
	cwin << nose1 << nose2 << nose3;

	//creating the mouth 
	Point m1(x, y); Point m2(x, y - 1);
	Point m3(x - 0.75, y - 1); Point m4(x + 0.75, y - 1);
	Line mo1(m1, m2); Line mo2(m3, m4);
	cwin << mo1 << mo2;

	//creating the eyes 
	Point ey1(x - 1.5, y + 0.5); Point ey2(x + 1.5, y + 0.5);
	cwin << ey1 << ey2;

	//creating the face (variable b)
	Point b1(x - 2.5, y + 1.5); Point b2(x + 2.5, y + 1.5);
	Point b3(x + 2.75, y - 0.5); Point b4(x + 2.25, y + 0.5);
	Point b5(x + 2.25, y - 0.5); Point b6(x + 2.25, y - 1.5);
	Point b7(x - 2.25, y - 1.5); Point b8(x - 2.25, y - 0.5);
	Point b9(x - 2.25, y + 0.5); Point b10(x - 2.75, y - 0.5);
	Line bi1(b1, b2); Line bi2(b2, b3); Line bi3(b3, b5); Line bi4(b4, b6);
	Line bi5(b6, b7); Line bi6(b7, b9); Line bi7(b8, b10); Line bi8(b10, b1);
	cwin << bi1 << bi2 << bi3 << bi4 << bi5 << bi6 << bi7 << bi8;

	//creating the collar 
	Point c1(x - 1.5, y - 1.5); Point c2(x - 1.5, y - 2);
	Point c3(x + 1.5, y - 2); Point c4(x + 1.5, y - 1.5);
	Line co1(c1, c2); Line co2(c2, c3); Line co3(c3, c4);
	cwin << co1 << co2 << co3;

	//creating the tag
	Point t(x, y - 1.75);
	Circle C(t, 0.2);
	cwin << C;
}

int ccc_win_main()
{
	//creating the board dimensions
	cwin.coord(-10, 10, 10, -10);
	//creating the grid
	Point G1(-9, 9), G2(9, 9), G3(-9, -9), G4(9, -9); //four corners
	Point G1c(-9, 3), G1d(-9, -3), G2a(9, 3), G2b(9, -3); //two vertical sides
	Point G1a(-3, 9), G1b(3, 9), G3a(-3, -9), G3b(3, -9); //two horizontal sides
	Line GL1_2(G1, G2); Line GL3_4(G3, G4); Line GL_3(G1, G3); Line GL2_4(G2, G4); // the outer lines
	Line G1a_3a(G1a, G3a); Line G1b_3b(G1b, G3b); Line G1c_2a(G1c, G2a); Line G1d_2b(G1d, G2b); //the inner lines
	cwin << GL1_2 << GL3_4 << GL_3 << GL2_4 << G1a_3a << G1b_3b << G1c_2a << G1d_2b;

	//ACTUAL PROGRAM BEGINS HERE!
	Point a; //clicked point for cat or X
	Point b; //clicked point for dog or O
	int i; //for the cat/X and dog/O loop
	Point c(-2, 0); //Gameover point
	string response; //to redo the program 
	string x; //thanks for playing to exit program
	Message M; //message at end when leaving 

	response = "y"; //what response is to begin the program 

	do
	{
		for (i = 2; i < 11; ++i)
		{
			if (i % 2 == 0)
			{
				//create a cat 
				a = cwin.get_mouse("Click for cat.");

				while (occupied(a)) {
					a = cwin.get_mouse("Click somewhere else!");
				}

				drawing_cat(a);
				mark(a);

			}
			else
			{
				//creating the dog 
				b = cwin.get_mouse("Click for dog.");

				while (occupied(b)) {
					b = cwin.get_mouse("Click somewhere else!");
				}
				drawing_dog(b);
				mark(b);

			}
		}

		//asking user to play again or not
		response = cwin.get_string("Game over. Play again [y/n]?");

		cwin.clear();

		//creating the grid again
		Point G1(-9, 9), G2(9, 9), G3(-9, -9), G4(9, -9); //four corners
		Point G1c(-9, 3), G1d(-9, -3), G2a(9, 3), G2b(9, -3); //two vertical sides
		Point G1a(-3, 9), G1b(3, 9), G3a(-3, -9), G3b(3, -9); //two horizontal sides
		Line GL1_2(G1, G2); Line GL3_4(G3, G4); Line GL_3(G1, G3); Line GL2_4(G2, G4); // the outer lines
		Line G1a_3a(G1a, G3a); Line G1b_3b(G1b, G3b); Line G1c_2a(G1c, G2a); Line G1d_2b(G1d, G2b); //the inner lines
		cwin << GL1_2 << GL3_4 << GL_3 << GL2_4 << G1a_3a << G1b_3b << G1c_2a << G1d_2b;

		unmark(a);
		unmark(b);

	} while (response == "Y" || response == "y");

	//goodbye message to exiting program
	if (response != "Y" || response != "y")
	{
		cwin.clear();
		x = "Thanks for playing!";
		Message M(c, x);
		cwin << M;
	}

	/*code for X and O

	//create an "X"
	a = cwin.get_mouse("Click for X.");
	//getting the points
	const double random = 2.5;
	Point a1(a.get_x() - random, a.get_y() + random); //a1 = upper left
	Point a2(a.get_x() + random, a.get_y() + random); //a2 = upper right
	Point a3(a.get_x() - random, a.get_y() - random); //a3 = lower left
	Point a4(a.get_x() + random, a.get_y() - random); //a4 = lower right
	Line X1(a1, a4); //upper left to bottom right
	Line X2(a2, a3); //upper right to bottom left
	cwin << X1 << X2;

	//create an "O"
	b = cwin.get_mouse("Click for O.");
	Circle C(b, 2.5); //radius 2.5
	cwin << C;

	*/

	return 0;
}