#pragma once

#include <QLayout>
#include <QWidget>
#include <QTime>

class Utils
{
public:
	static QWidget *layoutToWidget(QLayout *layout);
	static QString formatTime(int ms);
};


