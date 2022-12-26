CC=gcc -g
LIBS=-lopencv_core -lopencv_highgui -lopencv_imgproc -lstdc++ -ltiff
INCLUDE=-I/usr/include/opencv4
CFLAGS=-Wall -Werror $(INCLUDE)
LDFLAGS=$(LIBS)

MKDIR_P = mkdir -p
.PHONY: directories

all: directories spectator
spectator: obj/main.o obj/geometry.o obj/draw.o
	$(CC)  -o $@ $< $(CFLAGS) $(LDFLAGS)

obj/main.o: src/main.cpp src/geometry.h src/draw.h
	$(CC) -c src/main.cpp -o $@ $(CFLAGS)

obj/geometry.o: src/geometry.cpp src/geometry.h	
	$(CC) -c src/geometry.cpp -o $@

obj/draw.o: src/draw.cpp src/draw.h src/geometry.h
	$(CC) -c src/draw.cpp -o $@ $(CFLAGS)

directories: obj

obj:
	$(MKDIR_P) obj
