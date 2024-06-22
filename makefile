tetris: main.o Menu.o Tetramino.o Grid.o Scores.o Classifica.o
	g++ -std=c++20 -o tetris main.o Menu.o Tetramino.o Grid.o Scores.o Classifica.o -lncurses

main.o: main.cpp 
	g++ -std=c++20 -c main.cpp 

Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++20 -c Menu.cpp

Tetramino.o: Tetramino.cpp Tetramino.hpp
	g++ -std=c++20 -c Tetramino.cpp

Grid.o: Grid.cpp Grid.hpp
	g++ -std=c++20 -c Grid.cpp

Scores.o: Scores.cpp Scores.hpp
	g++ -std=c++20 -c Scores.cpp 

Classifica.o: Classifica.cpp Classifica.hpp
	g++ -std=c++20 -c Classifica.cpp