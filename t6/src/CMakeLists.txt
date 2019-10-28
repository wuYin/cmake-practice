SET(SRC_LIST main.c)

ADD_EXECUTABLE(demo ${SRC_LIST})

# 向 C/C++编译器添加-D 定义
ADD_DEFINITIONS(-DENABLE_DEBUG)

# cmake 最低版本要求
CMAKE_MINIMUM_REQUIRED(VERSION 2.5 FATAL_ERROR)

#
# 文件操作
#
# 声明变量即设置空值
# SET(var_str) # ... 不必预先声明变量直接用，方便
FILE(WRITE demo.txt "abc")
FILE(APPEND demo.txt "DEF")
FILE(READ demo.txt var_str)
message(STATUS "> var_string:  " ${var_str})
FILE(REMOVE demo.txt)


#
# 文件查找与 IF 语句
#

FIND_PATH(libGo go /usr/local)
IF (libX)
    message(STATUS "> [INFO] C++ 11 installed")
ELSEIF (libGo)
    message(STATUS "> [INFO] Golang installed")
ENDIF ()

# 类 shell 的 IF 判断表达式
IF (EXISTS /Users/wuyin)
    message(STATUS "> user wuyin ok")
ENDIF ()
IF (UNIX)
    message("> unix best") # 没有 STATUS 就没有 -- 前缀
ENDIF ()


#
# WHILE 循环
#
WHILE (UNIX)
    message(STATUS "> unix best again")
    BREAK()
ENDWHILE ()

#
# FOREACH 循环
#
# 列表
SET(nums 1 2 3)
FOREACH (n ${nums})
    message(STATUS "> ${n}") # 和 SHELL/PHP 一样，单引号无法解析变量，双引号可以
ENDFOREACH ()
# 范围
FOREACH (m RANGE 1 10 2)
    message(STATUS "> ${m}") # range 默认是从 0 开始的，不过可以指定 start end gap
ENDFOREACH ()


# 编程语言该有的大多都有
# cmake 牛批