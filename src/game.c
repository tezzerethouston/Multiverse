#include "game.h"
#include "tools.h"

int	game(char a) {

// DECLARATIONS ==
// data
char	map[10][70];
int	scene, I, IMAX;
// UI
WINDOW	*dialog;
// utilitary
int	i, j;
char	c, d;
FILE	*f;
// ===============

// INITIALIZATIONS
// data
// UI
dialog = newwin(6, 70, 12, 1);
// utilitary
c = 0; d = 0;
// ===============

// === LOADING ===
if (a == 'l') {
	loadsave(&scene, &I);
	switch (scene) {
	case 0: IMAX = 33; break;
	case 1: IMAX = 4; break; }
}
else { scene = 0; I = 0; IMAX = 33; }

loadmap(map);
// ===============

while(1) {

switch(d) {
case 'x':
	if (I < IMAX) I++;
	break;

case 'm':
	if (scene==0 && I==IMAX) {
		scene = 1; I = 0; IMAX = 2; }
	break;

case 's':
	save(scene, I);
	break;
case 'q':
	endwin();
	return 0;
}

// === DISPLAY ===
erase();
displaymap(map);
refresh();

displaydialog(dialog, scene, I);
// ===============

d = getch(); }

endwin();
return 0; }
