#include "errordialog.hpp"

ErrorDialog::ErrorDialog(const QString &message, const QString &details, QWidget *parent)
	: QDialog(parent)
{
	auto layout = new QVBoxLayout();
	setLayout(layout);
	setWindowTitle("Error");

	auto msgText = new QLabel(message, this);
	msgText->setWordWrap(true);
	layout->addWidget(msgText);

	auto detailTest = new QTextEdit(details, this);
	detailTest->setReadOnly(true);
	detailTest->setFontFamily("monospace");
	layout->addWidget(detailTest);

	auto buttons = new QDialogButtonBox();
	QPushButton::connect(buttons->addButton(QDialogButtonBox::Ok), &QPushButton::clicked,
		[this](bool checked)
		{
			accept();
		});

	layout->addWidget(buttons);
}
