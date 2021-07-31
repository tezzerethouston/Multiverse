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
// ===============

// INITIALIZATIONS
// data
poi = NULL;
// UI
dialog = newwin(6, 70, 12, 1);
// utilitary
c = 0;
// ===============

// === LOADING ===
if (a == 'l') {
	loadsave(&scene, &I);
	switch (scene) {
	case 0: IMAX = 33; break;
	case 1: IMAX = 4; break; }
}
else { scene = 0; I = 0; IMAX = 33; }

loadmap(map, poi);
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
refresh();

displaydialog(dialog, scene, I);
// ===============

c = getch(); }}
