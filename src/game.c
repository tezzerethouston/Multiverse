#include "game.h"

int	game(char a) {

// DECLARATIONS ==
// data
char	map[10][70];
dlcl	*poi;
int	scene, I, IMAX;
// UI
WINDOW	*dialog;
// utilitary
char	c;
int	block;
// ===============

// INITIALIZATIONS
// data
poi = NULL;
// UI
dialog = newwin(6, 70, 12, 1);
// utilitary
c = 0;
block = 0;
// ===============

// === LOADING ===
if (a == 'l') {
	loadsave(&scene, &I);
	switch (scene) {
	case 0: IMAX = 33; break;
	case 1: IMAX = 4; break; }
}
else { scene = 0; I = 0; IMAX = 33; }

loadmap(map, &poi);
// ===============

while(1) {

switch(c) {
case 'x':
	if (I < IMAX) I++;
	break;

case 'm':
	if (scene==0 && I==IMAX) {
		scene = 1; I = 0; IMAX = 4; }
	break;
case '\033':	// arrow key
	if (scene==1 && I==IMAX) {
		getch();	// getch buffers 3 values
		if ((c=getch())=='D')	// LEFT
			poi = poi->prev;
		else if (c=='C')	// RIGHT
			poi = poi->next;
		block = 1;
	}
	break;

case 's':
	save(scene, I);
	break;
case 'q':
	dlcl_clear(poi);
	endwin();
	return 0;
}

// === DISPLAY ===
erase();
displaymap(map);
if (scene>=1 && I==IMAX && block) {
	attron(A_REVERSE);
	mvaddch(poi->pos[0]+1, poi->pos[1]+1, 'X');
	attroff(A_REVERSE);
}
refresh();

displaydialog(dialog, scene, I);
// ===============

c = getch(); }}
