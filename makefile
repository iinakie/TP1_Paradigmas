
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

Ej1 : 
	g++ -std=c++17 -Wall -Wextra $(HEADERS) -g Ejercicio1/main1.cpp $(SOURCES) -o ej1
	./ej1
Ej2 : 
	g++ -std=c++17 -Wall -Wextra $(HEADERS) -g Ejercicio2/main2.cpp $(SOURCES) -o ej2
	./ej2
Ej3 : 
	g++ -std=c++17 -Wall -Wextra $(HEADERS) -g Ejercicio3/main3.cpp $(SOURCES) -o ej3
	./ej3
clean : 
		rm -f ej1 ej2 ej3
		rm -f *.dSYM/ 





