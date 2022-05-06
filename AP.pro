QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    db.cpp \
    deaninterface.cpp \
    deanrole.cpp \
    group.cpp \
    grouplist.cpp \
    main.cpp \
    mark.cpp \
    markslist.cpp \
    performancecalc.cpp \
    professorrole.cpp \
    proffinterface.cpp \
    roleslists.cpp \
    stplan.cpp \
    student.cpp \
    studentinterface.cpp \
    studentlist.cpp \
    studentrole.cpp \
    user.cpp \
    widget.cpp

HEADERS += \
    db.h \
    deaninterface.h \
    deanrole.h \
    group.h \
    grouplist.h \
    mark.h \
    markslist.h \
    performancecalc.h \
    professorrole.h \
    proffinterface.h \
    roleslists.h \
    stplan.h \
    student.h \
    studentinterface.h \
    studentlist.h \
    studentrole.h \
    user.h \
    widget.h

FORMS += \
    deaninterface.ui \
    proffinterface.ui \
    studentinterface.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
