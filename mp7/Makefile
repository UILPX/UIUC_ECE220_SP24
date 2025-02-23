
mp7: main.c sudoku.c
	g++ -g -c sudoku.c -o sudoku.o
	g++ -g -c main.c -o main.o
	g++ -g main.o sudoku.o sudoku_golden.a -o mp7

clean:
	rm *.o mp7

sudoku1: mp7
	./mp7 sudoku1.txt

sudoku2: mp7
	./mp7 sudoku2.txt

sudoku3: mp7
	./mp7 sudoku3.txt
