install:
	rm -rf /usr/include/ratatouille
	mkdir /usr/include/ratatouille
	cp -t /usr/include/ratatouille/ curry.h pipe.h

curryTest:
	g++ curryTest.cc -o curryTest
pipeTest:
	g++ pipeTest.cc -o pipeTest
tests: curryTest pipeTest