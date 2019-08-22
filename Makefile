install:
	rm -rf /usr/include/ratatouille
	mkdir /usr/include/ratatouille
	cp -t /usr/include/ratatouille/ curry.h pipe.h

tests:
	clang++ -Wall -std=c++14 curryTest.cc -o curryTest
	clang++ -Wall -std=c++14 pipeTest.cc -o pipeTest
	clang++ -Wall -pthread -std=c++14 threading-pipes-test.cc -o threading-pipes-test