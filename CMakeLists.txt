cmake_minimum_required (VERSION 2.6)
project (testproto)
# The version number.

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h

set(LIBPATH "$ENV{HOME}/app")

include_directories(".")
include_directories("include")
include_directories("detail")
include_directories("opt")
include_directories("libs/asio/asio/include")

include_directories("${LIBPATH}/include")
link_directories("${LIBPATH}/lib") 
link_directories("/usr/local/lib") 

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(APPLE)
  #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wc++11-extensions -std=c++11 -stdlib=libc++  -g  -D NDEBUG")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wc++11-extensions -std=c++11 -stdlib=libc++  -g  ")
  file(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/detail/mac/*.cpp)

elseif(UNIX)
  #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -std=c++11 -pthread  -DNDEBUG  -D_LIBUV")
  #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -std=c++11 -pthread  -D NDEBUG")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -pthread  -g")
  #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pthread -pg -g -DNDEBUG -Wunused-value ")
  file(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/detail/linux/*.cpp)
elseif(WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11   -D NDEBUG")
  file(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/detail/win/*.cpp)
endif()


# add the executable
add_executable(testproto test.cpp  addressbook.pb.cc)


target_link_libraries(testproto protobuf )


#usage: 
#cmake -DUSE_LIBUV=ON . 
#cmake -DUSE_LIBEV=ON . 



