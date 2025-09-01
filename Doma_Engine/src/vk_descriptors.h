//
// Created by glumi on 8/31/25.
//
#include <span>
#include <vector>

#include "video/khronos/vulkan/vulkan_core.h"

#ifndef DOMA__VK_DESCRIPTORS_H
#define DOMA__VK_DESCRIPTORS_H

struct DescriptorLayoutBuilder {

    std::vector<VkDescriptorSetLayoutBinding> bindings;

    void add_binding(uint32_t binding, VkDescriptorType type);
    void clear();
    VkDescriptorSetLayout build(VkDevice device, VkShaderStageFlags shaderStages, void* pNext = nullptr, VkDescriptorSetLayoutCreateFlags flags = 0);
};
struct DescriptorAllocator {

    struct PoolSizeRatio{
        VkDescriptorType type;
        float ratio;
    };

    VkDescriptorPool pool;

    void init_pool(VkDevice device, uint32_t maxSets, std::span<PoolSizeRatio> poolRatios);
    void clear_descriptors(VkDevice device);
    void destroy_pool(VkDevice device);

    VkDescriptorSet allocate(VkDevice device, VkDescriptorSetLayout layout);
};

class vk_descriptors {

};


#endif //DOMA__VK_DESCRIPTORS_H