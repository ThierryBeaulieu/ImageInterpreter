#include "httpParser.h"

HttpParser::HttpParser(){}

void HttpParser::parse(QByteArray httpRequest, const HttpContent& newContent){
    QVector<QByteArray> lines;
    QByteArray currentLine;
    for (auto i = httpRequest.cbegin(), end = httpRequest.cend(); i != end; ++i){
        qDebug() << *i << Qt::endl;
    }
}
