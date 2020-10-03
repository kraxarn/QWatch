#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	// Custom dark theme
	QFile styleFile(":/res/style/Dark.qss");
	styleFile.open(QIODevice::ReadOnly);
	setStyleSheet(styleFile.readAll());
	styleFile.close();

	// Window properties
	setWindowIcon(Icon::get("logo:app"));
	resize(1280, 720);

	// Media player stuff
	mediaPlayer = new QMediaPlayer(this);
	videoWidget = new QVideoWidget(this);

	// Finish setup
	setCentralWidget(videoWidget);
}
