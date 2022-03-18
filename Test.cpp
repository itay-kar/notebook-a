#include "doctest.h"

#include "Notebook.hpp"
using namespace ariel;
TEST_CASE("Notebook a")
{
    struct Notebook notebook;
    CHECK_NOTHROW(notebook.write(12, 14, 54, Direction::Horizontal, "New"));
    CHECK(notebook.read(12, 14, 54, Direction::Horizontal, 3) == "New");
    notebook.erase(12, 14, 54, Direction::Horizontal, 2);
    CHECK(notebook.read(12, 14, 54, Direction::Horizontal, 3) == "~~w");
    CHECK_NOTHROW(notebook.erase(1, 24, 12, Direction::Vertical, 5));
    // Check no throw on erase on erased chars.
    CHECK_NOTHROW(notebook.erase(1, 24, 12, Direction::Horizontal, 5));
    notebook.write(0, 0, 0, Direction::Horizontal, "abc");
    notebook.write(0, 1, 0, Direction::Vertical, "bc");
    CHECK_EQ(notebook.read(0, 0, 0, Direction::Horizontal, 3), notebook.read(0, 0, 0, Direction::Vertical, 3));
    notebook.write(1,1,1,Direction::Vertical,"Hello");
    notebook.write(2,2,2,Direction::Horizontal,"Hello");
    CHECK_EQ(notebook.read(1,1,1,Direction::Vertical,5),notebook.read(2,2,2,Direction::Horizontal,5));
    notebook.write(1,6,1,Direction::Vertical,"A");
    CHECK_EQ(notebook.read(1,1,1,Direction::Vertical,7),notebook.read(2,2,2,Direction::Horizontal,7));
}

TEST_CASE("Throws Check")
{
    struct Notebook notebook;
    notebook.write(1, 2, 80, Direction::Horizontal, "Test2");
    CHECK_THROWS(notebook.write(12, 14, 79, Direction::Horizontal, "NEW_Line"));
    notebook.write(0, 0, 0, Direction::Horizontal, "abc");
    CHECK_THROWS(notebook.write(0, 0, 0, Direction::Vertical, "abc"));
    notebook.erase(0, 0, 0, Direction::Horizontal, 1);
    CHECK_THROWS(notebook.write(0, 0, 0, Direction::Vertical, "abc"));

    // Check throws on line length longer than 100 
    CHECK_THROWS(notebook.erase(1, 4, 78, Direction::Horizontal, 69));
    CHECK_THROWS(notebook.write(12, 14, 96, Direction::Horizontal, "NEW_Line"));
    CHECK_THROWS(notebook.read(1, 4, 99, Direction::Horizontal, 3));
    // Checking on coll > 100
    CHECK_THROWS(notebook.erase(1, 4, 101, Direction::Vertical, 12));
    CHECK_THROWS(notebook.write(12, 14, 105, Direction::Horizontal, "NEW_Line"));
    CHECK_THROWS(notebook.read(1, 4, 103, Direction::Vertical, 3));
}

TEST_CASE("NO THROW"){
    struct Notebook notebook;
    //Should not throw line lengths is infinity
    CHECK_NOTHROW(notebook.write(12,195,20,Direction::Vertical,"CHECKING IF STRING IS TOO LONG FOR LINES LENGTH THERE SHOULD BE NO THROW"));
    CHECK_NOTHROW(notebook.read(12,195,20,Direction::Vertical,100000));
    CHECK_NOTHROW(notebook.read(12,10000,20,Direction::Vertical,100000));
}