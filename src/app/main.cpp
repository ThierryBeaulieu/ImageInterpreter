#include <QApplication>
#include "mainwindow.h"
#include "httpServer/httpServer.h"

// Run inside build folder :
//
// cmake -DCMAKE_PREFIX_PATH="/Users/thierry/Desktop/qtbase/qt6base-build/" /Users/thierry/Desktop/ImageInterpreter/ 
//

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    HttpServer httpServer;

    return app.exec();
}