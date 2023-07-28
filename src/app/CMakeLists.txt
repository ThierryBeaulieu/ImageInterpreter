qt_add_executable(imageProc
    mainwindow.ui
    mainwindow.cpp
    main.cpp
)

target_link_libraries(imageProc PRIVATE Qt6::Core)
target_link_libraries(imageProc PRIVATE Qt6::Widgets)
target_link_libraries(imageProc PRIVATE Qt6::Network)
target_link_libraries(imageProc PRIVATE Qt6::HttpServer)

set_target_properties(imageProc PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)