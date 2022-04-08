project3.x: main.o JSONToken.o JSONTokenizer.o JSONParser.o EntitySet.o EntityInstance.o Pair.o EquityStats.o
	g++ -std=c++17 main.o JSONToken.o JSONTokenizer.o JSONParser.o EntitySet.o EntityInstance.o  Pair.o  EquityStats.o -o project3.x
main.o: main.cpp JSONTokenizer.hpp JSONToken.hpp JSONParser.hpp EntityInstance.hpp EntitySet.hpp EquityStats.o
	g++ -std=c++17 main.cpp -o main.o -c 
JSONToken.o: JSONToken.cpp JSONToken.hpp 
	g++ -std=c++17 JSONToken.cpp -o JSONToken.o -c 
JSONTokenizer.o: JSONTokenizer.cpp JSONTokenizer.hpp JSONToken.hpp 
	g++ -std=c++17 JSONTokenizer.cpp  -o JSONTokenizer.o -c 
Pair.o: Pair.cpp Pair.hpp 
	g++ -std=c++17 Pair.cpp -o Pair.o -c 
JSONParser.o: JSONParser.cpp JSONParser.hpp JSONTokenizer.hpp JSONToken.hpp EntityInstance.hpp EntitySet.hpp Pair.hpp
	g++ -std=c++17 JSONParser.cpp -o JSONParser.o -c   
EntitySet.o: EntitySet.cpp EntitySet.hpp EntityInstance.hpp 
	g++ -std=c++17 EntitySet.cpp -o EntitySet.o -c
EntityInstance.o: EntityInstance.cpp EntityInstance.hpp Pair.hpp JSONParser.hpp
	g++ -std=c++17 EntityInstance.cpp -o EntityInstance.o -c
EquityStats.o: EquityStats.cpp EquityStats.hpp EntitySet.hpp EntityInstance.hpp 
	g++ -std=c++17 EquityStats.cpp -o EquityStats.o -c 
clean:
	rm *.o *.x
 
