#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setWindowIcon(Icon::get("logo:app"));
	resize(1280, 720);

	mediaPlayer = new QMediaPlayer(this);
	videoWidget = new QVideoWidget(this);

	setCentralWidget(videoWidget);
}
