#include "utils.hpp"

QWidget *Utils::layoutToWidget(QLayout *layout)
{
	auto widget = new QWidget();
	widget->setLayout(layout);
	return widget;
}

QString Utils::formatTime(int ms)
{
	auto duration = QTime(0, 0).addMSecs(ms);
	return QString("%1:%2")
		.arg(duration.minute(), 2, 10, QChar('0'))
		.arg(duration.second() % 60, 2, 10, QChar('0'));
}