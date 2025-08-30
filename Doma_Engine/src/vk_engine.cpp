#include "vk_engine.h"

#include <SDL.h>
#include <SDL_vulkan.h>

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

}
