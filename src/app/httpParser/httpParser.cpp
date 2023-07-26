#include "httpParser.h"

HttpParser::HttpParser(){}

void HttpParser::parse(QByteArray httpRequest, const HttpContent& httpContent){
    int delimiterIndex = httpRequest.indexOf("\r\n\r\n");

    if (delimiterIndex != -1) {
        const QByteArray part1 = httpRequest.left(delimiterIndex);
        const QByteArray part2 = httpRequest.mid(delimiterIndex + 4);

    } else {
    }
}

void HttpParser::handleGet(HttpContent httpContent) { 

}
