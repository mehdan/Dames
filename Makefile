SOURCE=Game.cpp Player.cpp include/Player.h Pawn.cpp include/Pawn.h Square.cpp include/Square.h
MYPROGRAM=game
MYINCLUDES=include

CC=g++ -std=c++11

#------------------------------------------------------------------------------



all: $(MYPROGRAM)



$(MYPROGRAM): $(SOURCE)

	$(CC) -I$(MYINCLUDES) $(SOURCE) -o$(MYPROGRAM)

clean:

	rm -f $(MYPROGRAM)


