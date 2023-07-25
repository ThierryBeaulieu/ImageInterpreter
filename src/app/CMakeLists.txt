qt_add_executable(imageProc
    mainwindow.ui
    mainwindow.cpp
    bmpWnd/bmpWnd.cpp
    main.cpp
)

target_link_libraries(imageProc PRIVATE Qt6::Widgets)
target_link_libraries(imageProc PRIVATE Qt6::Network)

set_target_properties(imageProc PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)