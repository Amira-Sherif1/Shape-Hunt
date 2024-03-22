
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\auxil.h"	// where Pause is found

void drawhome(window& w, color c, int x, int y, int size) {
	w.SetBrush(c);
	w.DrawRectangle(x, y, x + size, y+size, FILLED);
	//w.SetBrush(BLUE);
	w.DrawTriangle(x, y, x + size, y, x + size / 2, y - size / 2, FILLED);
}


int main()
{
	srand(time(0));
	int size = 5+rand()  % (100 - 5 + 1);
	int x1 = 5+rand() % (1205 - size+1);
	int y1 =   (size / 2) +rand() % ((705-size) - (size / 2) + 1);
	window w(1200, 700, 5, 5);
	drawhome(w, BLACK, x1, y1, size);
	//cout << x1 << endl << y1 << endl << size;
	
	
	
}