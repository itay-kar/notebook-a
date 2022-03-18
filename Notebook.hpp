#include "Direction.hpp"

#include <string>

namespace ariel
{

    struct Notebook
    {

        void write(unsigned int page, unsigned int row, unsigned int col, Direction dir, std::string str);

        std::string read(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int len);

        void erase(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int len);

        void show(unsigned int page);
    };
};