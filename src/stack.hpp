#ifndef STACK_HPP
#define STACK_HPP
#include "node.hpp"

template <class T>
class stack{
    public:
        stack(){
            std::cout << "[Hello world, i am a new stack on address::"<<this<<"]" << std::endl;
        }
        ~stack(){
            this->free_();
            std::cout << "[Goodbye cruel world, i was a stack on address::"<<this<<"]" << std::endl;
        }
        std::size_t size(){
            return (this->length);
        }
        void push(T value){
            //std::cout << "push on back::value::[" << value <<"] ";
            this->length++;
            this->push_(value);
            std::cout << "next::" << this->top->next << std::endl;
        }
        node<T>* pop(){
            if(this->top){
                node<T>* tmp = this->top;
                //std::cout << "pop on back::value::[" << this->top->value << "]";
                std::cout << ", address::[" << this->top << "] ";
                this->remove_();
                this->length--;
                return tmp;
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
                }
                position++;
                if(iterator->next)
                    iterator = (*iterator)++;
                else
                    iterator = NULL;
            }
        }
    private:
        void push_(T value){
            node<T>* tmp = new node<T>(value, this->top);
            this->top = tmp;
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
            std::cout << "list length::[" << this->size() << "]" << std::endl;
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
