PROGS = game

all: ${PROGS}


game: Location.o Plains.o Plateau.o Valley.o Forest.o River.o Mine.o Cave.o Hideout.o Inventory.o Character.o Player.o Henchman.o Grizzly.o Diablo.o Game.o gameMain.o
	g++ -g Location.o Plains.o Plateau.o Valley.o Forest.o River.o Mine.o Cave.o Hideout.o Inventory.o Character.o Player.o Henchman.o Grizzly.o Diablo.o Game.o gameMain.o -o game


Location.o: Location.cpp Location.hpp
	g++ -c Location.cpp

Plains.o: Plains.cpp Plains.hpp
	g++ -c Plains.cpp

Plateau.o: Plateau.cpp Plateau.hpp
	g++ -c Plateau.cpp

Valley.o: Valley.cpp Valley.hpp
	g++ -c Valley.cpp

Forest.o: Forest.cpp Forest.hpp
	g++ -c Forest.cpp

River.o: River.cpp River.hpp
	g++ -c River.cpp

Mine.o: Mine.cpp Mine.hpp
	g++ -c Mine.cpp

Cave.o: Cave.cpp Cave.hpp
	g++ -c Cave.cpp

Hideout.o: Hideout.cpp Hideout.hpp
	g++ -c Hideout.cpp

Inventory.o: Inventory.cpp Inventory.hpp
	g++ -c Inventory.cpp

Character.o: Character.cpp Character.hpp
	g++ -c Character.cpp

Player.o: Player.cpp Player.hpp
	g++ -c Player.cpp

Henchman.o: Henchman.cpp Henchman.hpp
	g++ -c Henchman.cpp

Grizzly.o: Grizzly.cpp Grizzly.hpp
	g++ -c Grizzly.cpp

Diablo.o: Diablo.cpp Diablo.hpp
	g++ -c Diablo.cpp

Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp

gameMain.o: gameMain.cpp
	g++ -c gameMain.cpp


clean:
	rm -f ${PROGS} *.o *~
