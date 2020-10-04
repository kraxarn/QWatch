#include "networkmanager.hpp"

NetworkManager::NetworkManager(QObject *parent)
{
	network = new QNetworkAccessManager(parent);

	cachePath = QStandardPaths::standardLocations(QStandardPaths::CacheLocation)[0];
	QDir(cachePath).mkpath("thumbnails");
}

QByteArray NetworkManager::get(const QString &url)
{
	auto reply = network->get(QNetworkRequest(url.startsWith("http")
		? url
		: QString("%1/%2").arg(API_URL).arg(url)));

	while (!reply->isFinished())
		QCoreApplication::processEvents();

	auto data = reply->readAll();
	reply->deleteLater();
	return data;
}

QJsonDocument NetworkManager::getJson(const QString &url)
{
	return QJsonDocument::fromJson(get(url));
}

QPixmap NetworkManager::getThumbnail(const QString &id)
{
	auto tempFilePath = QString("%1/thumbnails/%2.jpg").arg(cachePath).arg(id);
	QFile tempFile(tempFilePath);
	QByteArray data;

	if (QFileInfo::exists(tempFilePath))
	{
		tempFile.open(QIODevice::ReadOnly);
		data = tempFile.readAll();
	}
	else
	{
		data = get(QString("https://i.ytimg.com/vi/%1/hqdefault.jpg").arg(id));
		tempFile.open(QIODevice::WriteOnly);
		tempFile.write(data);
	}

	tempFile.close();
	return QPixmap(data);
}