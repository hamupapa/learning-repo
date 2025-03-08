# CMakeのバージョンを設定
cmake_minimum_required(VERSION 3.28)
# プロジェクト名と使用する言語を設定
project(hello_cmake CXX)
# a.outという実行ファイルをmain.cppとhello.cppから作成
add_executable(myexe
  main/src/main.cpp
  control/src/hello.cpp
)
target_include_directories(myexe
  PRIVATE main/include
  PRIVATE control/include
)
