#include <ncurses.h>

int	main(int ac, char **av) {

initscr();	// starts ncurses mode
cbreak();	// no buffering
noecho();
//nodelay(stdscr, TRUE);	// getch doesn't wait
curs_set(0);	// no cursor

printw("Hello Multiverse!\n");
refresh();

getch();

endwin();	// clears ncurses mode
return 0; }
