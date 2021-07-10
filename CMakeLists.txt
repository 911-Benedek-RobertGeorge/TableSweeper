cmake_minimum_required(VERSION 3.19)
project(e3_911_Benedek_RobertGeorge)

set(CMAKE_CXX_STANDARD 14)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets )
set(REQUIRED_LIBS_QUALIFIED Qt5::Core  Qt5::Gui Qt5::Widgets)
set(CMAKE_CXX_STANDARD 14)

include_directories(Domain)

add_executable(e3_911_Benedek_RobertGeorge

        main.cpp
        Repository/Repo.cpp
        Repository/Repo.h
        GUI/Window.cpp
        GUI/Window.h
        )



if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})