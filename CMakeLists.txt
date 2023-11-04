cmake_minimum_required(VERSION 3.12)

find_package(LLVM REQUIRED CONFIG)

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})

# add your pass here
add_library(MyModulePass MODULE MyModulePass.cpp)

set_target_properties(MyModulePass PROPERTIES
  COMPILE_FLAGS "-fno-rtti"
)