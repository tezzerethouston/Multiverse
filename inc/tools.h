#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <ncurses.h>

#include "dlcl.h"

void	displaydialog(WINDOW *dialog, int scene, int I);
void	displaymap(char map[][70]);
int	save(int scene, int I);
int	loadmap(char map[][70], dlcl *poi);
int	loadsave(int *scene, int *I);

#endif
