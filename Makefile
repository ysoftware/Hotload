ARGS=-Wall -Wextra 

all: main lib
	@echo "Complete"
	@echo 

lib:
	mkdir -p build
	clang $(ARGS) -fPIC -c lib.c -o build/lib.o
	clang $(ARGS) -shared -o build/libmylibrary.so build/lib.o

main: 
	clang $(ARGS) -o main.app main.c
