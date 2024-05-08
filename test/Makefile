compile :
				g++ -c *.cpp

run :
				g++ *.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

start : 
				./sfml-app


r :
				make compile;make run; make start

testc : 
		g++ -c *.cpp

testr :
	  g++ *.o -o test-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

tests : 
		./test-app

t : 
	make testc;make testr;make tests


