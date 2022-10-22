calculate : calMain.o ./lib/add.o ./lib/substract.o ./lib/multiply.o ./lib/divide.o
	gcc -o calculate calMain.o ./lib/add.o ./lib/substract.o ./lib/multiply.o ./lib/divide.o -L./lib
calMain.o : calMain.c
	gcc -c calMain.c
./lib/add.o : ./lib/add.c
	gcc -c ./lib/add.c
./lib/substract.o : ./lib/substract.c
	gcc -c ./lib/substract.c
./lib/multiply.o : ./lib/multiply.c
	gcc -c ./lib/multiply.c
./lib/divide.o : ./lib/divide.c
	gcc -c ./lib/divide.c
clean:
	rm -f calculate calMain.o ./lib/add.o ./lib/substract.o ./lib/multiply.o ./lib/divide.o
