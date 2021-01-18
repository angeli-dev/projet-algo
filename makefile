reversi: main.o fonctions.o
	g++ -o reversi main.o fonctions.o -Wall -lstdc++

main.o: main.cpp structure.h  appelFonctions.h 
	g++ -c main.cpp -Wall

fonctions.o: fonctions.cpp structure.h appelFonctions.h
	g++ -c fonctions.cpp -Wall

clean:
	rm -f *.o