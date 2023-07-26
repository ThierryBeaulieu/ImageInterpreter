#include "httpParser.h"

HttpParser::HttpParser(){}

void HttpParser::parse(QByteArray httpRequest, const HttpContent& newContent){
    if (!httpRequest.contains("Content-Length")){
        qDebug() << "we return because we don't have content-elngth" << Qt::endl;
        return;
    }
    QVector<QByteArray> lines;
    QByteArray currentLine;
    qDebug() << httpRequest << Qt::endl;

    for (auto i = httpRequest.cbegin(), end = httpRequest.cend(); i != end; ++i){

    }
}
