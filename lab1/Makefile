all: westernPainting chinesePainting
westernPainting: westernPaintingMain.o colors.o black.o
	g++ -o westernPainting westernPaintingMain.o colors.o black.o
westernPaintingMain.o: westernPaintingMain.cpp colors.h black.h
	g++ -c westernPaintingMain.cpp
colors.o: colors.cpp colors.h
	g++ -c colors.cpp
black.o: black.cpp black.h
	g++ -c black.cpp
chinesePainting: chinesePaintingMain.o whiteSpace.o black.o
	g++ -o chinesePainting chinesePaintingMain.o whiteSpace.o black.o
chinesePaintingMain.o: chinesePaintingMain.cpp whiteSpace.h black.h
	g++ -c chinesePaintingMain.cpp
whiteSpace.o: whiteSpace.cpp whiteSpace.h
	g++ -c whiteSpace.cpp
western: westernPainting
chinese: chinesePainting
clean:
	rm -rf *.o
	rm -rf *.out
