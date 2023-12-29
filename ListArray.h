#include "List.h"
#include <iostream>
#include <exception>
template <typename T>



class ListArray : public List<T>{
	private:
		T* arr;
		int max;
		int n;
		static int const MINSIZE=2;
		
		void resize( int new_size){
			T* newarr = new T[new_size]; 
			if(new_size < n){
				throw std::out_of_range("No se puede");
			}
			for(int x = 0; x < n; x++){
				newarr[x] = arr[x];
			}
			max = new_size;
			delete[] arr;
			arr = newarr;
			newarr = nullptr;
			delete newarr;
		
		}


	public:
		
		void insert(int pos, T e) override{
			if(pos < 0 || pos > size()){
				throw std::out_of_range("Posicion invalida");
			}
			if(size() == max){
			
				resize(size()*2);
				max = size()*2;
			}
			
			
			if(pos == 0){
				prepend(e);
			
			}else if(pos == size()){
				append(e);
			}else{
				for(int x = size(); x > pos; x--){
					arr[x] = arr[x-1];
				}
				arr[pos] = e;
				n++;
			
			}
				
		
		
		}
		void append(T e) override{
			if(size() == max){
				resize(size()*2);
				max = size()*2;
			}
			arr[size()] = e;	
			n++;
		}

		void prepend(T e) override{
			if(size() == max){
				resize(size()*2);
				max = size()*2;
			
			}

			for(int x = size(); x > 0; x--){
				arr[x] = arr[x-1];
		
			}
			arr[0] = e;
			n++;
		
		}
		T remove(int pos) override{
			if(pos > (size() - 1) || pos < 0){
				throw std::out_of_range("fuera de rango");
			} else {
				
				T x = arr[pos];
				
				
				if(pos<(max-1) && pos < size() - 1){
					for(int y = pos; y < size() - 1; y++){
						arr[y] = arr[y+1];
					
					}
				
				}
				
				n--;
				return x; 
			}
		}
	
		T get(int pos) override{
			if(pos > (size()-1)||pos<0){
				throw std::out_of_range("fuera de rango");
			
			}else{
				return arr[pos];
		
			}
		}

		int search( T e) override{
		
			for(int x = 0; x < size(); x++){
				if(arr[x] == e){
					return x;
				}
			
			}
			return -1;
		}

		bool empty() override{
			if(n == 0){
				return true;
			}else{
				return false;
			}
		
		}
		
		int size() override{
			return n;
		
		}
	
	
		ListArray(){
			arr = new T[MINSIZE]; 
			max = MINSIZE;
			n = 0;
		}


		~ListArray(){
			n = 0;
			delete[] arr;
		}


		T& operator[](int pos){
			if(pos > n || pos<0 ){
				throw std::out_of_range("fuera de rango");		
			
			}else{
				return arr[pos];
			}
		
		}

		friend std::ostream& operator<<(std::ostream &out,ListArray<T> &list){
			out << "List --> [" << std::endl;
			for(int x = 0; x < list.size(); x++){
			
				out << list[x] << std::endl;
			
			}

			out << "]" << std::endl;
			return out;	
		}

		friend ListArray<T> operator+(ListArray<T>& a, ListArray<T>& b){
			arr = new array;
			for(int i = 0; i < n; i+=2){
				if(a[i] < b[i]){
					arr[i] = a[i];
					arr[i+1] = b[i];
				}else{
					arr[i] = b[i];
					arr[i+1] = a[i];
				}
				if(i > 1 && a[i] < arr[i-1]){
					arr[i-1] = a[i];
					arr[i] = a[i-1];
				}
				if(i > 1 && b[i] < arr[i-1]){
					arr[i-1] = b[i];
					arr[i] = b[i-1];
				}
			}
			return arr;


		} 									
		


};

