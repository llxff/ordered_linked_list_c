build:
	mkdir -p bin
	gcc src/main.c src/ollist.c -o bin/main

run:
	make build
	bin/main

tests:
	mkdir -p bin
	gcc src/test.c src/ollist.c src/expect.c -o bin/test
	bin/test
