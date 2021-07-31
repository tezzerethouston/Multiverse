#include "dlcl.h"

dlcl	*dlcl_new(int pos[2]) {

dlcl	*new;

new = (dlcl*)malloc(sizeof(dlcl));
new->pos[0] = pos[0];
new->pos[1] = pos[1];
new->prev = NULL;
new->next = NULL;

return new; }
