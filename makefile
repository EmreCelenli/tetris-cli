main: main.o menu.o game.o scores.o 
	g++ -o main main.o menu.o game.o scores.o -lncurses

main.o: main.cpp main.hpp
	g++ -c main.cpp 

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

game.o: game.cpp game.hpp
	g++ -c game.cpp

scores.o: scores.cpp scores.hpp
	g++ -c scores.cpp