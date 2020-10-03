#pragma once

#include <QDebug>
#include <QIcon>
#include <QString>

class Icon
{
public:
	static QIcon get(const QString &name);

private:
	Icon() = default;
};