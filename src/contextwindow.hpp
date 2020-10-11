#pragma once

#include "utils.hpp"
#include "networkmanager.hpp"
#include "mediainformation.hpp"

#include <QDockWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QListWidget>
#include <QJsonArray>
#include <QJsonObject>
#include <QTreeWidget>
#include <QIcon>
#include <QPixmap>

class ContextWindow: public QDockWidget
{
Q_OBJECT

public:
	explicit ContextWindow(QWidget *parent);

signals:
	void playMedia(const MediaInformation &info);

private:
	NetworkManager *networkManager;
	QTreeWidget *searchResults;
	QLineEdit *searchBox;

	void search();
	void clicked(QTreeWidgetItem *item, int column);
};


