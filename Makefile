bin/TestListArray: TestListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/TestListArray TestListArray.cpp ListArray.h List.h

bin/testnode: TestNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/TestNode TestNode.cpp Node.h

bin/testlinked: testListLinked.cpp ListLinked.h List.h Node.h
	mkdir -p bin
	g++ -o bin/testlinked testListLinked.cpp ListLinked.h Node.h

bin/testPoint2D: testPoint2D.cpp Point2D.h
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.cpp Point2D.h

bin/testshape: Shape.h Shape.cpp Point2D.h
	mkdir -p bin
	g++ -o Point2D Point2D.h 
	g++ -o Shape Shape.h Shape.cpp 

bin/testcircle: testcircle.cpp Circle.h Shape.cpp Shape.h Point2D.h 
	mkdir -p bin
	g++ -o bin/testcircle testcircle.cpp Circle.h Shape.cpp Point2D.h	

bin/testrectangle: testrectangle.cpp Rectangle.h Shape.cpp Shape.h Point2D.h  
	mkdir -p bin
	g++ -c Shape.o Shape.h Shape.cpp
	g++ -c Rectangle.o Rectangle.h Rectangle.cpp
	g++ -o bin/testrectangle testrectangle.cpp Rectangle.o Shape.o Point2D.h

bin/testsquare: testsquare.cpp Rectangle.h Rectangle.cpp Shape.h Shape.cpp Point2D.h Square.h Square.cpp
	mkdir -p bin
	g++ -c Shape.o Shape.h Shape.cpp
	g++ -c Rectangle.o Rectangle.h Rectangle.cpp
	g++ -c Square.o Square.h Square.cpp
	g++ -o bin/testsquare testsquare.cpp Rectangle.o Shape.o Point2D.h Square.o
bin/testdrawing: testdrawing.cpp List.h ListLinked.h Node.h Point2D.h Shape.h Shape.cpp Circle.h Rectangle.h Rectangle.cpp Square.h Square.cpp Drawing.h Drawing.cpp
	mkdir -p bin
	g++ -c Shape.o Shape.h Shape.cpp
	g++ -c Rectangle.o Rectangle.h Rectangle.cpp
	g++ -c Square.o Square.h Square.cpp
	g++ -c Drawing.o Drawing.h Drawing.cpp
	g++ -o bin/testdrawing testdrawing.cpp ListLinked.h Node.h Point2D.h Shape.o Circle.h Rectangle.o Square.o Drawing.o
	./bin/testdrawing
clean:
	rm -r *.o *gch bin

