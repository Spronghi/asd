#ifndef DOUBLE_LINKED_TREE_NODE_HPP
#define DOUBLE_LINKED_TREE_NODE_HPP
#include <iostream>
#include <stdexcept>

template <class T>
class double_linked_tree_node{
    public:
        double_linked_tree_node(T value, double_linked_tree_node<T>* left, double_linked_tree_node<T>* right, int level):value(value),left(left),right(right),level(level){
            //std::cout << "[Hello world, i am a new double linked tree node on address::"<<this<<"]" << std::endl;
        }
        ~double_linked_tree_node(){
            //std::cout << "[Goodbye cruel world, i was a double linked tree node on address::"<<this<<"]" << std::endl;
        }
        T value;
        double_linked_tree_node<T>* left;
        double_linked_tree_node<T>* right;
        int level;
};

#endif
