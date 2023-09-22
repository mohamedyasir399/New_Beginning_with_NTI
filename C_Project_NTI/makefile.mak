comp1 = gcc

target = C_Project_NTI.exe


build: main.o App.o

    $(comp1) main.o App.o -o $(target)



main.o: main.c App.h

    $(comp1) -c main.c


run:

    $(target)



clean:

    rm main.o App.o
