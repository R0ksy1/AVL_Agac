Tum: temizle derle bagla calistir

temizle:
	@cls || clear

derle:
	@echo "Derleme islemi basliyor..."
	g++ -g -c -I "./include" ./src/Main.cpp -o ./lib/Main.o
	g++ -g -c -I "./include" ./src/Tree.cpp -o ./lib/Tree.o
	g++ -g -c -I "./include" ./src/Node.cpp -o ./lib/Node.o
	g++ -g -c -I "./include" ./src/List.cpp -o ./lib/List.o
	g++ -g -c -I "./include" ./src/Helper.cpp -o ./lib/Helper.o

bagla:
	@echo "Baglama islemi basliyor..."
	g++ -g ./lib/Node.o ./lib/Tree.o ./lib/Helper.o ./lib/List.o ./lib/Main.o -o ./bin/program

calistir: bagla
	@./bin/program

clear:
	rm -f ./lib/*.o
	rm -f ./bin/program
