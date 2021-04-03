add_executable(runCgen main.cpp include/cgen.hpp)

add_library(cgen STATIC
  ${PROJECT_SOURCE_DIR}/src/include/cgen.cpp
  )

target_link_directories(cgen PRIVATE
  ${PROJECT_SOURCE_DIR}/src/include/
  )

# Compiler options below
set_target_properties(runCgen PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON)

set_target_properties(cgen PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON)


target_link_libraries(runCgen cgen)

target_compile_options(
  cgen BEFORE
  PRIVATE
  "$<$<CONFIG:Release>:-ofast>"
  "$<$<CONFIG:Debug>:-ggdb>"
  "$<$<CONFIG:test>:-ggdb>"
  "$<$<CONFIG:bench>:-ofast>"
  )
target_compile_options(
  runCgen BEFORE
  PRIVATE
  "$<$<CONFIG:Release>:-ofast>"
  "$<$<CONFIG:Debug>:-ggdb>"
  "$<$<CONFIG:test>:-ggdb>"
  "$<$<CONFIG:bench>:-ofast>"
  )
