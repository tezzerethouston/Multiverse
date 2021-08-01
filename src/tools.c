#include "tools.h"

// --- DISPLAYDIALOG ---
void	displaydialog(WINDOW *dialog, int scene, int I) {

FILE	*f;
int	i, j;
char	c;

werase(dialog);
wmove(dialog, 1, 2);
switch (scene) {
case 0: f = fopen("assets/dialog1", "r"); break;
case 1: f = fopen("assets/dialog2", "r"); break; }
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

f = fopen("save/save", "w");
putc(scene, f);
putc(I, f);
fclose(f);

return 0; }

// --- LOADMAP ---
int	loadmap(char map[][70], dlcl **poi) {

FILE	*f;
int	i, j;
dlcl	*l;
char	c, id;

f = fopen("assets/map1", "r");
for (i=0; i<10; i++) {
	for (j=0; j<70; j++) {
		map[i][j] = getc(f);

		// POI
		if (map[i][j]>=49 && map[i][j]<=57) {
			dlcl_insert(poi, map[i][j], (int[2]){i,j});
			map[i][j] = 'X';
		}
	}
	getc(f); getc(f);
}
while ((c = getc(f))!=EOF) {
	id = c; getc(f);
	if (id==(*poi)->id)
		loadstr(f,&(*poi)->name);
	else
		for (l=(*poi)->next; l!=*poi; l=l->next)
			if (id==l->id)
				loadstr(f, &l->name);
	getc(f);
}
fclose(f);

return 0; }

// --- LOADSAVE ---
int	loadsave(int *scene, int *I) {

FILE	*f;

f = fopen("save/save", "r");
*scene = getc(f);
*I = getc(f);
fclose(f);

return 0; }
