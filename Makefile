all: compile link

compile:
	g++ -c main.cpp particle.cpp -IC:\Users\user\OneDrive\Dokumenty\Libraries\SFML-2.5.1\include -DSFML_STATIC
link:
	g++ main.o particle.o -o main -LC:\Users\user\OneDrive\Dokumenty\Libraries\SFML-2.5.1\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 
clean:
	rm -f main *.o