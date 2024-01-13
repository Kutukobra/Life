#include <raylib.h>
#include <game.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    InitWindow(1080, 720, "Life");

    SetTargetFPS(60);
    srand(time(NULL));
    Setup();
    while (!WindowShouldClose())
    {
        Update();
        BeginDrawing();
        Draw();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}