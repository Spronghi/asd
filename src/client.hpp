#ifndef CLIENT_HPP
#define CLIENT_HPP
#include <string>
class client{
    public:
        client(std::string name, std::string surname):name(name),surname(surname){
            //std::cout <<"[Hello world! I'm a new client on address " <<this<<"]"<< std::endl;
        }
        ~client(){
            //std::cout <<"[Goodbye cruel world, I was a client on address "<<this<<"]"<< std::endl;
        }
        bool operator < (client element){
            return (this->name < element.name);
        }
        bool operator >= (client element){
            return (this->name >= element.name);
        }
        void print(){
            std::cout <<"name::["<<this->name<<"], surname::["<<this->surname<<"]"<< std::endl;
        }
    private:
        std::string name;
        std::string surname;
};
#endif
