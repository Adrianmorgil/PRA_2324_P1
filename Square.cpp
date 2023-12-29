#include "Rectangle.h"
#include "Shape.h"
#include "Point2D.h"
#include "Square.h"
#include <iostream>


Square::Square(){
	
	vs = new Point2D[N_VERTICES];
	vs[0]={-1,1};
	vs[1] = {1,1};
	vs[2] = {1,-1};
	vs[3] = {-1,-1};

}

Square::Square(std::string color, Point2D* vertices){
	vs = new Point2D[N_VERTICES];
	set_color(color);
	for (int i = 0; i < N_VERTICES; i++) {
	     	vs[i] = vertices[i];
	}

}


std::ostream& operator<<(std::ostream &out, const Square &square){
			
	out <<"COLOR:"<<square.getcolor() << " " <<square.get_vertex(0) << square.get_vertex(1) << square.get_vertex(2) << square.get_vertex(3);
	return out;
					
}
