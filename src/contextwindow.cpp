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

	setWidget(Utils::layoutToWidget(layout));
}

void ContextWindow::search()
{
	searchBox->setDisabled(true);
	searchResults->setDisabled(true);
	auto json = networkManager->get(QString("yt/search?q=%1").arg(searchBox->text()));

	searchResults->clear();
	QJsonObject obj;
	for (auto item : json.array())
	{
		obj = item.toObject();
		auto listItem = new QTreeWidgetItem(searchResults, {
			"", obj["title"].toString(), "<author>"
		});
	}

	searchBox->setDisabled(false);
	searchResults->setDisabled(false);
}
