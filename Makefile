TARGET= mp3_explorer
cc= gcc
CFLAGS= -Wall -pedantic -O3 -c
LFLAGS= -Wall

all: $(TARGET)

$(TARGET): main.o mp3_explorer.o ADT_vector.o ADT_track.o
	$(cc) $(LFLAGS) -o $(TARGET) main.o mp3_explorer.o ADT_vector.o ADT_track.o
main.o: types.h mp3_explorer.h ADT_vector.h ADT_track.h ADT_vector_prototypes.h ADT_track_prototypes.h
	$(cc) $(CFLAGS) -o main.o main.c
mp3_explorer.o: types.h mp3_explorer.h
	$(cc) $(CFLAGS) -o mp3_explorer.o mp3_explorer.c
ADT_vector.o: types.h ADT_vector.h ADT_vector_prototypes.h
	$(cc) $(CFLAGS) -o ADT_vector.o ADT_vector.c
ADT_track.o: types.h ADT_track.h ADT_track_prototypes.h
	$(cc) $(CFLAGS) -o ADT_track.o ADT_track.c
clean:
	rm *.o

release: $(TARGET)
