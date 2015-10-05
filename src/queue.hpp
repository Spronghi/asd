#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "node.hpp"

template<class T>
class queue{
    public:
        queue():top(0), length(0){
            std::cout << "[Hello world! I am a new queue on address "<<this<<"]"<<std::endl;
        }
        ~queue(){
            this->free_();
            std::cout << "[Goodbye cruel world! I was a queue on address "<<this<<"]"<<std::endl;
        }
        std::size_t size(){
            return (this->length);
        }
        void push(T value){
            node<T>* next = this->top;
            node<T>* prev = NULL;
            std::size_t position = 1;
            while(next){
                prev = next;
                position++;
                if(prev && prev->next)
                    next = (*prev)++;
                else
                    next = NULL;
            }
            //std::cout << "push on back::position::[" << position << "]::value::[" << value <<"] ";
            this->length++;
            this->push_(prev, value);
            std::cout << "prev::" << prev << std::endl;
        }
        T pop(){
            if(this->top){
                node<T>* tmp = this->top;
                //std::cout << "pop on front::value::[" << this->top->value << "]";
                std::cout << "::address::[" << this->top << "] ";
                this->remove_();
                this->length--;
                return tmp->value;
            }else{
                throw std::invalid_argument("cannot pop on front");
            }
        }
        void print(){
            node<T>* iterator = this->top;
            int position = 1;
            std::cout << "length::[" << this->length << "]" << std::endl;
            while(iterator){
                try{
                    iterator->value.print();
                }catch(std::exception& e){
                    std::cout << "[EXCEPTION]::[Node]::element in address::[" << iterator << "]";
                    std::cout << ", address::[" << iterator << "]" << std::endl;
                }                position++;
                if(iterator->next)
                    iterator = (*iterator)++;
                else
                    iterator = NULL;
            }
        }
    private:
        void push_(node<T>* next, T value){
            node<T>* tmp = new node<T>(value, NULL);
            if(!next)
                this->top = tmp;
            else
                next->next = tmp;
        }
        void remove_(){
            node<T>* tmp = this->top;
            this->top = this->top->next;
            delete tmp;
        }
        void free_(){
            node<T>* next = this->top;
            node<T>* prev = NULL;
            int position = 1;
            std::cout << "queue length::[" << this->size() << "]" << std::endl;
            while(next){
                std::cout << "element in position::[" << position << "]";
                //std::cout << "::value::[" << next->value << "]";
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
        node<T>* top;
};
#endif
