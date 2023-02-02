// #include "OtterGraphic.hpp"
// #include "OtterNetwork.hpp"

#include "OtterCore.hpp"

#include <iostream>
#include <raylib.h>

/*
int main(int ac, ch0ar** av)
{
#ifdef TARGET_CLIENT
    std::cout << "CLIENT" << std::endl;
#elif TARGET_SERVER
    std::cout << "SERVER" << std::endl;
#endif
    Otter::Network::print_hello();

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;

Otter::Network::print_hello();
    Otter::Graphic::start();
    Otter::Graphic::end();
    return 0;
}
*/

void func(Otter::Core::Orchestrator& ref) { std::cout << "i am working" << std::endl; }

void func1(Otter::Core::Orchestrator& ref) { std::cout << "i am working2" << std::endl; }

void func2(Otter::Core::Orchestrator& ref) { std::cout << "i am working3" << std::endl; }

void Otter::Core::registerComponents(Otter::Core::Orchestrator& orchestrator)
{
    orchestrator.register_component<test_str>();
    orchestrator.register_component<testcomponent>();
}

void Otter::Core::registerSystems(Otter::Core::SystemManager& manager)
{
    manager.registerSystem(func, Otter::Core::SystemManager::init);
    manager.registerSystem(func1, Otter::Core::SystemManager::update);
    manager.registerSystem(func2, Otter::Core::SystemManager::preUpdate);
}