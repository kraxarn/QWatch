#pragma once

#include <QFont>
#include <QApplication>
#include <QDebug>

class Font
{
public:
	static QFont &regular();
	static QFont &monospace();

private:
	Font() = default;

	static QFont *regularFont;
	static QFont *monospaceFont;
};


