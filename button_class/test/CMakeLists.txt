cmake_minimum_required(VERSION 3.10)

# 定义项目名称和使用的语言
project(test C)

# 设置 C99 标准
set(CMAKE_C_STANDARD 99)

# 添加子目录，这里是 button
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/.. ${CMAKE_BINARY_DIR}/button_build)
# 添加子目录，这里是 gpio_api
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../gpio_api/ ${CMAKE_BINARY_DIR}/gpio_api_build)

# 添加可执行文件，并指定源文件
add_executable(test ${CMAKE_CURRENT_SOURCE_DIR}/main.c)

# 将 myclass 库链接到可执行文件
target_link_libraries(test PRIVATE button_class gpio_api)