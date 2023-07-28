#include <QApplication>
#include "mainwindow.h"
#include "httpServer/httpServer.h"
#include <QHttpServer>
#include <Qdebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QHttpServer httpServer;
    httpServer.route("/", []() {
        return "Hello world";
    });

    const auto port = httpServer.listen(QHostAddress::Any);
    if (!port) {
        qWarning() << QCoreApplication::translate("QHttpServerExample",
                                                  "Server failed to listen on a port.");
        return -1;
    }
}