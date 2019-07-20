CF = -Wall -pedantic

default: main.o Pixel.o Image.o
	g++ main.o Pixel.o Image.o -o exe
	./exe
	timeout 1s eog chaos.bmp

main.o: main.cpp
	g++ $(CF) -c main.cpp -o main.o

clean:
	rm main.o exe

preview:
	eog chaos.bmp
