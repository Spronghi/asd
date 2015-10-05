#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP
#include "node.hpp"

template <class T>
class forward_list{
    public:
        forward_list():top(0),length(0){
            std::cout << "[Hello world, I'm a new forward list on address::"<<this<<"]"<< std::endl;
        }
        ~forward_list(){
            this->free_();
            std::cout << "[Goodbye cruel world, I was a forward list on address::"<<this<<"]"<< std::endl;
        }
        std::size_t size(){
            return (this->length);
        }
        void append(std::size_t position, T value){
            std::cout << "append::position::[" << position << "]::value::[" << value <<"] ";
            if((this->length+1) >= position && position >0){
                int current_position = 1;
                node<T>* next = this->top;
                node<T>* prev = NULL;
                while(position != current_position){
                    current_position++;
                    prev = next;
                    if(prev && prev->next)
                        next = (*prev)++;
                    else
						next = NULL;
                }
                this->push_(prev, next, value);
                std::cout << "prev::" << prev << "::next::" << next << std::endl;
            }else{
                this->free_();
                throw std::invalid_argument("cannot append");
            }
        }
        node<T>* pop(std::size_t position){
            std::cout<< "pop::position::[" << position << "]"<< std::endl;
            if(this->length >= position && position >0){
                node<T>* next = this->top;
                node<T>* prev = NULL;
                int current_position = 1;
                while(current_position != position){
                    current_position++;
                    prev = next;
                    if(prev && prev->next)
                        next = (*prev)++;
                    else
                        next = NULL;
                }
                std::cout << "value::[" << next->value << "]";
                std::cout << ", position::[" << position << "]";
                std::cout << ", address::[" << next << "] " << std::endl;
                this->remove_(prev, next);
                return next;
            }else{
                this->free_();
                throw std::invalid_argument("cannot pop");
            }
        }
        void print(){
            node<T>* iterator = this->top;
            int position = 1;
            std::cout << "forward list length::[" << this->size() << "]" << std::endl;
            while(iterator){
				std::cout<< "element in position::["<<position<<"], value::["<<iterator->value<<"], address::["<<iterator<<"]"<<std::endl;
				/*
                try{
                    iterator->value.print();
                }catch(std::exception& e){
                    std::cout << "[EXCEPTION]::[Node]::element in address::[" << iterator << "]";
                    std::cout << ", address::[" << iterator << "]" << std::endl;
                }
                */
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
                    node<T>* next = this->top;
                    node<T>* prev = NULL;
                    while(next){
                        prev = next;
                        if(prev && prev->next){
                            next = (*prev)++;
                            if(prev->value < next->value){
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
        void push_(node<T>* prev, node<T>* next, T value){
            node<T>* tmp = new node<T>(value, next);
            this->length++;
            if(!prev && !next)
                this->top = tmp;
            else if(!prev)
                this->top = tmp;
            else
                prev->next = tmp;
        }
        void remove_(node<T>* prev, node<T>* next){
            this->length--;
            if(!prev){
                this->top = this->top->next;
            }else if(!next){
                prev->next = NULL;
            }else{
                prev->next = next->next;
            }
            delete next;
        }
        void free_(){
            node<T>* next = this->top;
            node<T>* prev = NULL;
            int position = 1;
            std::cout << "forward list length::[" << this->size() << "]" << std::endl;
            while(next){
                std::cout << "element in position::[" << position << "]";
                std::cout << "::value::[" << next->value << "]";
                std::cout << "::address::[" << next << "] ";
                position++;
                prev = next;
                if(prev && prev->next)
                    next = prev->next;
                else
                    next = NULL;
                delete prev;
                std::cout << "freed!" << std::endl;
            }
            this->length=0;
        }
        std::size_t length;
        node<T>* top;
};
#endif
