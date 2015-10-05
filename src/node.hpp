#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <stdexcept>

template <class T>
class node{
    public:
        node(T value, node<T>* next):value(value),next(next){
            //std::cout << "[Hello world, i am a new node on address::"<<this<<"]" << std::endl;
        }
        //node(const node<T>& rhs){std::cout << "[COPY] to address::["<<this<<"]" << std::endl;}
        ~node(){
            //std::cout << "[Goodbye cruel world, i was a node on address::"<<this<<"]" << std::endl;
        }
		node<T>& operator=(const node<T>& rhs){std::cout << "assign" << std::endl;}
        const node<T>* operator++(int i) const{
            //std::cout << "[Node]::[const operator++]::[" << i << " " << this->next <<"]" << std::endl;
            return this->next;
        }
        node<T>* operator++(int i){
            //std::cout << "[Node]::[operator++]::[" << i << " " << this->next <<"]" << std::endl;
            return const_cast < node<T>* >(static_cast < const node<T> >(*this)++);
        }
		void swap(node<T>* other){
			T tmp = this->value;
			this->value = other->value;
			other->value = tmp;
        }
        T value;
		node<T>* next;
};
#endif
