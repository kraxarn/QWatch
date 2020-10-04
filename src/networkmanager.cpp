#include "networkmanager.hpp"

NetworkManager::NetworkManager(QObject *parent)
{
	network = new QNetworkAccessManager(parent);
}

QJsonDocument NetworkManager::get(const QString &url)
{
	auto reply = network->get(QNetworkRequest(QString("%1/%2").arg(API_URL).arg(url)));

	while (!reply->isFinished())
		QCoreApplication::processEvents();

	auto json = QJsonDocument::fromJson(reply->readAll());
	reply->deleteLater();

	return json;
}
