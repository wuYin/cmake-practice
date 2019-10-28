# cmake 构建定义文件

# project 指令定义工程名称
# 同时定义了 2 个内部变量 projectname_BINARY_DIR 和 projectname_SOURCE_DIR
PROJECT(HELLO)

# SET k v
SET(SRC_LIST main.c)


# message 输出三种信息到终端
MESSAGE(STATUS "this is binary dir " ${HELLO_BINARY_DIR})
MESSAGE(STATUS "this is source dir  ${HELLO_SOURCE_DIR}")


# 定义生成的可执行文件名称
ADD_EXECUTABLE(hello; ${SRC_LIST})