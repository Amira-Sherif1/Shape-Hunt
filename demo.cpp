
#include <iostream>
#include <sstream>
#include <cmath>

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

	//Create an object of controller
/*	game Game;

	Game.run();
	return 0;*/

	window w(1200, 700, 5, 5);

	drawhome(w, RED, 700, 100, 60);
	w.SetBrush(BLUE);
	//w.DrawRectangle(100, 100, 300, 100 + 150, FILLED);
	
}