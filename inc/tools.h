#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <ncurses.h>

void	displaydialog(WINDOW *dialog, int scene, int I);
void	displaymap(char map[][70]);
int	save(int scene, int I);
int	loadmap(char map[][70]);
int	loadsave(int *scene, int *I);

#endif
