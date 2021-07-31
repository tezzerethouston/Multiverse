#include "game.h"

int	game(char a) {

WINDOW	*dialog;
char	map[10][70];
int	i, j;
FILE	*f;
char	c, d;
int	I, scene, IMAX;

// INITIALIZATIONS
c = 0; d = 0;
dialog = newwin(6, 70, 12, 1);
// ===============

// === LOADING ===
if (a == 'l') {
	f = fopen("save", "r");
	scene = getc(f);
	I = getc(f);
	fclose(f);
	switch (scene) {
	case 0: IMAX = 33; break;
	case 1: IMAX = 4; break; }
}
else { scene = 0; I = 0; IMAX = 33; }

f = fopen("map1", "r");
for (i=0; i<10; i++) {
	for (j=0; j<70; j++)
		map[i][j] = getc(f);
	getc(f); getc(f); }
fclose(f);
// ===============

while(1) {

switch(d) {
case 'x':
	if (I < IMAX) I++;
	break;

case 'm':
	if (scene==0 && I==IMAX) {
		scene = 1;
		I = 0;
		IMAX = 2; }
	break;

case 's':
	f = fopen("save", "w");
	putc(scene, f);
	putc(I, f);
	fclose(f);
	break;
case 'q':
	endwin();
	return 0;
}

// === DISPLAY ===
erase();
addch('\n');
for (i=0; i<10; i++) {
	addch(' ');
	for (j=0; j<70; j++) addch(map[i][j]);
	addch('\n'); }
refresh();

werase(dialog);
wmove(dialog, 1, 2);
switch (scene) {
case 0: f = fopen("dialog1", "r"); break;
case 1: f = fopen("dialog2", "r"); break; }
for (i=0; i<I; i++) while(getc(f)!='\n');
i = 0; j = 0;
while((c = getc(f))!='\n') {
	if (i>65) {
		j++;
		wmove(dialog, 1+j, 2);
		i = 0; }
	else i++;
	waddch(dialog, c); }
fclose(f);
box(dialog, 0, 0);
mvwaddch(dialog, 5, 65, 'x');
wrefresh(dialog);
// ===============

d = getch(); }

endwin();
return 0; }
