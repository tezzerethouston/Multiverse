#include "game.h"

int	game(char a) {

WINDOW	*dialog;
char	map[10][70];
int	i, j;
FILE	*f;

// === LOADING ===
f = fopen("map1", "r");
for (i=0; i<10; i++) {
	for (j=0; j<70; j++)
		map[i][j] = getc(f);
	getc(f); getc(f); }
fclose(f);
		
// ===============

// === DISPLAY ===
erase();
addch('\n');
for (i=0; i<10; i++) {
	addch(' ');
	for (j=0; j<70; j++)
		addch(map[i][j]);
	addch('\n'); }
refresh();

dialog = newwin(6, 70, 12, 1);
box(dialog, 0, 0);
wrefresh(dialog);
// ===============

getch();

endwin();
return 0; }
