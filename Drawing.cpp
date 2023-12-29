#include "Drawing.h"

Drawing::Drawing(){
	shapes = new ListLinked<Shape*>();
}
Drawing::~Drawing(){
	delete shapes;
}
void Drawing::add_front( Shape* shape){
	shapes->insert(0,shape);
}
void Drawing::add_back(Shape* shape){
	shapes->append(shape);
}
void Drawing::print_all(){
	Shape* s;
	for(int i=0; i< shapes->size(); i++){
		s = shapes->get(i);
		s->print();

	}
}
double Drawing::get_area_all_circles(){
	double area = 0;
	for(int i = 0; i<shapes->size();i++){
		if(Circle* c = dynamic_cast<Circle*>(shapes->get(i))){ 
			area+= c->area();
		}
	}
	return area;
}
void Drawing::move_squares(double incX, double incY){
	for(int i = 0; i< shapes->size(); i++){
		if(Square* c = dynamic_cast<Square*>(shapes->get(i))){
			c->translate(incX, incY);
		}
	}

}
