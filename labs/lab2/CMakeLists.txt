project(Lab2 CXX)


add_executable(lab2)

target_sources("lab2"
  PRIVATE
    "src/main.cpp"
  PRIVATE FILE_SET "modules" TYPE CXX_MODULES FILES
  "src/tllist.cppm"
  "src/task.cppm"
  "src/randomizer.cppm")