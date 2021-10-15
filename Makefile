LINKS= -lsfml-graphics -lsfml-window -lsfml-system

flight-editor: main.o
	g++ $? $(LINKS) -o $@ 

main.o: main.cpp
	g++ -c $? -o $@

