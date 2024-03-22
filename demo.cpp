
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\auxil.h"	// where Pause is found

void drawhome(window& w, color c, int x, int y, int size) {
	w.SetBrush(c);
	w.DrawRectangle(x, y, x + size, y+size, FILLED);
	w.SetBrush(BLUE);
	w.DrawTriangle(x, y, x + size, y, x + size / 2, y - size / 2, FILLED);
}


int main()
{
	int crand(time(0));
	int size = (rand() + 5) % (400 - 5 + 1);
	int x1 = (rand() + 5) % (1205 - size+1);
	int y1 = (rand() + size / 2) % (705 - (size / 2) + 1);
	window w(1200, 700, 5, 5);
	drawhome(w, RED, x1, y1, size);
	
	
	
}