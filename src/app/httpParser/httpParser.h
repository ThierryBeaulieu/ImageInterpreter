#ifndef HTTPPARSER
#define HTTPPARSER

#include <QByteArray>

class HttpContent {
private:
    QByteArray body;
    QByteArray header;
};

class HttpParser {
public:
    HttpParser();
    void parse(QByteArray httpRequest, const HttpContent& content);
};

#endif /* HTTPPARSER */