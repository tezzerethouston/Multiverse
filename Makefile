all:
	gcc -o Multiverse -l ncurses -I inc src/main.c src/game.c src/tools.c src/dlcl.c
dlcl:
	gcc -o dlcl-test -I inc src/dlcl_test.c src/dlcl.c
