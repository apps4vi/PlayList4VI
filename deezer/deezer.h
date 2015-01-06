#ifndef DEEZER_H
#define DEEZER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QList>
#include <QFile>
#include <QUrl>
#include <QAuthenticator>
#include <QSslError>

class Deezer : public QObject
{
    Q_OBJECT
public:
    Deezer(QObject *parent);
    void startRequest(QUrl url);

private:
    QNetworkAccessManager networkAccessManager;
    QNetworkReply *networkReply;
    QFile *file;

private slots:
    void read();
    void finished();
    void manageSslError(QNetworkReply* networkReply, QList<QSslError> sslErrorList);
    void requireAuthentication(QNetworkReply* networkReply, QAuthenticator *authenticator);
};

#endif // DEEZER_H
