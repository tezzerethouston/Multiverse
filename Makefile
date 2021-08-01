all:
	gcc -o bin/Multiverse -l ncurses -I inc src/main.c src/game.c src/tools.c src/dlcl.c src/str.c
dlcl:
	gcc -o bin/dlcl-test -I inc src/dlcl_test.c src/dlcl.c
