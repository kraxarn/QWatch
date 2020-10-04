#include "font.hpp"

#define REGULAR_FONT "Noto Sans Regular"
#define MONOSPACE_FONT "Noto Sans Mono Regular"

QFont *Font::regularFont = nullptr;
QFont *Font::monospaceFont = nullptr;

QFont &Font::regular()
{
	if (regularFont == nullptr)
		regularFont = new QFont(REGULAR_FONT, QApplication::font().pointSize() * 4);

	return *regularFont;
}

QFont &Font::monospace()
{
	if (monospaceFont == nullptr)
		monospaceFont = new QFont(MONOSPACE_FONT, QApplication::font().pointSize() * 4);

	return *monospaceFont;
}
