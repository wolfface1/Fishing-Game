project(FishingGame)
cmake_minimum_required(VERSION 2.6)
##find_package(Qt4 REQUIRED)
find_package(Qt4 COMPONENTS QtCore QtGui QtXml REQUIRED )
#find_package(QXml REQUIRED)
##find_package(Automoc4 REQUIRED)

##set(CMAKE_AUTOMOC ON)
##set(CMAKE_AUTOUIC ON)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

set(UIS MainWindow.ui)
set(SRCS StoryMaker.cpp main.cpp MainWindow.cpp GameLog.cpp LogItem.cpp byteTable.cpp seaWidget.cpp)
set(HEADERS MainWindow.h GameLog.h LogItem.h byteTable.h seaWidget.h StoryMaker.h)
set(RESOURCES seaWidgetImages.qrc)

QT4_WRAP_CPP(HEADERS_MOC ${HEADERS})
QT4_WRAP_UI(UIHEADERS ${UIS})
QT4_ADD_RESOURCES(RCCS ${RESOURCES})

##qt4_wrap_ui(UIHEADERS ${UIS})
##qt4_automoc(FishingGame ${FishingGame_SRCS})
##automoc4(FishingGame ${FishingGame_SRCS})

add_executable(FishingGame ${SRCS} ${UIHEADERS} ${HEADERS_MOC} ${RCCS})
target_link_libraries(FishingGame ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTXML_LIBRARY})
install(TARGETS FishingGame RUNTIME DESTINATION bin)