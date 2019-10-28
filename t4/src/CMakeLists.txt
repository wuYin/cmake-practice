ADD_EXECUTABLE(main main.c)

# 添加非标准头文件搜索路径
INCLUDE_DIRECTORIES(/usr/local/include/hello)

# 添加非标准库文件搜索路径
# 链接到动态库
#TARGET_LINK_LIBRARIES(main /usr/local/lib/libhello.dylib)

# otool -L src/main
# src/main:
#        libhello.1.dylib (compatibility version 1.0.0, current version 1.2.0)
#        /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1252.250.1)


# 链接到静态库
TARGET_LINK_LIBRARIES(main /usr/local/lib/libhello.a)

# src/main:
#        /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1252.250.1)