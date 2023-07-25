#ifndef HTTPPARSER
#define HTTPPARSER

#include <QByteArray>

class HttpContent {
public:
    QByteArray body;
    QByteArray header;
};

class HttpParser {
public:
    HttpParser();
    static void parse(QByteArray httpRequest, const HttpContent& content);
};

#endif /* HTTPPARSER */