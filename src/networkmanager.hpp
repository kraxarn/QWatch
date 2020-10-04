#pragma once

#include "config.hpp"

#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QCoreApplication>

class NetworkManager: QNetworkAccessManager
{
public:
	explicit NetworkManager(QObject *parent);

	QJsonDocument get(const QString &url);

private:
	QNetworkAccessManager *network;
};


