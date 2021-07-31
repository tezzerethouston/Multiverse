#include <ncurses.h>
#include <locale.h>
#include "game.h"

int	main(int ac, char **av) {

char	c;

setlocale(LC_ALL, "");
initscr();	// starts ncurses mode
cbreak();	// no buffering
noecho();
//nodelay(stdscr, TRUE);	// getch doesn't wait
curs_set(0);	// no cursor

printw("Hello Multiverse!\n\n");
printw("n - start new game\n");
printw("l - load save\n");
printw("q - quit\n\n");
printw("HOW TO PLAY:\n\n");
printw("s - save\n");
printw("q - quit\n");
refresh();

while(1) {
c = getch();

switch(c) {
case 'n':
	return game('n');
case 'l':
	return game('l');
case 'q':
	endwin();	// clears ncurses mode
	return 0;
}}}
