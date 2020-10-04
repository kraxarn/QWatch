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
	QFontDatabase::addApplicationFont(":/res/font/NotoSansMono-Regular.ttf");

	// Window properties
	setWindowIcon(Icon::get("logo:app"));
	resize(1280, 720);

	// Media player stuff
	mediaPlayer = new QMediaPlayer(this);
	videoWidget = new QVideoWidget(this);

	// Footer
	footer = new Footer(this);
	addToolBar(Qt::BottomToolBarArea, footer);

	// Sidebar
	addDockWidget(Qt::RightDockWidgetArea, new ContextWindow(this));

	// Finish setup
	setCentralWidget(videoWidget);
}
