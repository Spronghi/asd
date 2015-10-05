#include "forward_list.hpp"

int main(int argc, char* argv[]){
	int i;
    forward_list<int>* element = new forward_list<int>();
	for(i=1; i<10; ++i)
        element->append(i, i);
	element->bubble_sort();
    element->print();

    delete element;
    return 0;
}
