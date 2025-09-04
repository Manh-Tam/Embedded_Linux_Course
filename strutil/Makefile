all: static shared

static:
	gcc -c bstrutils.c -o strutils.o
	ar rcs libstrutils.a strutils.o
	gcc main.c -L. -lstrutils -o main_static
shared:
	gcc -fPIC -c bstrutils.c -o strutils.o
	gcc -shared -o libstrutils.so strutils.o
	gcc main.c -L. -lstrutils -o main_shared
run:
	./main_static
run_shared:
	LD_LIBRARY_PATH=. ./main_shared
clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf *.so