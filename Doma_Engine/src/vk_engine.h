#pragma once

#include <vk_types.h>
#include "vk_descriptors.h"

struct AllocatedImage {
	VkImage image;
	VkImageView imageView;
	VmaAllocation allocation;
	VkExtent3D imageExtent;
	VkFormat imageFormat;
};

struct DeletionQueue {
	std::deque<std::function<void()>> deletors;
	void push_function(std::function<void()>&& function) {
		deletors.push_back(function);
	}
	void flush() {
		//reverse iterate the deletion queue to execute all the functions
		for (auto it = deletors.rbegin(); it != deletors.rend(); ++it) {
			(*it)();
		}
		deletors.clear();
	}
};
struct FrameData {
	VkSemaphore _swapchainSemaphore, _renderSemaphore;
	VkFence _renderFence;
	VkCommandPool _commandPool;
	VkCommandBuffer _mainCommandBuffer;
	DeletionQueue _deletionQueue;

};
constexpr unsigned int FRAME_OVERLAP = 2;

class VulkanEngine {

public:
	VkPipeline _gradientPipeline;
	VkPipelineLayout _gradientPipelineLayout;


	DescriptorAllocator globalDescriptorAllocator;

	VkDescriptorSet _drawImageDescriptors;
	VkDescriptorSetLayout _drawImageDescriptorLayout;

	//draw resources
	AllocatedImage _drawImage;
	VkExtent2D _drawExtent;

	VmaAllocator _allocator;
	DeletionQueue _mainDeletionQueue;
	FrameData _frames[FRAME_OVERLAP];
	FrameData _balls;
	FrameData& get_current_frame(){ return _frames[_frameNumber % FRAME_OVERLAP];};

	VkQueue _graphicsQueue;
	uint32_t _graphicsQueueFamily;

	bool _isInitialized{ false };
	int _frameNumber {0};
	bool stop_rendering{ false };
	VkExtent2D _windowExtent{ 1920 , 1080 };

	VkInstance _instance;// Vulkan library handle
	VkDebugUtilsMessengerEXT _debug_messenger; // vulkan debug output handle
	VkPhysicalDevice _chosenGPU; // GPU chosen as the default device
	VkDevice _device; // Vulkan device for commands - pretty sure this deals with gpu drivers as well
	VkSurfaceKHR _surface; //Vulkan window surface

	VkSwapchainKHR _swapchain;
	VkFormat _swapchainImageFormat;

	std::vector<VkImage> _swapchainImages;
	std::vector<VkImageView> _swapchainImageViews;
	VkExtent2D _swapchainExtent;


	struct SDL_Window* _window{ nullptr };

	static VulkanEngine& Get();


	//initializes everything in the engine
	void init();
	//shuts down the engine
	void cleanup();
	//draw loop
	void draw();
	//run main loop
	void run();

private:

	void draw_background(VkCommandBuffer cmd);

	void init_vulkan();
	void init_swapchain();
	void init_commands();
	void init_sync_structures();
	void init_descriptors();
	void init_pipelines();
	void init_background_pipelines();
	void create_swapchain(uint32_t width, uint32_t height);
	void destroy_swapchain();
};