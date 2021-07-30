#include <ncurses.h>
#include "game.h"

int	main(int ac, char **av) {

char	c;

initscr();	// starts ncurses mode
cbreak();	// no buffering
noecho();
//nodelay(stdscr, TRUE);	// getch doesn't wait
curs_set(0);	// no cursor

printw("Hello Multiverse!\n\n");
printw("n - start new game\n");
printw("q - quit\n");
refresh();

while(1) {
c = getch();

switch(c) {
case 'n':
	return game('n');
case 'q':
	endwin();
	return 0;
}
}

endwin();	// clears ncurses mode
return 0; }
