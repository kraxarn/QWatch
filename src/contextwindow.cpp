#include "contextwindow.hpp"

ContextWindow::ContextWindow(QWidget *parent)
	: QDockWidget(parent)
{
	networkManager = new NetworkManager(this);

	auto layout = new QVBoxLayout();

	searchBox = new QLineEdit(this);
	layout->addWidget(searchBox);

	QLineEdit::connect(searchBox, &QLineEdit::returnPressed, this, &ContextWindow::search);

	searchResults = new QTreeWidget(this);
	searchResults->setHeaderLabels({
		"", "Title", "Author"
	});
	layout->addWidget(searchResults, 1);

	QTreeWidget::connect(searchResults, &QTreeWidget::itemDoubleClicked, this, &ContextWindow::clicked);

	setWidget(Utils::layoutToWidget(layout));
}

void ContextWindow::search()
{
	searchBox->setDisabled(true);
	searchResults->setDisabled(true);
	auto json = networkManager->getJson(QUrl(QString("yt/search?q=%1").arg(searchBox->text())).toEncoded());

	searchResults->clear();
	QJsonObject obj;
	for (auto item : json.array())
	{
		obj = item.toObject();
		auto treeItem = new QTreeWidgetItem(searchResults, {
			"", obj["title"].toString(), obj["author"].toString()
		});
		treeItem->setIcon(0,
			QIcon(networkManager->getThumbnail(obj["id"].toString())));
		treeItem->setData(0, 0x100, obj["id"].toString());
	}

	searchBox->setDisabled(false);
	searchResults->setDisabled(false);
}

void ContextWindow::clicked(QTreeWidgetItem *item, int)
{
	auto json = networkManager->getJson(QString("yt/info/%1")
		.arg(item->data(0, 0x100).toString())).object();

	auto videoUrl = json["video"].toObject()["url"].toString();
	auto audioUrl = json["audio"].toObject()["url"].toString();

	emit playMedia(videoUrl, audioUrl);
}