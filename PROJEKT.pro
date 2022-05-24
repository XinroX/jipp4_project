QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addlecturerdialog.cpp \
    address.cpp \
    addstudentdialog.cpp \
    changedialog.cpp \
    connector.cpp \
    course.cpp \
    coursedialog.cpp \
    dbreader.cpp \
    dbwriter.cpp \
    employee.cpp \
    employeedialog.cpp \
    grade.cpp \
    lecturer.cpp \
    loadform.cpp \
    logindialog.cpp \
    main.cpp \
    person.cpp \
    program.cpp \
    student.cpp \
    studentdialog.cpp \
    studenttablegenerator.cpp \
    subject.cpp \
    subjecteditdialog.cpp \
    tablewidgetgenerator.cpp \
    tools.cpp

HEADERS += \
    addlecturerdialog.h \
    address.h \
    addstudentdialog.h \
    changedialog.h \
    connector.h \
    course.h \
    coursedialog.h \
    dbreader.h \
    dbwriter.h \
    employee.h \
    employeedialog.h \
    grade.h \
    lecturer.h \
    loadform.h \
    logindialog.h \
    person.h \
    program.h \
    student.h \
    studentdialog.h \
    studenttablegenerator.h \
    subject.h \
    subjecteditdialog.h \
    tablewidgetgenerator.h \
    tools.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    addlecturerdialog.ui \
    addstudentdialog.ui \
    changedialog.ui \
    coursedialog.ui \
    employeedialog.ui \
    loadform.ui \
    logindialog.ui \
    studentdialog.ui \
    subjecteditdialog.ui
