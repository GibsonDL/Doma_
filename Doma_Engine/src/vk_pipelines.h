//
// Created by glumi on 8/31/25.
//

#ifndef DOMA__VK_PIPELINES_H
#define DOMA__VK_PIPELINES_H


#include "video/khronos/vulkan/vulkan_core.h"

namespace vkutil {
    bool load_shader_module(const char* filePath, VkDevice device, VkShaderModule* outShaderModule);
};

#endif //DOMA__VK_PIPELINES_H