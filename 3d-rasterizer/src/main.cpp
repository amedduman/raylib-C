#include "../include/raylib.h"
#include "../include/raymath.h"
#include "my_model.hpp"
#include "my_camera.hpp"
#include "my_rendering.hpp"
#include <iostream>
#include <assert.h>
#include <vector>

int main(void)
{
  const int screenWidth = 400;
  const int screenHeight = 400;

  SetTraceLogLevel(LOG_WARNING); 

  InitWindow(screenWidth, screenHeight, "Game");

  model_t cube = {
    
      .vertices = {
      (Vector3){ 1,  1,  1}, // 0
      (Vector3){-1,  1,  1}, // 1
      (Vector3){-1, -1,  1}, // 2
      (Vector3){ 1, -1,  1}, // 3
      (Vector3){ 1,  1, -1}, // 4
      (Vector3){-1,  1, -1}, // 5
      (Vector3){-1, -1, -1}, // 6
      (Vector3){ 1, -1, -1}, // 7
    },
    .triangles = {
      {.tri_indices = {0, 1, 2}, .color = RED},
      {.tri_indices = {0, 2, 3}, .color = RED},
      {.tri_indices = {4, 0, 3}, .color = GREEN},
      {.tri_indices = {4, 3, 7}, .color = GREEN},
      {.tri_indices = {5, 4, 7}, .color = BLUE},
      {.tri_indices = {5, 7, 6}, .color = BLUE},
      {.tri_indices = {1, 5, 6}, .color = GOLD},
      {.tri_indices = {1, 6, 2}, .color = GOLD},
      {.tri_indices = {4, 5, 1}, .color = PURPLE},
      {.tri_indices = {4, 1, 0}, .color = PURPLE},
      {.tri_indices = { 2, 6, 7},.color = BLACK},
      {.tri_indices = { 2, 7, 3},.color = BLACK},
    },
    .uv_of_each_vertex = {
      (Vector2){ 0, 0 }, // 0
      (Vector2){ 1, 0 }, // 1
      (Vector2){ 1, 1 }, // 2
      (Vector2){ 0, 1 }, // 3
      (Vector2){ 0, 0 }, // 4
      (Vector2){ 1, 0 }, // 5
      (Vector2){ 1, 1 }, // 6
      (Vector2){ 0, 1 }, // 7
    }

  };

  instance_t cube_a = model_init_instance(cube, (Vector3){0, 0, 7}, (Vector3){0, DEG2RAD * 0, 0}, (Vector3){1,1,1});
  instance_t cube_b = model_init_instance(cube, (Vector3){0, 0, 3}, (Vector3){0, DEG2RAD * 0, 0}, (Vector3){1,1,1});

  camera_t camera = {
    .position = {0,0,0},
    .rot_in_rad = (Vector3){0, DEG2RAD * 0, 0},
    .fov = 90,
    .z_near = 0.1f,
    .z_far = 300.0f
  };

  SetTargetFPS(60);

  while (!WindowShouldClose())
  {
    camera_move(camera);
    camera_rotate(camera);


    BeginDrawing();
    ClearBackground(RAYWHITE);
    
    render_scene(std::vector<instance_t>{cube_b, cube_a}, camera);

    EndDrawing();
  }

  CloseWindow();
}
