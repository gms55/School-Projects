#makefile

a.out: ItemType.o TestCases.o
	g++ ItemType.cpp TestCases.cpp

ItemType.o: ItemType.cpp ItemType.h
	g++ -c ItemType.cpp

TestCases.o: TestCases.cpp UnsortedList.h
	g++ -c TestCases.cpp
