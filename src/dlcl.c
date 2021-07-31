#include "dlcl.h"

#include <ncurses.h>

// --- DLCL_NEW ---
dlcl	*dlcl_new(char id, int pos[2]) {

dlcl	*new;

new = (dlcl*)malloc(sizeof(dlcl));
new->id = id;
new->pos[0] = pos[0];
new->pos[1] = pos[1];
new->prev = NULL;
new->next = NULL;

return new; }

// --- DLCL_INSERT ---
void	dlcl_insert(dlcl *list, char id, int pos[2]) {

dlcl	*l, *ll;

if (list==NULL)
	list = dlcl_new(id, pos);
else if (list->next==NULL) {
	list->next = dlcl_new(id, pos);
	list->prev = list->next;
	if (list->id>id)
		list = list->next;
}
else {
	if (list->id>id) {
		l = list->prev;
		list->prev = dlcl_new(id, pos);
		l->next = list->prev;
		list->prev->next = list;
		list->prev->prev = l;
		list = list->prev;
		return;
	}
	for (l=list->next; l!=list; l=l->next) {
		puts("coucou");
		if (l->id>id) {
			ll = l->next;
			l->next = dlcl_new(id, pos);
			l->next->next = ll;
			l->next->prev = l;
			ll->prev = l->next;
			return;
		}
	}
	l = list->prev;
	list->prev = dlcl_new(id, pos);
	l->next = list->prev;
	list->prev->next = list;
	list->prev->prev = l;
}

return; }

// --- DLCL_CLEAR ---
void	dlcl_clear(dlcl *list) {

dlcl	*l;

if (list==NULL)
	return;
else if (list->next==NULL) {
	free(list);
	return;
}
else {
	list->prev->next = NULL;
	while (list->next!=NULL) {
		l = list->next;
		free(list);
		list = l;
	}
}

return; }
