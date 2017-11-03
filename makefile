all: dirinfo.c
	gcc dirinfo.c
run: all
	./a.out
