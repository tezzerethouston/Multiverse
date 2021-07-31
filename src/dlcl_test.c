#include <stdio.h>
#include "dlcl.h"

int	main (int ac, char **av) {

dlcl	*list, *head;

head = dlcl_new((int[2]){1, 2});
head->next = dlcl_new((int[2]){2, 3});
list = head->next;
for (int i=0; i<2; i++) {
	list->next = dlcl_new((int[2]){2, i});
	list = list->next;
}
list->next = head;
head->prev = list;

puts("Welcome to the dlcl test program.\n");
puts("List:\n");

list = head;
printf("{ %d, %d }\n", list->pos[0], list->pos[1]);
list = head->next;
while(list!=head) {
	printf("{ %d, %d }\n", list->pos[0], list->pos[1]);
	list = list->next; }

return 0; }
