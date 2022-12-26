CC=gcc -g
LIBS=-lopencv_core -lopencv_highgui -lopencv_imgproc -lstdc++ -ltiff
INCLUDE=-I/usr/include/opencv4
CFLAGS=-Wall -Werror $(INCLUDE)

spectator: src/main.cpp
	$(CC) src/main.cpp -o spectator $(CFLAGS) $(LIBS)
