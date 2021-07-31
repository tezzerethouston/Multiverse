#ifndef DLCL_H
#define DLCL_H

#include <stdlib.h>

typedef struct dlcl dlcl;

struct dlcl {
	int	pos[2];
	dlcl	*prev;
	dlcl	*next;
};

dlcl	*dlcl_new(int pos[2]);

#endif
