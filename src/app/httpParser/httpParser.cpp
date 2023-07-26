#include "httpParser.h"


HttpContent::HttpContent(QByteArray header){
}
HttpContent::HttpContent(QByteArray header, QByteArray body){

}

HttpParser::HttpParser(){}

HttpContent HttpParser::parse(const QByteArray& httpRequest) {
    int delimiterIndex = httpRequest.indexOf("\r\n\r\n");

    if (delimiterIndex != -1) {
        QByteArray part1 = httpRequest.left(delimiterIndex);
        QByteArray part2 = httpRequest.mid(delimiterIndex + 4);
        HttpContent httpcontent(part1, part2);
        return httpcontent;
    } else {
        HttpContent httpcontent(httpRequest);
        return httpcontent;
    }
}

void HttpParser::handleGet(const HttpContent& httpContent) { 

}
