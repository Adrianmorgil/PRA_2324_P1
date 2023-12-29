#include <iostream>
template <typename T>

class Node{
	public:
		T data;
		Node<T>* next;
		Node(T data, Node<T>* next=nullptr){
			this-> data = data;
			this-> next = next;
		
		
		}
		friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
			for(Node<T> x : node){
				out << x.data<< std::endl;
			}
			return out;
		
		}
};
