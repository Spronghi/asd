#ifndef DOUBLE_LINKED_NODE_HPP
#define DOUBLE_LINKED_NODE_HPP
#include <iostream>
#include <stdexcept>

template <class T>
class double_linked_node{
    public:
        double_linked_node(T value, double_linked_node<T>* prev, double_linked_node<T>* next):value(value),prev(prev),next(next){
            //std::cout << "[Hello world, i am a new double linked node on address::"<<this<<"]" << std::endl;
        }
        ~double_linked_node(){
            //std::cout << "[Goodbye cruel world, i was a double linked node on address::"<<this<<"]" << std::endl;
        }
        const double_linked_node<T>* operator++(int i) const{
            //std::cout << "[Node]::[const operator++]::[" << i << " " << this->next <<"]" << std::endl;
            return this->next;
        }
        double_linked_node<T>* operator++(int i){
            //std::cout << "[Node]::[operator++]::[" << i << " " << this->next <<"]" << std::endl;
            return const_cast < double_linked_node<T>* >(static_cast < const double_linked_node<T> >(*this)++);
        }
        const double_linked_node<T>* operator--(int i) const{
            //std::cout << "[Node]::[const operator--]::[" << i << " " << this->prev <<"]" << std::endl;
            return this->prev;
        }
        double_linked_node<T>* operator--(int i){
            //std::cout << "[Node]::[operator--]::[" << i << " " << this->prev <<"]" << std::endl;
            return const_cast < double_linked_node<T>* >(static_cast < const double_linked_node<T> >(*this)--);
        }
		void swap(double_linked_node<T>* other){
			T tmp = this->value;
			this->value = other->value;
			other->value = tmp;
        }
        T value;
        double_linked_node<T>* prev;
        double_linked_node<T>* next;
};

#endif
