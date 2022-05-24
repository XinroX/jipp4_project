cmake_minimum_required(VERSION 3.20)
project(PROJEKT)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH = "/Users/mateuszszybicki/Qt/5.15.0/clang_64/")
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5 COMPONENTS Widgets REQUIRED Sql)

include_directories(.)

add_executable(PROJEKT
        addlecturerdialog.cpp
        addlecturerdialog.h
        address.cpp
        address.h
        addstudentdialog.cpp
        addstudentdialog.h
        changedialog.cpp
        changedialog.h
        connector.cpp
        connector.h
        course.cpp
        course.h
        coursedialog.cpp
        coursedialog.h
        dbreader.cpp
        dbreader.h
        dbwriter.cpp
        dbwriter.h
        dialog.cpp
        dialog.h
        employee.cpp
        employee.h
        employeedialog.cpp
        employeedialog.h
        grade.cpp
        grade.h
        lecturer.cpp
        lecturer.h
        loadform.cpp
        loadform.h
        logindialog.cpp
        logindialog.h
        main.cpp
        person.cpp
        person.h
        program.cpp
        program.h
        student.cpp
        student.h
        studentdialog.cpp
        studentdialog.h
        studenttablegenerator.cpp
        studenttablegenerator.h
        subject.cpp
        subject.h
        subjecteditdialog.cpp
        subjecteditdialog.h
        tablewidgetgenerator.cpp
        tablewidgetgenerator.h
        tools.cpp
        tools.h)

target_link_libraries(PROJEKT Qt5::Widgets Qt5::Sql)
