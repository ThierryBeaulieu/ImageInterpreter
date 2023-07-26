#ifndef HTTPPARSER
#define HTTPPARSER

#include <QByteArray>
#include <QVector>
#include <QDebug>
#include <QList>

class HttpContent {
public:
    HttpContent() = default;
    QByteArray body;
    QByteArray header;
};

class HttpParser {
public:
    HttpParser();
    static void parse(QByteArray httpRequest, const HttpContent& httpContent);
    static void handleGet(HttpContent httpContent);
};

#endif /* HTTPPARSER */