add_subdirectory(qpainter)
add_subdirectory(opengl)
if (KWIN_BUILD_XRENDER_COMPOSITING)
    add_subdirectory(xrender)
endif()

if (Vulkan_FOUND)
    add_subdirectory(vulkan)
endif()
