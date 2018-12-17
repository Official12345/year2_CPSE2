build:
	g++ -std=c++17 main.cpp ball.cpp line.cpp picture.cpp rectangle.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system -lstdc++
	
run: build
	./game

clean:
	rm game
	rm -f *.o
