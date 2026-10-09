project(Lab1 CXX)


add_executable(lab1)

target_sources("lab1"
  PRIVATE
    "src/main.cpp"
  PRIVATE FILE_SET "modules" TYPE CXX_MODULES FILES
  "src/geometry.cppm"
  "src/randomizer.cppm"
  "src/linemath.cppm")