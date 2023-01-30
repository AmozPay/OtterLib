#include <iostream>
#include <raylib.h>

namespace Otter::Graphic {
    void print_hello() { std::cout << "Hello" << std::endl; }

    void start() { InitWindow(800, 450, "raylib [core] example - basic window"); }

    void end() { CloseWindow(); }
} // namespace Otter::Graphic
