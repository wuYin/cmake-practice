ADD_EXECUTABLE(curltest main.c)

# 连接库文件
INCLUDE_DIRECTORIES("/usr/include")
INCLUDE_DIRECTORIES("usr/local/include")

TARGET_LINK_LIBRARIES(curltest curl)

# done for now