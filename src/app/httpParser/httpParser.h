#ifndef HTTPPARSER
#define HTTPPARSER

#include <QByteArray>
#include <QVector>
#include <QDebug>
#include <QList>

class HttpContent {
public:
    HttpContent(QByteArray header);
    HttpContent(QByteArray header, QByteArray body);
private:
    QByteArray body;
    QByteArray header;
};

class HttpParser {
public:
    HttpParser();
    static HttpContent parse(const QByteArray& httpRequest);
    static void handleGet(const HttpContent& httpContent);
};

#endif /* HTTPPARSER */