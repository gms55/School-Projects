#makefile

a.out: ItemType.o Queue.o TreeNode.o 
	g++  TestCasesDriver.cpp ItemType.o Queue.o TreeNode.o

ItemType.o: ItemType.cpp ItemType.h
	g++ -c ItemType.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

TreeNode.o: TreeNode.cpp TreeNode.h
	g++ -c TreeNode.cpp


