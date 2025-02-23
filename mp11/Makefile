student: shape.hpp main.cpp
	g++ main.cpp shape.hpp -o mp11 

verify:  shape.hpp check.hpp verify.cpp gshape.hpp
	g++ -g -c shape.hpp -o shape.o 
	g++ -g -c verify.cpp -o verify.o
	g++ -g verify.o shape.hpp gshape.o check.cpp -o verify_mp11

clean:
	rm  shape.o verify.o mp11 verify_mp11
