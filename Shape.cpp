#include "Shape.h"
#include <string>
Shape::Shape(){
	color="red";
}
Shape::Shape( std::string color){
	if(color!= "red" && color!="green" && color !="blue"){
		throw std::invalid_argument("Color incorrecto");
			
	}
	this -> color = color;
		
}

std::string Shape::getcolor() const{
		
	return color;
}

void Shape::set_color(std::string c){
		
	if(c!= "red" && c!="green" && c!="blue"){
		throw std::invalid_argument("Color incorrecto");
			
	}
	color = c;	
		
}


