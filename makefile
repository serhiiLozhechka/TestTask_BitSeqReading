all: clean test

test: exe
	./test_app

utils: utils.c utils.h data_types.h
	gcc -c utils.c -o utils.o

exe: test_app.c utils
	gcc test_app.c utils.o -o test_app

clean:
	-rm test_app *.o 2>/dev/null
