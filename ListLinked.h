#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <iostream>
#include <exception>
#include "List.h"
#include "Node.h"


template <typename T>
class ListLinked : public List<T> {
	private:
		Node<T>* first;
		int n;
	public:
		//Metodos heredados
		virtual void insert(int pos, T e){
		
			if(pos<0 || pos>size()){
				throw std::out_of_range("Posicion invalida");
			
			}
		
			if(pos==0){
				prepend(e);
			}else if(pos==n){
				append(e);
			}else{
				Node<T>* aux = first->next;
				Node<T>* nuevo=new Node<T>(e,nullptr);
				Node<T>* prev = first;

				for(int x=0;x<size();x++){
					if(x == pos-1 ){
						prev->next = nuevo;
						nuevo->next = aux;
						n++;
						break;
					}
					prev=aux;
					aux=aux->next;	
				}
			}
		
		}

		virtual void append( T e){
			Node<T>* aux = first->next;
			Node<T>* prev= first;
			while(aux!=nullptr){
				prev=aux;
				aux=aux->next;
			}
			prev->next = new Node<T>(e,nullptr);
			n++;

		}

		virtual void prepend( T e){
			Node<T>* aux = first;
			Node<T>* nuevo=new Node<T>(e,nullptr);
			first = nuevo;
			first ->next = aux;
			n++;
		}

		virtual T remove(int pos){
			if(pos<0 || pos >(size()-1)){
				throw std::out_of_range("Posicion invalida");
			
			} else {

				Node<T>* aux = first;
				Node<T>* prev = nullptr;
				for(int x=0; x<size();x++){
					if(x==pos&&pos==0){
					
						first = first->next;
						n--;
						return aux->data;

					}else if(x==pos && pos ==size()-1){
					
						prev->next =nullptr;
						n--;
						return aux->data;

					}else if(x==pos){
					
						prev->next = aux->next;
						n--;
						return aux->data;
					
					}
					prev=aux;
					aux = aux->next;
				}	return aux->data;
			}
		}

		virtual T get(int pos){
			if(pos>size()-1 || pos < 0){
				throw std::out_of_range("Posicion invalida");
			}else{
				Node<T>* aux=first;
				for( int x=0;x<n;x++){
					if(x==pos){

						return aux->data;
					}
					aux=aux->next;
					return aux->data;	
				}
			}
		
		}

		virtual int search( T e){
			Node<T>* aux=first;
			for(int x=0;x<n;x++){
				if(aux->data == e){
					
					return x;
				}
				aux=aux->next;
		
			}
			
			return -1;
		
		
		}
		
		
		virtual bool empty(){
			if(n==0){
				return true;
			}
			return false;
		}

		virtual int size(){
			return n;
		}

		//Metodos de la clase
		ListLinked(){
			
			first=nullptr;
			n=0;
		}
		~ListLinked(){
			Node<T>* aux=first->next;
			while(aux!=nullptr){
				delete first;
				first = aux;
				aux = aux->next;
			}

			delete first;
			
		}
		T operator[](int pos){
			if(pos>n){
				throw std::out_of_range("fuera de rango");
			}
			Node<T>* aux=first;
			for(int x=0;x<n;x++){
				if(x==pos){
					return aux->data;
				}
				aux=aux->next;
			}
			return -1;
		
			
		
		}
		
		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			Node<T>* aux=list.first;
			out<<"-->["<<std::endl;	
			while(aux!=nullptr){
				out<< aux->data <<std::endl;
				aux=aux->next;
			}
			out<<"]"<<std::endl;	
			return out;
		}



};

#endif 
