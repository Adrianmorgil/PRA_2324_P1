#include "Rectangle.h"
#include "Shape.h"
#include "Point2D.h"


Rectangle::Rectangle():Shape(){
	vs = new Point2D[N_VERTICES];
	vs[0]={-1,0.5};
	vs[1] = {1,0.5};
	vs[2] = {1,-0.5};
	vs[3] = {-1,-0.5};
			
}

Rectangle::Rectangle(std::string color, Point2D* vertices):Shape(color){
	vs = new Point2D[N_VERTICES];
	for (int i = 0; i < N_VERTICES; i++) {
        	vs[i] = vertices[i];
    	}
		
}

Rectangle::Rectangle(const Rectangle &r){	
	vs = new Point2D[N_VERTICES];
	color = r.color;
	for (int i = 0; i < N_VERTICES; i++) {
       		vs[i] = r.vs[i];
    	}
}

Rectangle::~Rectangle(){
	delete[] vs;
		
}

Point2D Rectangle::get_vertex(int ind) const{
	if(ind < 0 || ind >=  N_VERTICES){
		throw std::out_of_range("Numero de vertices no valido");
			
	}
	return vs[ind];	
		
}

Point2D Rectangle::operator[](int ind) const{
		
	if(ind < 0 || ind >=  N_VERTICES){
		throw std::out_of_range("Numero de vertices no valido");
			
	}
	return vs[ind];	
		
}
void Rectangle::set_vertices(Point2D* vertices){
		
	if( check(vertices)){
			
		for(int x=0;x< N_VERTICES; x++){
				
			vs[x] = vertices[x];
				
		}
			
	}else{
		throw std::invalid_argument("No forman un rectanglo valido");
			
	}
		
		
		
}
		
		

Rectangle& Rectangle::operator=(const Rectangle &r){
	this->color = r.color;
	for (int i = 0; i < N_VERTICES; i++) {
        	vs[i] = r.vs[i];
    	}
	return *this;
		
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r){
		
	out <<"COLOR:"<<r.color << " " <<r.vs[0] << r.vs[1] << r.vs[2] << r.vs[3];
	return out;
		
}


