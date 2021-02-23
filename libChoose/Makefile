libChoose.a: choose.o
		ar rcs $@ $^ 

choose.o: choose.cpp choose.hpp
		g++ -std=c++11 -fPIC -c choose.cpp -o choose.o

clean:
	rm -f *.o *.a
