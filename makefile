
HEADERS = -I.\
		-I Ejercicio1/ARMAS/\
		-I Ejercicio1/ARMAS/Armas_combat/\
		-I Ejercicio1/ARMAS/Items_mag/\
		-I Ejercicio1/PERSONAJES/\
		-I Ejercicio1/PERSONAJES/Guerreros/\
		-I Ejercicio1/PERSONAJES/Magos/\
		-I Ejercicio2/\
		-I Ejercicio3/

SOURCES = Ejercicio1/PERSONAJES/Magos/*.cpp \
			Ejercicio1/PERSONAJES/Guerreros/*.cpp \
			Ejercicio1/ARMAS/Armas_combat/*.cpp \
			Ejercicio1/ARMAS/Items_mag/*.cpp \
			Ejercicio1/ARMAS/*.cpp \
			Ejercicio1/PERSONAJES/*.cpp \
			Ejercicio2/PersonajeFactory.cpp 


Ej2 : 
	g++ -std=c++17 -Wall -Wextra $(HEADERS) -g Ejercicio2/main2.cpp $(SOURCES) -o ejercicio2
	./ejercicio2
Ej3 : 
	g++ -std=c++17 -Wall -Wextra $(HEADERS) -g Ejercicio3/main3.cpp $(SOURCES) -o ejercicio3
	./ejercicio3
clean : 
		rm -f ejercicio2 ejercicio3
		rm -f *.dSYM/ 





