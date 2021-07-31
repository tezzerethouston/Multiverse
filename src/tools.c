#include "tools.h"

// --- DISPLAYDIALOG ---
void	displaydialog(WINDOW *dialog, int scene, int I) {

FILE	*f;
int	i, j;
char	c;

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

return; }

// --- DISPLAYMAP ---
void	displaymap(char map[][70]) {

int	i, j;

move(0, 0);
addch('\n');
for (i=0; i<10; i++) {
	addch(' ');
	for (j=0; j<70; j++)
		addch(map[i][j]);
	addch('\n');
}

return; }

// --- SAVE ---
int	save(int scene, int I) {

FILE	*f;

f = fopen("save", "w");
putc(scene, f);
putc(I, f);
fclose(f);

return 0; }

// --- LOADMAP ---
int	loadmap(char map[][70]) {

FILE	*f;
int	i, j;

f = fopen("map1", "r");
for (i=0; i<10; i++) {
	for (j=0; j<70; j++)
		map[i][j] = getc(f);
	getc(f); getc(f); }
fclose(f);

return 0; }

// --- LOADSAVE ---
int	loadsave(int *scene, int *I) {

FILE	*f;

f = fopen("save", "r");
*scene = getc(f);
*I = getc(f);
fclose(f);

return 0; }
