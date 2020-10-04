#pragma once

#include "utils.hpp"
#include "networkmanager.hpp"

#include <QDockWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QListWidget>
#include <QJsonArray>
#include <QJsonObject>
#include <QTreeWidget>

class ContextWindow: public QDockWidget
{
Q_OBJECT

public:
	explicit ContextWindow(QWidget *parent);

private:
	NetworkManager *networkManager;
	QTreeWidget *searchResults;
	QLineEdit *searchBox;

	void search();
};


