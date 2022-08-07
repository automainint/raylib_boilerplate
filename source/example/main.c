#include <raylib.h>
#include <string.h>

int main(int argc, char **argv) {
  for (int i = 0; i < argc; i++)
    if (strcmp("--test", argv[i]) == 0)
      return 0;

  int const screenWidth  = 800;
  int const screenHeight = 450;

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(screenWidth, screenHeight, "raylib project boilerplate");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(DARKGRAY);

    DrawText("Foo bar", 140, 140, 60, LIGHTGRAY);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
