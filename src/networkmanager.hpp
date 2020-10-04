#pragma once

#include "config.hpp"

#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QCoreApplication>
#include <QPixmap>
#include <QStandardPaths>
#include <QDir>
#include <QJsonObject>
#include <QMessageBox>

class NetworkManager: QNetworkAccessManager
{
public:
	explicit NetworkManager(QObject *parent);

	QJsonDocument getJson(const QString &url);
	QPixmap getThumbnail(const QString &id);

private:
	QByteArray get(const QString &url);

	QNetworkAccessManager *network;
	QString cachePath;
};


