QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accountinfo.cpp \
    admin.cpp \
    adminmaindialog.cpp \
    aexceptions.cpp \
    attemptquiz.cpp \
    auser.cpp \
    changepassword.cpp \
    clientexception.cpp \
    connmanagerexception.cpp \
    createtestquestions.cpp \
    encryptor.cpp \
    factoryuser.cpp \
    gradesstudent.cpp \
    main.cpp \
    mainwindow.cpp \
    manageusers.cpp \
    onlineaccounts.cpp \
    parser.cpp \
    profesor.cpp \
    profmaindialog.cpp \
    registeruser.cpp \
    serverconnection.cpp \
    student.cpp \
    studentmaindialog.cpp \
    studentquizlist.cpp \
    testdetails.cpp \
    testlist.cpp \
    testresults.cpp

HEADERS += \
    IException.h \
    IUser.h \
    accountinfo.h \
    admin.h \
    adminmaindialog.h \
    aexceptions.h \
    attemptquiz.h \
    auser.h \
    changepassword.h \
    clientexception.h \
    connmanagerexception.h \
    createtestquestions.h \
    encryptor.h \
    factoryuser.h \
    gradesstudent.h \
    mainwindow.h \
    manageusers.h \
    onlineaccounts.h \
    parser.h \
    profesor.h \
    profmaindialog.h \
    registeruser.h \
    serverconnection.h \
    student.h \
    studentmaindialog.h \
    studentquizlist.h \
    testdetails.h \
    testlist.h \
    testresults.h

FORMS += \
    accountinfo.ui \
    adminmaindialog.ui \
    attemptquiz.ui \
    changepassword.ui \
    createtestquestions.ui \
    gradesstudent.ui \
    mainwindow.ui \
    manageusers.ui \
    onlineaccounts.ui \
    profmaindialog.ui \
    registeruser.ui \
    studentmaindialog.ui \
    studentquizlist.ui \
    testdetails.ui \
    testlist.ui \
    testresults.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
