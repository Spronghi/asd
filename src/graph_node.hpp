#ifndef GRAPH_NODE_HPP
#define GRAPH_NODE_HPP
#include <iostream>
#include <stdexcept>

template <class T>
class edge;

template <class T>
class vertex{
    public:
        vertex(T value, edge<T>* edges, vertex<T>* next):value(value),visited(0),edges(edges),next(next){
            //std::cout<<"new vertex address::["<<this<<"]"<<std::endl;
        }
        ~vertex(){
            //std::cout<<"old vertex address::["<<this<<"]"<<std::endl;
        }
        const vertex<T>* operator++(int i) const{
            //std::cout << "[vertex]::[const operator++]::[" << i << " " << this->next <<"]" << std::endl;
            return this->next;
        }
        vertex<T>* operator++(int i){
            //std::cout << "[vertex]::[operator++]::[" << i << " " << this->next <<"]" << std::endl;
            return const_cast < vertex<T>* >(static_cast < const vertex<T> >(*this)++);
        }
        T value;
        bool visited;
        edge<T>* edges;
        vertex<T>* next;
};
template <class T>
class edge{
    public:
        edge(vertex<T>* connects_to, edge<T>* next):connects_to(connects_to),next(next){
            //std::cout<<"new edge address::["<<this<<"]"<<std::endl;
        }
        ~edge(){
            //std::cout<<"old edge address::["<<this<<"]"<<std::endl;
        }
        const edge<T>* operator++(int i) const{
            //std::cout << "[edge]::[const operator++]::[" << i << " " << this->next <<"]" << std::endl;
            return this->next;
        }
        edge<T>* operator++(int i){
            //std::cout << "[edge]::[operator++]::[" << i << " " << this->next <<"]" << std::endl;
            return const_cast < edge<T>* >(static_cast < const edge<T> >(*this)++);
        }
        vertex<T>* connects_to;
        edge<T>* next;
};
#endif
