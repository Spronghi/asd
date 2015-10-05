#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include "double_linked_tree_node.hpp"

template<class T>
class binary_tree{
    public:
        binary_tree():root(0),length(0),leaf_level(0){
            std::cout << "[Hello world, i am a new binary tree on address::"<<this<<"]" << std::endl;
        }
        ~binary_tree(){
            this->destroy_tree();
            std::cout << "[Goodbye cruel world, i was a binary tree node on address::"<<this<<"]" << std::endl;
        }
        std::size_t size(){
            return (this->length);
        }
        void insert(T value){
            this->leaf_level = 0;
            if(this->root){
                this->insert_(value, this->root);
            }else{
                this->length++;
                this->root = new double_linked_tree_node<T>(value, NULL, NULL, leaf_level);
                std::cout << "insert root on address::["<<this->root<<"]"<< std::endl;
            }
        }
        void destroy_tree(){
            std::cout << "destroy tree on address::["<<this<<"]::length::["<<this->size()<<"]"<< std::endl;
            this->destroy_tree_(this->root);
            std::cout << "freed!"<< std::endl;
        }
        void print(){
            std::cout << "length::["<<this->size()<<"]"<< std::endl;
            this->print_(this->root);
        }
        double_linked_tree_node<T>* search(T value){
            std::cout<< "search element"<<std::endl;
            if(this->root){
                this->search_(value, this->root);
            }else{
                throw std::invalid_argument("cannot search");
            }
        }
    private:
        void insert_(T value, double_linked_tree_node<T>* leaf){
            this->leaf_level++;
            if((value) < (leaf->value)){
                if(leaf->left){
                    this->insert_(value, leaf->left);
                }else{
                    this->length++;
                    leaf->left = new double_linked_tree_node<T>(value, NULL, NULL, leaf_level);
                    std::cout << "insert left on address::["<<leaf->left<<"]"<< std::endl;
                }
            }else if((value) >= (leaf->value)){
                if(leaf->right){
                    this->insert_(value, leaf->right);
                }else{
                    this->length++;
                    leaf->right = new double_linked_tree_node<T>(value, NULL, NULL, leaf_level);
                    std::cout << "insert right on address::["<<leaf->right<<"]"<< std::endl;
                }
            }
        }
        void destroy_tree_(double_linked_tree_node<T>* leaf){
            if(leaf){
                std::cout << "element address::["<<leaf<<"]"<< std::endl;
                this->destroy_tree_(leaf->right);
                this->destroy_tree_(leaf->left);
                this->length--;
                delete leaf;
            }
        }
        void print_(double_linked_tree_node<T>* leaf){
            if(leaf){
                try{
                    leaf->value.print();
                    std::cout << "address::[" << leaf << "], level::["<<leaf->level<<"] ";
                    std::cout << "left::" << leaf->left << "::right::" << leaf->right << std::endl;
                }catch(std::exception& e){
                    std::cout << "[EXCEPTION]::[Node]::element in address::[" << leaf << "]";
                    std::cout << ", address::[" << leaf << "], " << std::endl;
                    std::cout << "left::" << leaf->left << "::right::" << leaf->right << std::endl;
                }
                this->print_(leaf->right);
                this->print_(leaf->left);
            }
        }
        double_linked_tree_node<T>* search_(T value, double_linked_tree_node<T>* leaf){
            if(leaf){
                if(value == leaf->value)
                    return leaf;
                else if(value < leaf->value)
                    return (this->search_(value, leaf->left));
                else
                    return (this->search_(value, leaf->right));
            }else{
                return NULL;
            }
        }
        int leaf_level;
        std::size_t length;
        double_linked_tree_node<T>* root;
};
#endif
