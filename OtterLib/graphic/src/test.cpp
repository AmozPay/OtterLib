#include <iostream>
#include "Raylib.hpp"

namespace Otter::Graphic {
    void print_hello() { std::cout << "Hello" << std::endl; }

    void start() { raylib::InitWindow(800, 450, "raylib [core] example - basic window"); }

    void end() { raylib::CloseWindow(); }
} // namespace Otter::Graphic
