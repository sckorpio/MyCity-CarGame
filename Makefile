GRL = -lGL -lGLU -lglut

all: hello

hello: CITY.o MYUTILITY.o BUILDING.o CAMERA.o CAR.o ROAD.o MOTION.o FLAG.o METER.o STOPWATCH.o ALL.o MENU.o GAME.o DRIVE.o XPLORE.o CONTROLS.o CREDITS.o run.o
	g++ CITY.o MYUTILITY.o BUILDING.o CAMERA.o CAR.o ROAD.o MOTION.o FLAG.o METER.o STOPWATCH.o ALL.o MENU.o GAME.o DRIVE.o XPLORE.o CONTROLS.o CREDITS.o run.o -o hello $(GRL)


MYUTILITY.o: MYUTILITY.cpp
	g++ -c MYUTILITY.cpp $(GRL) 



BUILDING.o: BUILDING.cpp
	g++ -c BUILDING.cpp $(GRL)

CAMERA.o: CAMERA.cpp
	g++ -c CAMERA.cpp $(GRL)

CAR.o: CAR.cpp
	g++ -c CAR.cpp $(GRL)

ROAD.o: ROAD.cpp
	g++ -c ROAD.cpp $(GRL)

MOTION.o: MOTION.cpp
	g++ -c MOTION.cpp $(GRL)

CITY.o: CITY.cpp
	g++ -c CITY.cpp $(GRL)

FLAG.o: FLAG.cpp
	g++ -c FLAG.cpp $(GRL)	

METER.o: METER.cpp
	g++ -c METER.cpp $(GRL)	

STOPWATCH.o: STOPWATCH.cpp
	g++ -c STOPWATCH.cpp $(GRL)	

MENU.o: MENU.cpp
	g++ -c MENU.cpp $(GRL)	

GAME.o: GAME.cpp
	g++ -c GAME.cpp $(GRL)	

DRIVE.o: DRIVE.cpp
	g++ -c DRIVE.cpp $(GRL)	

XPLORE.o: XPLORE.cpp
	g++ -c XPLORE.cpp $(GRL)	

CONTROLS.o: CONTROLS.cpp
	g++ -c CONTROLS.cpp $(GRL)	

CREDITS.o: CREDITS.cpp
	g++ -c CREDITS.cpp $(GRL)			
		

run.o: run.cpp
	g++ -c run.cpp $(GRL)	







clean:
	rm -rf *o hello