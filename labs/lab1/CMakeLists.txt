project(Lab1 CXX)


add_executable(lab3)

target_sources("lab3"
  PRIVATE
    "src/main.cpp"
  PRIVATE FILE_SET "modules" TYPE CXX_MODULES FILES
  "src/geometry.cppm")