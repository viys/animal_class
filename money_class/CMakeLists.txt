# 手动列出所有的 .c 源文件
set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/money.c
)

# 添加库
add_library(money_class SHARED ${SRC})

# 添加包含目录
target_include_directories(money_class PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(money_class PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
