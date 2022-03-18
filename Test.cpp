#include "doctest.h"

#include "Notebook.hpp"
using namespace ariel;
TEST_CASE("Notebook a"){
    Notebook notebook;    
    notebook.write(12,14,54,Direction::Horizontal,"New");
    CHECK(notebook.read(12,14,54,Direction::Horizontal,3)=="New");
}