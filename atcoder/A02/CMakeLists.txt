# CMakeのバージョンを設定
cmake_minimum_required(VERSION 3.28)

# プロジェクト名と使用する言語を設定
project(Atcoder_A01 CXX)

# A01という実行ファイルをsrc/main.cppから作成
add_executable(A01
  src/main.cpp
)
