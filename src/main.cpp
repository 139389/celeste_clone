#include "engine_lib.h"

#define APIENTRY
#define GL_GLEXT_PROTOTYPES
#include "glcorearb.h"


#include "input.h"


// #############################################################################
//                           Platform Includes
// #############################################################################
#include "platform.h"
#ifdef _WIN32
#include "win32_platform.cpp"
#endif

#include "gl_renderer.cpp"

int main() {

  BumpAllocator transientStorage = make_bump_allocator(MB(50));

  input.screenSizeX = 1200;
  input.screenSizeY = 720;

  platform_create_window(input.screenSizeX, input.screenSizeY, "testwindow");

  gl_init(&transientStorage);

  while (running) {
    // update
    platform_update_window();
    gl_render();
    platform_swap_buffers();
  }
  return 0;
};