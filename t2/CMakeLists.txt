PROJECT(HELLO)

# 依次指定源文件和目标文件目录
# ADD_SUBDIRECTORY(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
# 本质上是 src 重命名为 bin
ADD_SUBDIRECTORY(src bin)


INSTALL(FILES COPYRIGHT README DESTINATION share/doc/cmake/t2)
INSTALL(PROGRAMS runhello.sh DESTINATION bin)

# cmake -DCMAKE_INSTALL_PREFIX=/tmp/t2/usr ..
# make
# make install
#
#/tmp/t2/usr
#├── bin
#│   └── runhello.sh
#└── share
#    └── doc
#        └── cmake
#            └── t2
#                ├── COPYRIGHT
#                └── README