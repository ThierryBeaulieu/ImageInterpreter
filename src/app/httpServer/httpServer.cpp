#include "httpServer.h"

HttpServer::HttpServer(QObject* parent)
    : QObject(parent)
{
    tcpServer = new QTcpServer(this);
    connect(tcpServer, &QTcpServer::newConnection, this, &HttpServer::onNewConnection);

    if (!tcpServer->listen(QHostAddress::Any, 8080)) {
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

    // Read incoming data (HTTP request)
    QByteArray requestData = clientSocket->readAll();

    // Process the HTTP request and generate HTTP response
    // For a simple example, you can respond with a basic HTML page
    QByteArray response = "HTTP/1.1 200 OK\r\n"
                          "Content-Type: text/html\r\n"
                          "\r\n"
                          "<html><body><h1>Hello, World!</h1></body></html>";

    // Send the response back to the client
    clientSocket->write(response);

    // Close the connection after sending the response
    clientSocket->disconnectFromHost();
}