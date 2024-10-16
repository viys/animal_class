# 手动列出所有的 .c 源文件
set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/animal.c
)

# 添加库
add_library(animal_class SHARED ${SRC})

# 添加包含目录
target_include_directories(animal_class PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
