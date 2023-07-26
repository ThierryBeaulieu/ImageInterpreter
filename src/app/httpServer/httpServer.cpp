#include "httpServer.h"

constexpr int PORT = 8080;

HttpServer::HttpServer(QObject* parent)
    : QObject(parent)
{
    tcpServer = new QTcpServer(this);
    connect(tcpServer, &QTcpServer::newConnection, this, &HttpServer::onNewConnection);

    if (!tcpServer->listen(QHostAddress::Any, PORT)) {
        qDebug() << "Failed to start server.";
    } else {
        qDebug() << "Server started on port 8080.";
    }
}

void HttpServer::onNewConnection()
{
    QTcpSocket* clientSocket = tcpServer->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &HttpServer::onDataReceived);
}

void HttpServer::onDataReceived()
{
    QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket)
        return;

    handleRequest(clientSocket);
}

void HttpServer::handleRequest(QTcpSocket* clientSocket){
    QByteArray clientRequest = clientSocket->readAll();

    HttpContent content = HttpParser::parse(clientRequest);

    QByteArray response = "";
    if (clientRequest.startsWith("GET / HTTP/1.1")){
        response = "HTTP/1.1 200 OK\r\n"
                            "Content-Type: text/html\r\n"
                            "\r\n"
                            "<html><body><h1>Hello, World!</h1></body></html>";
    } else if (clientRequest.startsWith("GET /sleep HTTP/1.1")){
        response = "HTTP/1.1 200 OK\r\n"
                            "Content-Type: text/html\r\n"
                            "\r\n"
                            "<html><body><h1>Hello sleepy head!</h1></body></html>";
    } else {
        response = "HTTP/1.1 200 OK\r\n"
                            "Content-Type: text/html\r\n"
                            "\r\n"
                            "<html><body><h1>Error 404</h1></body></html>";
    }

    clientSocket->write(response);
    clientSocket->disconnectFromHost();

    qDebug() << clientRequest << Qt::endl;
}


