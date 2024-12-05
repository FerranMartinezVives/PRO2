OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
#
program.exe: program.o Conjunt_Categories.o Conjunt_Tornejos.o Ranking.o
	g++ -o program.exe *.o
#
Conjunt_Categories.o: Conjunt_Categories.cc Conjunt_Categories.hh
	g++ -c Conjunt_Categories.cc $(OPCIONS)
Partit.o: Partit.cc Partit.hh
	g++ -c Partit.cc $(OPCIONS)
Torneig.o: Torneig.cc Torneig.hh Partit.hh Partit.o BinTree.hh
	g++ -c Torneig.cc $(OPCIONS)
Jugador.o: Jugador.cc Jugador.hh
	g++ -c Jugador.cc $(OPCIONS)
Conjunt_Tornejos.o: Conjunt_Tornejos.cc Conjunt_Tornejos.hh Torneig.hh Torneig.o
	g++ -c Conjunt_Tornejos.cc $(OPCIONS)
Ranking.o: Ranking.cc Ranking.hh Jugador.hh Jugador.o
	g++ -c Ranking.cc $(OPCIONS)
#
program.o: program.cc
	g++ -c program.cc $(OPCIONS)
# Esta última opción sirve para limpiar el directorio de ficheros
# innecesarios; se ejecuta mediante el comando "make clean"
#
clean:
	rm *.o
	rm *.exe
