#include "game.h"

int	game(char a) {

// DECLARATIONS ==
// data
char	map[10][70];
dlcl	*poi, *universe;
int	scene, I, IMAX;
// UI
WINDOW	*dialog, *hint;
// utilitary
char	c;
int	block;
// ===============

// INITIALIZATIONS
// data
poi = NULL; universe = NULL;
dlcl_insert(&universe, 1, (int[2]){0,0});
dlcl_insert(&universe, 2, (int[2]){0,0});
dlcl_insert(&universe, 3, (int[2]){0,0});
// UI
dialog = newwin(6, 70, 12, 1);
hint = NULL;
// utilitary
c = 0;
block = 0;
// ===============

// === LOADING ===
if (a == 'l') {
	loadsave(&scene, &I);
	switch (scene) {
	case 0:
		IMAX = 33;
		loadmap("asset/map/map1", map, &poi);
		break;
	case 1:
		IMAX = 4;
		loadmap("asset/map/map1", map, &poi);
		break;
	case 2:
		IMAX = 8;
		loadmap("asset/map/map1", map, &poi);
		break;
	case 49:
		IMAX = 13;
		loadmap("asset/map/Moss World", map, NULL);
		break;
	case 50:
		IMAX = 0;
		loadmap("asset/map/Planet Ametita", map, NULL);
		break;
	case 51:
		IMAX = 0;
		loadmap("asset/map/Angelis Star", map, NULL);
		break;
	}
}
else {
	scene = 0; I = 0; IMAX = 33;
	loadmap("asset/map/map1", map, &poi);
}

// ===============

while(1) {

switch(c) {
case 'x':
	if (I < IMAX) I++;
	break;

// map view & move on from scene 0
case 'm':
	if (scene==0 && I==IMAX) {
		scene = 1; I = 0; IMAX = 4; }
	else if (scene>48 && I==IMAX) {
		loadmap("asset/map/map1", map, &poi);
		scene = 2; I = 0; IMAX = 8; }
	else if (scene==2 && I==IMAX) {
		universe = universe->next;
		switch (universe->id) {
		case 1:
			dlcl_clear(&poi);
			loadmap("asset/map/map1", map, &poi);
			break;
		case 2:
			dlcl_clear(&poi);
			loadmap("asset/map/map2", map, &poi);
			break;
		case 3:
			dlcl_clear(&poi);
			loadmap("asset/map/map3", map, &poi);
			break;
		}}
	break;

// arrow key - cycle through POI
case '\033':
	if ((scene==1 && I>=4) || (scene==2 && I==IMAX)) {
		getch();	// getch buffers 3 values
		if ((c=getch())=='D')	// LEFT
			poi = poi->prev;
		else if (c=='C')	// RIGHT
			poi = poi->next;
		if (c=='C'||c=='D') {
			block = 1;
			if (scene==1 && I>=4) IMAX = 6;

			// creating POI name vignet
			if (hint!=NULL)
				delwin(hint);
			hint = newwin(3, poi->name.l+4, poi->pos[0], poi->pos[1]+2);
			box(hint, 0, 0);
			mvwprintw(hint, 1, 2, poi->name.str);
		}
	}
	break;

// Travel to Point Of Interest
case '\n':
	if (scene==1 && I>=6)
		switch (poi->id) {
		case 49:	// '1' Moss World
			scene=49; I=0; IMAX=13;
			dlcl_clear(&poi);
			loadmap("asset/map/Moss World", map, NULL);
			break;
		case 50:	// '2' Planet Anemita
			scene=50; I=0; IMAX=0;
			dlcl_clear(&poi);
			loadmap("asset/map/Planet Ametita", map, NULL);
			break;
		case 51:	// '3' Angelis Star
			scene=51; I=0; IMAX=0;
			dlcl_clear(&poi);
			loadmap("asset/map/Angelis Star", map, NULL);
			break;
		}
	break;

case 's':
	save(scene, I);
	break;
case 'q':
	if (poi!=NULL) dlcl_clear(&poi);
	if (hint) delwin(hint);
	delwin(dialog);
	endwin();
	return 0;
}

// === DISPLAY ===
erase();
// map
displaymap(map);
// cursor
if (scene==1 && I>=4 && block) {
	attron(A_REVERSE);
	mvaddch(poi->pos[0]+1, poi->pos[1]+1, 'X');
	attroff(A_REVERSE);
}
refresh();
// dialog box
displaydialog(dialog, scene, I);
// hint box
if ((scene==1 && I>=4 && block) || (scene==2 && I==IMAX))
	wrefresh(hint);
// ===============

c = getch(); }}
