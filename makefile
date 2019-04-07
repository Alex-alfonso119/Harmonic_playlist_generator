OBJ = main.o functions.o

playlist_generator: $(OBJ)
	g++ -o playlist_generator $(OBJ)

functions.o: functions.h

playlist_generator.o:

.PHONY:
	clean

clean:
	rm playlist_generator $(OBJ)
