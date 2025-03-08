# CMakeのバージョンを設定
cmake_minimum_required(VERSION 3.28)

# プロジェクト名と使用する言語を設定
project(hello_cmake CXX)

# myexeという実行ファイルをmain/src/main.cppとcontrol/src/hello.cppから作成
add_executable(myexe
  main/src/main.cpp
  control/src/hello.cpp
)

# main/includeとcontrol/includeをインクルードディレクトリとして設定
target_include_directories(myexe
  PRIVATE main/include
  PRIVATE control/include
)
