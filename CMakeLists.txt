cmake_minimum_required(VERSION 4.2)
project(Prata_Study)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Рекурсивно находим все файлы .cpp в проекте
file(GLOB_RECURSE ALL_CPP_FILES "*.cpp")

foreach(source_file ${ALL_CPP_FILES})
    # Получаем путь к папке файла (например, .../Chapter_4/Task_1)
    get_filename_component(dir_path ${source_file} DIRECTORY)
    get_filename_component(task_name ${dir_path} NAME)

    # Получаем путь на один уровень выше, чтобы узнать имя главы (например, "Chapter_4")
    get_filename_component(parent_path ${dir_path} DIRECTORY)
    get_filename_component(chapter_name ${parent_path} NAME)

    # Склеиваем имя главы и задачи в уникальный идентификатор (например: Chapter_4_Task_1)
    set(exe_name "${chapter_name}_${task_name}")

    # Находим все .cpp, .h и .hpp файлы конкретно в этой папке задачи
    file(GLOB SUB_SOURCES "${dir_path}/*.cpp" "${dir_path}/*.h" "${dir_path}/*.hpp")

    # Если такая цель еще не создана, собираем её
    if(NOT TARGET ${exe_name})
        add_executable(${exe_name} ${SUB_SOURCES})
    endif()
endforeach()

# Привязываем все ваши папки к кнопкам запуска в CLion
add_executable(Chapter_2_1 Lessons_cpp/Chapter_2/Listing_2_1/main.cpp)
add_executable(Chapter_2_2 Lessons_cpp/Chapter_2/Listing_2_2/main.cpp)
add_executable(Chapter_2_3 Lessons_cpp/Chapter_2/Listing_2_3/main.cpp)
add_executable(Chapter_2_4 Lessons_cpp/Chapter_2/Listing_2_4/main.cpp)
add_executable(Chapter_2_5 Lessons_cpp/Chapter_2/Listing_2_5/main.cpp)
add_executable(Chapter_2_6 Lessons_cpp/Chapter_2/Listing_2_6/main.cpp)
add_executable(Task_1 Lessons_cpp/Chapter_2/Task_1/main.cpp)
add_executable(Task_2 Lessons_cpp/Chapter_2/Task_2/main.cpp)
add_executable(Listing_4_10 Lessons_cpp/Chapter_4/Listing_4_10/main.cpp)
add_executable(Listing_4_11 Lessons_cpp/Chapter_4/Listing_4_11/main.cpp)
add_executable(Listing_4_12  Lessons_cpp/Chapter_4/Listing_4_12/main.cpp)
add_executable(Listing_4_13 Lessons_cpp/Chapter_4/Listing_4_13/main.cpp)
add_executable(Listing_4_bonus Lessons_cpp/Chapter_4/Listing_4_bonus/main.cpp)
add_executable(Listing_4_14 Lessons_cpp/Chapter_4/Listing_4_14/main.cpp)
add_executable(Listing_4_15 Lessons_cpp/Chapter_4/Listing_4_15/main.cpp)
add_executable(Listing_4_16 Lessons_cpp/Chapter_4/Listing_4_16/main.cpp)
add_executable(Listing_4_17 Lessons_cpp/Chapter_4/Listing_4_17/main.cpp)
add_executable(Listing_4_18 Lessons_cpp/Chapter_4/Listing_4_18/main.cpp)
add_executable(Listing_4_19 Lessons_cpp/Chapter_4/Listing_4_19/main.cpp)
add_executable(Listing_4_20 Lessons_cpp/Chapter_4/Listing_4_20/main.cpp)
add_executable(Listing_4_21 Lessons_cpp/Chapter_4/Listing_4_21/main.cpp)
add_executable(Listing_4_22 Lessons_cpp/Chapter_4/Listing_4_22/main.cpp)
add_executable(Listing_4_23 Lessons_cpp/Chapter_4/Listing_4_23/main.cpp)
add_executable(Listing_4_24 Lessons_cpp/Chapter_4/Listing_4_24/main.cpp)
