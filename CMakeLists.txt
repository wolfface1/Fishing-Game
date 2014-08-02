project(FishingGame)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

set(CMAKE_AUTOMOC = ON)
set(CMAKE_AUTOUIC = ON)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(FishingGame_SRCS main.cpp MainWindow.cpp MainWindow.ui GameLog.cpp LogItem.cpp byteTable.cpp seaWidget.cpp seaWidgetImages.qrc)
qt4_automoc(${FishingGame_SRCS})
add_executable(FishingGame ${FishingGame_SRCS})
target_link_libraries(FishingGame ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
install(TARGETS FishingGame RUNTIME DESTINATION bin)
