#include "Notebook.hpp"
using namespace ariel;

const int MAX_LINE_SIZE = 100;
#include <string>
void Notebook::write(unsigned int page, unsigned int row, unsigned int col, Direction dir, const std::string &str){
    if(str.size()+col > MAX_LINE_SIZE && dir == Direction::Horizontal){
        throw std::invalid_argument("Cannot write over 100 chars in 1 line.\n");
    }
}

std::string Notebook::read(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int len){return "";}

void Notebook::erase(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int len){
    try
    {
        /* code */
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        throw e;
    }
    
}

void Notebook::show(unsigned int page){}