#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	// Custom dark theme
	QFile styleFile(":/res/style/Dark.qss");
	styleFile.open(QIODevice::ReadOnly);
	QApplication::setStyle("fusion");
	setStyleSheet(styleFile.readAll());
	styleFile.close();

	// Custom font
	QFontDatabase::addApplicationFont(":/res/font/NotoSans-Regular.ttf");
	QApplication::setFont(QFont("Noto Sans Regular", QApplication::font().pointSize()));

	// Window properties
	setWindowIcon(Icon::get("logo:app"));
	resize(1280, 720);

	// Media player stuff
	mediaPlayer = new QMediaPlayer(this);
	videoWidget = new QVideoWidget(this);

	// Finish setup
	setCentralWidget(videoWidget);
}
