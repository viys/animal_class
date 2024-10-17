# 手动列出所有的 .c 源文件
set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/gpio_api.c
)

# 添加库
add_library(gpio_api SHARED ${SRC})

# 添加包含目录
target_include_directories(gpio_api PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
