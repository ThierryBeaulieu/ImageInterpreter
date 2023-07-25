#ifndef HTTPSERVER
#define HTTPSERVER

#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

#include <thread>

class HttpServer : public QObject {
    Q_OBJECT
public:
    HttpServer(QObject* parent = nullptr);

private slots:
    void onNewConnection();
    void onDataReceived();
    void handleRequest(QByteArray clientRequest, QTcpSocket*);

private:
    QTcpServer* tcpServer;
};

class Worker {
public:
    Worker();
private:
    unsigned int id;
    std::thread thread;
};

class ThreadPool {
public: 
    ThreadPool(int poolSize);
private:
    int poolSize;
    std::vector<Worker> pool;
};



#endif /* HTTPSERVER */