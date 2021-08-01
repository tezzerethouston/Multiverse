#include "str.h"

// --- LOADSTR ---
int	loadstr(FILE *f, str *s) {

int	i, j;

i = 0;

if (s->str!= NULL)
	free(s->str);
while (getc(f)!='\n') i++;
s->l = i;
s->str = (char *)malloc(sizeof(char)*(i+1));
fseek(f, -i-1, SEEK_CUR);
for (j=0; j<i; j++)
	s->str[j] = getc(f);
s->str[i] = '\0';

return 0; }
