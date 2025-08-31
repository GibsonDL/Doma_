#pragma once
#include <vulkan/vulkan.h>


#ifndef DOMA__VK_IMAGES_H
#define DOMA__VK_IMAGES_H

namespace vkutil {
void transition_image(VkCommandBuffer cmd, VkImage image, VkImageLayout currentLayout, VkImageLayout newLayout);
}
#endif //DOMA__VK_IMAGES_H