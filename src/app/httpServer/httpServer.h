#ifndef HTTPSERVER
#define HTTPSERVER

#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

#include "../httpParser/httpParser.h"

class HttpServer : public QObject {
    Q_OBJECT
public:
    HttpServer(QObject* parent = nullptr);

private slots:
    void onNewConnection();
    void onDataReceived();
    void handleRequest(QTcpSocket* clientSocket);

private:
    QTcpServer* tcpServer;
};

#endif /* HTTPSERVER */