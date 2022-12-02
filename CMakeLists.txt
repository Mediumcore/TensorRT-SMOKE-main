cmake_minimum_required(VERSION 2.8.0)
project(smoke_trt)
set(CMAKE_CXX_STANDARD 11)

find_package(CUDA REQUIRED)
find_package(OpenCV REQUIRED)
find_library(NVINFER NAMES nvinfer)
find_library(NVINFER_PLUGIN NAMES nvinfer_plugin)

include_directories(
  ${CUDA_INCLUDE_DIRS}
  /home/yankai/Music/TensorRT-8.5.1.7/include
)

add_executable(${PROJECT_NAME}
  smoke.cc
  main.cc
)

target_link_libraries(${PROJECT_NAME}
  # ${NVINFER}
  # ${NVINFER_PLUGIN}
  /home/yankai/Music/TensorRT-8.5.1.7/lib/libnvinfer.so
  /home/yankai/Music/TensorRT-8.5.1.7/lib/libnvinfer_plugin.so
  ${CUDA_LIBRARIES}
  ${OpenCV_LIBRARIES}
)
