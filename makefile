main: main.o Menu.o Tetramino.o Grid.o
	g++ -o main main.o Menu.o Tetramino.o Grid.o -lncurses

main.o: main.cpp 
	g++ -c main.cpp 

Menu.o: Menu.cpp Menu.hpp
	g++ -c Menu.cpp

Tetramino.o: Tetramino.cpp Tetramino.hpp
	g++ -c Tetramino.cpp

Grid.o: Grid.cpp Grid.hpp
	g++ -c Grid.cpp
