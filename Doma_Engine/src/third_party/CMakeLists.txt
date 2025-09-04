
# Tell CMake to ONLY search in LunarG SDK path
find_package(Vulkan REQUIRED MODULE)

# -------------------------------
# Your libraries
# -------------------------------

add_library(vkbootstrap STATIC)
add_library(glm INTERFACE)
add_library(vma INTERFACE)
add_library(stb_image INTERFACE)

add_subdirectory(fastgltf)
add_subdirectory(fmt EXCLUDE_FROM_ALL)
add_subdirectory(SDL EXCLUDE_FROM_ALL)

target_sources(vkbootstrap PRIVATE
        vkbootstrap/VkBootstrap.h
        vkbootstrap/VkBootstrap.cpp
)

target_include_directories(vkbootstrap PUBLIC vkbootstrap)
target_link_libraries(vkbootstrap PUBLIC Vulkan $<$<BOOL:UNIX>:${CMAKE_DL_LIBS}>)
set_property(TARGET vkbootstrap PROPERTY CXX_STANDARD 20)

target_include_directories(vma INTERFACE vma)
target_include_directories(glm INTERFACE glm)

add_library(sdl3 INTERFACE)
target_include_directories(sdl3 INTERFACE $ENV{VULKAN_SDK}/include/SDL3 )
target_link_directories(sdl3 INTERFACE $ENV{VULKAN_SDK}/lib )
target_link_libraries(sdl3 INTERFACE SDL3 SDL3::SDL3)

add_library(imgui STATIC)
target_include_directories(imgui PUBLIC imgui)

target_sources(imgui PRIVATE
        imgui/imgui.h
        imgui/imgui.cpp
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_widgets.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_impl_vulkan.cpp
        imgui/imgui_impl_sdl3.cpp
)

target_link_libraries(imgui PUBLIC Vulkan SDL3::SDL3)
target_include_directories(stb_image INTERFACE stb_image)
