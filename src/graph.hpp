#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "graph_node.hpp"

template <class T>
class graph{
    public:
        graph():top(0),length(0){
            std::cout << "[Hello world! I am a new graph on address "<<this<<"]"<<std::endl;
        }
        ~graph(){
            this->free_();
            std::cout << "[Goodbye cruel world! I was a graph on address "<<this<<"]"<<std::endl;
        }
        void vertex_push(T value){
            std::cout << "[PUSH_VERTEX]";
            vertex<T>* next = this->top;
            vertex<T>* prev = NULL;
            std::size_t position = 1;
            while(next){
                prev = next;
                position++;
                if(prev && prev->next)
                    next = (*prev)++;
                else
                    next = NULL;
            }
            this->vertex_push_(prev, value);
            std::cout << " position::[" << position << "]::value::[" << value <<"] ";
            std::cout << "prev::["<<prev<<"]" << std::endl;
        }
        void edge_push(T element, T connection){
            if(this->top){
                vertex<T>* iterator = this->top;
                vertex<T>* start = NULL;
                vertex<T>* end = NULL;
                while(iterator){
                    if(iterator->value == element)
                        start = iterator;
                    if(iterator->value == connection)
                        end = iterator;
                    iterator = (*iterator)++;
                }
                if(start && end){
                    this->edge_push(start, end);
                }else{
                    this->free_();
                    throw std::invalid_argument("cannot push the edge");
                }
            }
        }
        void edge_push(vertex<T>* element, vertex<T>* connection){
            std::cout << "[PUSH_EDGE] vertex address::[" << element << "]-->[" << connection <<"] "<< std::endl;
            if(this->top){
                if(!element->edges){
                    this->edge_push_(element, connection);
                }else{
                    edge<T>* next = element->edges;
                    edge<T>* prev = NULL;
                    while(next){
                        prev = next;
                        if(next->connects_to == connection){
                            std::cout<< "[ERROR]::[THE CONNECTION ALREADY EXISTS]"<<std::endl;
                            return;
                        }
                        else if(prev && prev->next)
                            next = (*prev)++;
                        else
                            next = NULL;
                    }
                    this->edge_push_(prev, connection);
                }
            }else{
                this->free_();
                throw std::invalid_argument("cannot push the edge");
            }
        }
        void print(){
            if(this->top){
                std::cout<<"=========================="<<std::endl;
                std::cout<<"[PRINT] graph length::["<<this->length<<"]"<<std::endl;
                const vertex<T>* iterator;
                for(iterator=this->top; iterator; iterator=(*iterator)++){
                    std::cout<<"vertex address::["<<iterator<<"], value::["<<iterator->value<<"]"<< std::endl;
                    this->edge_print(iterator);
                }
            }
        }
        void edge_print(const vertex<T>* element){
            if(element->edges){
                const edge<T>* iterator;
                for(iterator=element->edges; iterator; iterator=(*iterator)++){
                    std::cout<<"edge address::["<<iterator<<"]-->["<<iterator->connects_to<<"]::value::["<<iterator->connects_to->value<<"]"<<std::endl;
                }
            }
        }
        bool* is_reachable(T source, T destination){
            if(this->top){
                vertex<T>* iterator = this->top;
                vertex<T>* start = NULL;
                vertex<T>* end = NULL;
                while(iterator){
                    iterator->visited = false;
                    if(iterator->value == source){
                        start = iterator;
                        //std::cout<<"[START] address::["<<start<<"]::value::["<<start->value<<"]"<< std::endl;
                    }
                    if(iterator->value == destination){
                        end = iterator;
                        //std::cout<<"[END] address::["<<end<<"]::value::["<<end->value<<"]"<< std::endl;
                    }
                    iterator = (*iterator)++;
                }
                if(start && end){
                    return (this->is_reachable_(start, end))
                    std::cout<<"[IS_REACHABLE] ["<<source<<"]-->["<<destination<<"]"<<std::endl;
                }else{
                    return false;
                }
            }
        }
    private:
        void vertex_push_(vertex<T>* prev, T value){
            vertex<T>* tmp = new vertex<T>(value, NULL, NULL);
            this->length++;
            if(!prev)
                this->top = tmp;
            else
                prev->next = tmp;
        }
        void edge_push_(vertex<T>* element, vertex<T>* connection){
            element->edges = new edge<T>(connection, NULL);
        }
        void edge_push_(edge<T>* element, vertex<T>* connection){
            edge<T>* tmp = new edge<T>(connection, NULL);
            element->next = tmp;
        }
        bool is_reachable_(vertex<T>* source, vertex<T>* destination){
            if(source->visited)
                return false;
            else if(source == destination)
                return true;
            source->visited = true;
            if(source->edges){
                edge<T>* iterator = source->edges;
                while(iterator){
                    //std::cout<<"[ITERATOR]::["<<iterator->connects_to<<"]::[VALUE]::["<<iterator->connects_to->value<<"] [DESTINATION]::["<<destination<<"]"<<std::endl;
                    if(this->is_reachable_(iterator->connects_to, destination))
                        return true;
                    iterator = (*iterator)++;
                }
            }
            return false;
        }
        void free_(){
            vertex<T>* next = this->top;
            vertex<T>* prev = NULL;
            std::cout<<"=========================="<<std::endl;
            std::cout << "[FREE_GRAPH] length::[" << this->length << "]" << std::endl;
            while(next){
                std::cout << "[FREE] vertex address::["<<next<<"]::value::["<<next->value<<"]"<< std::endl;
                prev = next;
                this->edge_free_(prev);
                if(prev && prev->next)
                    next = (*prev)++;
                else
                    next = NULL;
                delete prev;
                std::cout << "freed!" << std::endl;
            }
            this->length=0;
        }
        void edge_free_(vertex<T>* element){
            if(element->edges){
                edge<T>* next = element->edges;
                edge<T>* prev = NULL;
                while(next){
                    std::cout << "[FREE] edge address::[" << next << "] "<< std::endl;
                    prev = next;
                    if(prev && prev->next)
                        next = (*prev)++;
                    else
                        next = NULL;
                    delete prev;
                }
            }
        }
        std::size_t length;
        vertex<T>* top;
};
#endif
