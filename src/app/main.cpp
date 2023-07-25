#include <QApplication>
#include "mainwindow.h"

// Run inside build folder :
//
// cmake -DCMAKE_PREFIX_PATH="/Users/thierry/Desktop/qtbase/qt6base-build/" /Users/thierry/Desktop/ImageInterpreter/ 
//

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
