#ifndef DOUBLE_LINKED_LIST_HPP
#define DOUBLE_LINKED_LIST_HPP
#include "double_linked_node.hpp"

template <class T>
class double_linked_list{
    public:
        double_linked_list():top(0),length(0){
            std::cout << "[Hello world, I'm a new double linked list on address::"<<this<<"]"<< std::endl;
        }
        ~double_linked_list(){
            this->free_();
            std::cout << "[Goodbye cruel world, I was a double linked list on address::"<<this<<"]"<< std::endl;
        }
        std::size_t size(){
            return (this->length);
        }
        void append(std::size_t position, T value){
            std::cout << "append::position::[" << position << "]"<< std::endl;
            if((this->length+1) >= position && position >0){
                int current_position = 1;
                double_linked_node<T>* next = this->top;
                double_linked_node<T>* prev = NULL;
                while(position != current_position){
                    current_position++;
                    prev = next;
                    if(prev && prev->next)
                        next = (*prev)++;
                    else
                        next = NULL;
                }
                this->length++;
                this->push_(prev, next, value);
                std::cout << "prev::" << prev << "::next::" << next << std::endl;
            }else{
                this->free_();
                throw std::invalid_argument("cannot append");
            }
        }
        double_linked_node<T>* pop(std::size_t position){
            std::cout<< "pop::position::[" << position << "], ";
            if(this->length >= position && position >0){
                double_linked_node<T>* next = this->top;
                double_linked_node<T>* prev = NULL;
                int current_position = 1;
                while(current_position != position){
                    current_position++;
                    prev = next;
                    if(prev && prev->next)
                        next = (*prev)++;
                    else
                        next = NULL;
                }
                std::cout << ", address::[" << next << "] "<< std::endl;
                this->length--;
                this->remove_(prev, next);
                return next;
            }else{
                this->free_();
                throw std::invalid_argument("cannot pop");
            }
        }
        void print(){
            double_linked_node<T>* iterator = this->top;
            int position = 1;
            std::cout << "double linked list length::[" << this->size() << "]" << std::endl;
            while(iterator){
                try{
                    iterator->value.print();
                }catch(std::exception& e){
                    std::cout << "[EXCEPTION]::[Node]::element in position::[" << position << "]";
                    std::cout << ", address::[" << iterator << "]" << std::endl;
                }
                position++;
                if(iterator->next)
                    iterator = (*iterator)++;
                else
                    iterator = NULL;
            }
        }
        void bubble_sort(){
            if(this->size()){
                std::cout << "sort::forward list on address::[" << this << "]" << std::endl;
                int current_position = 1;
                bool sorted = false;
                while(( current_position != this->size() ) && !sorted ){
                    sorted = true;
                    current_position++;
                    double_linked_node<T>* next = this->top;
                    double_linked_node<T>* prev = NULL;
                    while(next){
                        prev = next;
                        if(prev && prev->next){
                            next = (*prev)++;
                            if(prev->value > next->value){
                                sorted = false;
                                prev->swap(next);
                            }
                        }else{
                            next = NULL;
                        }
                    }
                }
                std::cout << "sorted!" <<std::endl;
            }else{
                throw std::invalid_argument("cannot sort");
            }
        }
    private:
        void push_(double_linked_node<T>* prev, double_linked_node<T>* next, T value){
            double_linked_node<T>* tmp = new double_linked_node<T>(value, prev, next);
            if(!prev && !next)
                this->top = tmp;
            else if(!prev)
                this->top = tmp;
            else if(!next){
                prev->next = tmp;
            }else{
                prev->next = tmp;
                next->prev = tmp;
            }
        }
        void remove_(double_linked_node<T>* prev, double_linked_node<T>* next){
            if(!prev){
                this->top = this->top->next;
            }else if(!next){
                prev->next = NULL;
            }else{
                prev->next = next->next;
                next->next->prev = prev;
            }
            delete next;
        }
        void free_(){
            double_linked_node<T>* next = this->top;
            double_linked_node<T>* prev = NULL;
            int position = 1;
            std::cout << "double linked list length::[" << this->size() << "]" << std::endl;
            while(next){
                std::cout << "element in position::[" << position << "]";
                std::cout << "::address::[" << next << "] ";
                position++;
                prev = next;
                if(prev && prev->next)
                    next = (*prev)++;
                else
                    next = NULL;
                delete prev;
                std::cout << "freed!" << std::endl;
            }
            this->length=0;
        }
        std::size_t length;
        double_linked_node<T>* top;
};
#endif
