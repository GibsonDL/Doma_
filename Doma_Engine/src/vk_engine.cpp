#include "vk_engine.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>
#include <SDL3/SDL_main.h>

#include <vk_initializers.h>
#include <vk_types.h>
#include <iostream>
#include <chrono>
#include <iostream>
#include <thread>
constexpr bool bUseValidationLayers = false;

VulkanEngine* loadedEngine = nullptr;

VulkanEngine& VulkanEngine::Get() {return *loadedEngine;}

void VulkanEngine::init() {


    SDL_Init(SDL_INIT_VIDEO);
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN);

    _window = SDL_CreateWindow(
        "Vulkan Engine",
        1000,
        1000,
        window_flags);

    //everythings okay!
    _isInitialized = true;
}
void VulkanEngine::cleanup() {
    if (_isInitialized == true) {
        SDL_DestroyWindow(_window);
    }
    //clear engine pointer
    loadedEngine = nullptr;
}
void VulkanEngine::draw() {

}
void VulkanEngine::run() {
    SDL_Event e;
    bool bQuit = false;

    //main loop
    while (!bQuit) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {

            //close the window when user alt-f4s or clicks the x button
            if (e.type == SDL_EVENT_QUIT)
                bQuit = true;

           // if (e.type == SDL_WINDOWEVENT) {
            //    if (e.window.type == SDL_EVENT_WINDOW_MINIMIZED) {
            //        stop_rendering = true;
            //    }
            //    if (e.window.type == SDL_EVENT_WINDOW_RESTORED) {
            //        stop_rendering = false;
            //    }
//
            //}

        }
        //do not draw if we are minimized
        if (stop_rendering) {
            // throttle the speed to avoid the endless spinning
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }
        draw();
    }
}

