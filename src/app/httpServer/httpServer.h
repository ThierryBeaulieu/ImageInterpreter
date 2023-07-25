#ifndef HTTPSERVER
#define HTTPSERVER

#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class HttpServer : public QObject {
    Q_OBJECT
public:
    HttpServer(QObject* parent = nullptr);

private slots:
    void onNewConnection();
    void onDataReceived();

private:
    QTcpServer* tcpServer;
};

#endif /* HTTPSERVER */