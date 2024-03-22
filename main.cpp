#include "game.h"

void drawhome(window& w, color c, int x, int y, int size) {
	w.SetPen(c);
	w.DrawRectangle(x, y, x+size, y, FILLED,size,size*1.5);
	w.DrawTriangle(x, y, x+size, y,x+ size / 2, y+size / 2, FILLED);
}


int main()
{

	//Create an object of controller
/*	game Game;
	
	Game.run();
	return 0;*/

	window w(1200, 700, 5, 5);

	drawhome(w, RED, 50, 50, 20);
	
	
	
}
