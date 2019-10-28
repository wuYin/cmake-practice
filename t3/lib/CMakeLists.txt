SET(LIBHELLO_SRC hello.c)

# 编译共享库
# darwin
# [ 50%] Building C object lib/CMakeFiles/hello.dir/hello.o
# [100%] Linking C shared library libhello.dylib

# ubuntu
# [ 50%] Building C object lib/CMakeFiles/hello.dir/hello.o
# [100%] Linking C shared library libhello.so
ADD_LIBRARY(hello SHARED ${LIBHELLO_SRC})


# 指定库文件编译输出位置
# SET(LIBRARY_OUTPUT_PATH /Users/wuyin/Desktop)

# ADD_LIBRARY(libname [SHARED|STATIC|MODULE]
# [EXCLUDE_FROM_ALL]
# source1 source2 ... sourceN)

# lib name 不能重名
ADD_LIBRARY(hello_static STATIC ${LIBHELLO_SRC})
# 但可通过重命名来达成同名动态、静态 library 的目的
SET_TARGET_PROPERTIES(hello_static PROPERTIES OUTPUT_NAME "hello")


# 动态版本号
# VERSION 是动态版本库版本号
# SOVERSION 是 API 版本号
# libhello.1.2.dylib
# libhello.1.dylib
SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.2 SOVERSION 1)


# 安装共享库和文件
INSTALL(TARGETS hello hello_static
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
INSTALL(FILES hello.h DESTINATION include/hello) # 此处静态文件会被分配到 /usr/local/include/hello，t4 能直接引用不担心


# 注意
# MacOS 的库头文件放在 /usr/local/include
# 故编译 prefix 应为
# cmake -DCMAKE_INSTALL_PREFIX=/usr/local ..
# make
# sudo make install