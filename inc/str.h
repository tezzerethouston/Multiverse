#ifndef STR_H
#define STR_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int	l;
	char	*str;
}str;

int	loadstr(FILE *f, str *s);

#endif
