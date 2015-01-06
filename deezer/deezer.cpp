#include "deezer.h"
#include <QDebug>

Deezer::Deezer(QObject *parent) : QObject(parent)
{
    connect(&networkAccessManager, &QNetworkAccessManager::authenticationRequired,
                  this, &Deezer::requireAuthentication);
    connect(&networkAccessManager, &QNetworkAccessManager::sslErrors,
            this, &Deezer::manageSslError);
    file = new QFile();
    if (!file->open(QIODevice::WriteOnly)) {
        qWarning() << tr("Unable to save the file")
                   << ":"
                   << file->errorString();
        delete file;
        file = 0;
    }
    QUrl url("http://qt.nokia.com");
    startRequest(url);
}

void Deezer::startRequest(QUrl url)
{
    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");
    networkReply = networkAccessManager.get(request);
    connect(networkReply, &QNetworkReply::finished,
            this, &Deezer::finished);
    connect(networkReply, &QNetworkReply::readyRead,
            this, &Deezer::read);
}

void startRequest(QUrl url);

void Deezer::read()
{
    // this slot gets called every time the QNetworkReply has new data.
    // We read all of its new data and write it into the file.
    // That way we use less RAM than when reading it at the finished()
    // signal of the QNetworkReply
    if (file)
        file->write(networkReply->readAll());
}

void Deezer::finished()
{
    file->flush();
    file->close();
    QVariant redirectionTarget = networkReply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    if (!redirectionTarget.isNull()) {
        QUrl newUrl = redirectionTarget.toUrl();
        qDebug() << tr("Redirect to")
                 << newUrl.toString();
        file->open(QIODevice::WriteOnly);
        file->resize(0);
        startRequest(newUrl);
    } else {
        if (networkReply->error()) {
            file->remove();
            qWarning() << tr("Download failed :")
                       << networkReply->errorString();
            networkReply->deleteLater();
        }
        networkReply = 0;
        delete file;
        file = 0;
    }
}

void Deezer::manageSslError(QNetworkReply *networkReply, QList<QSslError> sslErrorList)
{

}

void Deezer::requireAuthentication(QNetworkReply *networkReply, QAuthenticator *authenticator)
{

}
