install:
	rm -rf /usr/include/ratatouille
	mkdir /usr/include/ratatouille
	cp -t /usr/include/ratatouille/ curry.h pipe.h

tests:
	clang++ -Wall -std=c++11 curryTest.cc -o curryTest
	clang++ -Wall -std=c++11 pipeTest.cc -o pipeTest