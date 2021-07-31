#ifndef DLCL_H
#define DLCL_H

#include <stdlib.h>

typedef struct dlcl dlcl;

struct dlcl {
	char	id;
	int	pos[2];
	dlcl	*prev;
	dlcl	*next;
};

dlcl	*dlcl_new(char id, int pos[2]);
void	dlcl_insert(dlcl **list, char id, int pos[2]);
void	dlcl_clear(dlcl *list);

#endif
