set(target ${MP2_TESTS})

file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty")

add_executable(${polinomTest} ${srcs} ${hdrs})
target_link_libraries(${polinomTest}  ${libpolinom} gtest)